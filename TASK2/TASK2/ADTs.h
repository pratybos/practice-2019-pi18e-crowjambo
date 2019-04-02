#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*front, *rear, *temp, *front1;


int count = 0;


/* Create an empty queue */
static void create()
{
	front = rear = NULL;
}

/* Returns queue size */
static void queuesize()
{
	printf("\n Queue size : %d", count);
}

/* Enqueing the queue */
static void enq(int data)
{
	if (rear == NULL)
	{
		rear = (struct node *)malloc(1 * sizeof(struct node));
		rear->next = NULL;
		rear->data = data;
		front = rear;
	}
	else
	{
		temp = (struct node *)malloc(1 * sizeof(struct node));
		rear->next = temp;
		temp->data = data;
		temp->next = NULL;

		rear = temp;
	}
	count++;
}


/* Displaying the queue elements */
static void display()
{
	front1 = front;

	if ((front1 == NULL) && (rear == NULL))
	{
		printf("Queue is empty");
		return;
	}
	while (front1 != rear)
	{
		printf("%d ", front1->data);
		front1 = front1->next;
	}
	if (front1 == rear)
		printf("%d", front1->data);
}

/* Dequeing the queue */
static void deq()
{
	front1 = front;

	if (front1 == NULL)
	{
		printf("\n Error: Trying to display elements from empty queue");
		return;
	}
	else
		if (front1->next != NULL)
		{
			front1 = front1->next;
			printf("\n Dequed value : %d", front->data);
			free(front);
			front = front1;
		}
		else
		{
			printf("\n Dequed value : %d", front->data);
			free(front);
			front = NULL;
			rear = NULL;
		}
	count--;
}

/* Returns the front element of queue */
static int frontelement()
{
	if ((front != NULL) && (rear != NULL))
		return(front->data);
	else
		return 0;
}

/* Display if queue is empty or not */
static void empty()
{
	if ((front == NULL) && (rear == NULL))
		printf("\n Queue empty");
	else
		printf("Queue not empty");
}