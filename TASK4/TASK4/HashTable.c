#include "HashTable.h"



//numbers bigger than alphabet (128, to vary hashing a bit)
#define HT_PRIME_1 151
#define HT_PRIME_2 163
//base size of hash table
#define HT_INITIAL_BASE_SIZE 300

#pragma region Main INIT/CREATE/DELETE functions

//allocates a chunk of memory the size of an ht_item
static ht_item* ht_new_item(const char* k, list_node* v) {
	ht_item* i = malloc(sizeof(ht_item));
	i->key = _strdup(k);
	i->value = v;
	return i;
}

//creating hash tables of a certain size
static ht_hash_table* ht_new_sized(const int base_size) {
	ht_hash_table* ht = malloc(sizeof(ht_hash_table));
	ht->base_size = base_size;

	ht->size = next_prime(ht->base_size);

	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
	return ht;
}

//initialises a new hash table. size defines how many items we can store
ht_hash_table* ht_new() {
	return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

//delete singular item
static void ht_del_item(ht_item* i) {
	free(i->key);
	free(i->value);
	free(i);
}

//delete whole table and its items
void ht_del_hash_table(ht_hash_table* ht) {
	for (int i = 0; i < ht->size; i++) {
		ht_item* item = ht->items[i];
		if (item != NULL) {
			ht_del_item(item);
		}
	}
	free(ht->items);
	free(ht);
}

#pragma endregion
#pragma region Hashing

//Convert the string to a large integer
//Reduce the size of the integer to a fixed range by taking its remainder mod m
//the variable a should be a prime number larger than the size of the alphabet.
static int ht_hash(const char* s, const int a, const int m) {
	long hash = 0;
	const int len_s = strlen(s);
	for (int i = 0; i < len_s; i++) {
		//hash += (long)pow(a, len_s - (i + 1)) * s[i];
		//hash = hash % m;
		hash += (int)s[i];
	}
	hash = hash % m;
	return (int)hash;
}

#pragma endregion
#pragma region Collisions handling

static int ht_get_hash(
	const char* s, const int num_buckets, const int attempt
) {
	const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
	const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
	return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

#pragma endregion
#pragma region Methods

//simplify resizing with these functions
static void ht_resize_up(ht_hash_table* ht);
static void ht_resize_down(ht_hash_table* ht);

//instead of deleting the item, we simply mark it as deleted
static ht_item HT_DELETED_ITEM = { NULL, NULL };


// iterate through indexes until find an empty bucket then insert the item into that bucket and increment the hash tables count attribute, to indicate a new item has been added
//When inserting, if we hit a deleted node, we can insert the new node into the deleted slot.
void ht_insert(ht_hash_table* ht, const char* key, list_node* value) {
	//resize if load is more than 0.7 of hashtable
	const int load = ht->count * 100 / ht->size;
	if (load > 70) {
		ht_resize_up(ht);
	}
	ht_item* item = ht_new_item(key, value);
	int index = ht_get_hash(item->key, ht->size, 0);
	ht_item* cur_item = ht->items[index];
	int i = 1;
	while (cur_item != NULL) {
		if (cur_item != &HT_DELETED_ITEM) {
			if (strcmp(cur_item->key, key) == 0) {

			/*	list_node* custom_ht_search(ht_hash_table* ht, const char *searchValue) {
					char temp[2] = { searchValue[0] };
					const char* otherTemp = temp;
					return ht_search(ht, otherTemp);
				}*/

				//IF Already exists, return previously existing node in same hash bucket
				//assign previous nodes address to new ones NEXT
				item->value->next = custom_ht_search(ht, key);
				
				//PREVIOUSLY USED, but dont use it with linked list or memory gets corrupted!
				//delete the previous item and insert the new item at its location (UPDATE FUNCTION)
				//ht_del_item(cur_item);

				//sets new item as first one in order
				ht->items[index] = item;
				ht->count++;
				return;
			}
		}
		index = ht_get_hash(item->key, ht->size, i);
		cur_item = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}

//at each iteration of the while loop check whether the items key matches the key we are searching for. If it does, we return the item's value. If the while loop hits a NULL bucket, we return NULL, to indicate that no value was found.
//When searching, we ignore and 'jump over' deleted nodes
list_node* ht_search(ht_hash_table* ht, const char* key) {
	int index = ht_get_hash(key, ht->size, 0);
	ht_item* item = ht->items[index];
	int i = 1;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM) {
			if (strcmp(item->key, key) == 0) {
				return item->value;
			}
		}
		index = ht_get_hash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	return NULL;
}


// Removing it from the table will break that chain, and will make finding items in the tail of the chain impossible. To solve this, instead of deleting the item, we simply mark it as deleted.
void ht_delete(ht_hash_table* ht, const char* key) {
	//resize if load is smaller than 0.1 of hash table
	const int load = ht->count * 100 / ht->size;
	if (load < 10) {
		ht_resize_down(ht);
	}
	int index = ht_get_hash(key, ht->size, 0);
	ht_item* item = ht->items[index];
	int i = 1;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM) {
			if (strcmp(item->key, key) == 0) {

				ht_del_item(item);
				ht->items[index] = &HT_DELETED_ITEM;
			}
		}
		index = ht_get_hash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	ht->count--;
}

//check to make sure we're not attempting to reduce the size of the hash table below its minimum. We then initialise a new hash table with the desired size. All non NULL or deleted items are inserted into the new hash table. We then swap the attributes of the new and old hash tables before deleting the old
static void ht_resize(ht_hash_table* ht, const int base_size) {
	if (base_size < HT_INITIAL_BASE_SIZE) {
		return;
	}
	ht_hash_table* new_ht = ht_new_sized(base_size);
	for (int i = 0; i < ht->size; i++) {
		ht_item* item = ht->items[i];
		if (item != NULL && item != &HT_DELETED_ITEM) {
			ht_insert(new_ht, item->key, item->value);
		}
	}

	ht->base_size = new_ht->base_size;
	ht->count = new_ht->count;

	// To delete new_ht, we give it ht's size and items 
	const int tmp_size = ht->size;
	ht->size = new_ht->size;
	new_ht->size = tmp_size;

	ht_item** tmp_items = ht->items;
	ht->items = new_ht->items;
	new_ht->items = tmp_items;

	ht_del_hash_table(new_ht);
}
//simplify resizing with these functions
static void ht_resize_up(ht_hash_table* ht) {
	const int new_size = ht->base_size * 2;
	ht_resize(ht, new_size);
}
//simplify resizing with these functions
static void ht_resize_down(ht_hash_table* ht) {
	const int new_size = ht->base_size / 2;
	ht_resize(ht, new_size);
}



#pragma endregion
#pragma region Testing

//void ht_insert(ht_hash_table* ht, const char* key, list_node* value)
void custom_ht_insert(ht_hash_table* ht ,char *name, char *lastName, int age, char *groupName) {

	Student temp;
	temp.age = age;
	strcpy_s(temp.name, 20, name);
	strcpy_s(temp.lastName, 20, lastName);
	strcpy_s(temp.groupName, 10, groupName);

	list_node *node = createNewListNode(temp);

	//convert to cont char* first letter of last name
	char temp2[2] = { lastName[0] };
	const char* otherTemp = temp2;

	ht_insert(ht, temp2, node);
}

//Make sure all searches are made to search with first letter only!
list_node* custom_ht_search(ht_hash_table* ht, const char *searchValue) {
	char temp[2] = { searchValue[0] };
	const char* otherTemp = temp;
	return ht_search(ht, otherTemp);
}

#pragma endregion




