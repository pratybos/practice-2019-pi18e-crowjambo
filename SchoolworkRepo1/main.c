#include <stdlib.h>
#include <stdio.h>
#include "functionRefs.h"

enum hunger {
	low = 0,
	high = 1,
};

// the main function where all of the algorhithms will get called from
int main() {

	//armstrong function
	//ArmstrongFunction();

	//Task 1 - Real life algorhithm.
	//RealLifeAlgo(low);
	



	printf("\n");
	system("pause");
	return 0;
}
//example
/*

#include <iostream>
#include <ctime>
#include "functionRefs.h"

using namespace std;

bool fireplace = false;
bool shelter = false;

struct Backpack {

	int matchsticks;
	int logs;
	float l_of_water;
	float kg_of_meat;

	bool tent;
	bool shovel;
	bool hatchet;

};

class Adventurer
{
public:
	Backpack backpack;

	int hunger;
	int thirst;
	int sleep;

	bool alive = true;

	void INFO()
	{
		system("cls");
		cout << "*********SURVIVOR************\n";
		cout << "Hunger: " << hunger << "%\n";
		cout << "Thirst: " << thirst << "%\n";
		cout << "Sleep: " << sleep << "%\n";
		cout << "*********BACKPACK************\n";
		cout << "KG_Meat: " << backpack.kg_of_meat << "KG\n";
		cout << "L_Water: " << backpack.l_of_water << "L\n";
		cout << "Matchsticks: " << backpack.matchsticks << "\n";
		cout << "Logs: " << backpack.logs << "\n\n";

		cout << "Tent: " << backpack.tent << "\n";
		cout << "Shovel: " << backpack.shovel << "\n";
		cout << "Hatchet: " << backpack.hatchet << "\n";
		cout << "*****************************\n";
	}

	void MakeFireplace()
	{
		if (backpack.matchsticks >= 5 && backpack.logs > 5 && fireplace == false)
		{
			sleep -= 20;
			hunger -= 10;
			thirst -= 15;

			backpack.matchsticks -= 5;
			backpack.logs -= 5;
			fireplace = true;

			cout << "Fireplace made!\n";
		}
		else if (backpack.matchsticks < 5 && backpack.logs > 5 && fireplace == false) {
			sleep -= 30;
			hunger -= 20;
			thirst -= 15;

			backpack.logs -= 5;
			fireplace = true;
			cout << "You didn't have enough matchsticks, that took some effort...\n";
		}
		else if (backpack.logs < 5) cout << "You don't have enough lumber, go chop some\n";
		else cout << "You already have a fireplace...\n";

		cin.ignore();
	}

	void MakeShelter()
	{
		if (backpack.tent && sleep > 10)
		{
			sleep -= 10;
			cout << "You established your tent, sleep won't harm that much";
			backpack.tent = 0;
		}
		else if (sleep > 30)
		{
			sleep -= 30;
			cout << "You made a shelter from sticks and leaves, that took some effort...\n";
		}
		else cout << "You don't have enough energy...";
	}

	void CookAndEat()
	{
		if (fireplace == true && backpack.kg_of_meat > 0.5 && sleep > 5)
		{
			sleep -= 5;
			hunger += 25;
			thirst += 5;

			backpack.kg_of_meat -= 0.5;

			cout << "That was some delicious meat!\n";
		}
		else if (backpack.kg_of_meat < 0.5) cout << "You don't have enough meat, you should go hunting\n";
		else if (sleep < 5) cout << "Not enough energy, you need to go sleep\n";
		else cout << "You have to make a fireplace first\n";
	}

	void DrinkWater()
	{
		if (backpack.l_of_water > 0.5)
		{
			thirst += 25;

			backpack.l_of_water -= 0.5;

			cout << "Fresh water tastes good\n";
		}
		else cout << "You don't have a drop of water, go get some!\n";
	}

	void GatherWater()
	{

		if (sleep > 20) {
			sleep -= 20;

			backpack.l_of_water += 2;

			cout << "You've gathered some fresh spring water\n";
		}
		else cout << "Not enough energy, you need to go sleep\n";
	}

	void GoHunting()
	{
		if (sleep > 20) {
			sleep -= 20;

			backpack.kg_of_meat += 1;
			cout << "Hunting went successfully\n";
		}
		else cout << "Not enough energy, you need to go sleep\n";
	}

	void ChopWood()
	{
		if (sleep > 20 && backpack.hatchet)
		{
			sleep -= 10;
			backpack.logs += 5;
			cout << "You've gathered some logs!\n";
		}
		else if (sleep > 20) {
			sleep -= 30;
			backpack.logs += 5;
			cout << "You've gathered some logs but you didn't have Hatchet, you got tired.\n";
		}
		else cout << "Not enough energy, you need to go sleep\n";
	}

	void GoSleep(bool & COMPLETE)
	{
		COMPLETE = true;

		if (shelter && (hunger < 30 || thirst < 30)) alive = false;
		else if (hunger < 50 || thirst < 50) alive = false;
		else alive = true;
	}

} Person;


void Menu()
{
	cout << "--------Pick an action------\n";
	cout << "1. Cook and Eat something\n";
	cout << "2. Drink some water\n";
	cout << "3. Go hunting\n";
	cout << "4. Get some water from spring\n";
	cout << "5. Chop some wood\n";
	cout << "6. Make a fireplace\n";
	cout << "7. Make a shelter\n";
	cout << "0. Go to sleep\n";
	cout << "----------------------------\n";
	cout << "Option: ";
}

int ExampleAlgo()
{
	srand(time(NULL));

	bool COMPLETE = false;



	cout << "---------------------------------------------------------\n";
	cout << "Your goal is to live through the night.\n";
	cout << "To do so, you have to go to sleep\n";
	cout << "Going to sleep will reduce all of your life meters by 50%\n";
	cout << "You can do various things to help you live through the night.\n";
	cout << "                      GOOD LUCK!.\n";
	cout << "---------------------------------------------------------\n\n";

	cout << "First, we need to specify, what do we have:\n"
		"How much matchsticks do you have : "; cin >> Person.backpack.matchsticks;
	cout << "How many logs do you have : "; cin >> Person.backpack.logs;
	cout << "How many liters of water do you have : "; cin >> Person.backpack.l_of_water;
	cout << "How many kilo of meat do you have : "; cin >> Person.backpack.kg_of_meat;
	cout << "Do you have a tent? [1/0] : "; cin >> Person.backpack.tent;
	cout << "Do you have a shovel? [1/0] : "; cin >> Person.backpack.shovel;
	cout << "Do you have a hatchet? [1/0] : "; cin >> Person.backpack.hatchet;

	Person.hunger = rand() % 20 + 30;
	Person.thirst = rand() % 20 + 30;
	Person.sleep = rand() % 20 + 80;



	while (!COMPLETE) {
		Person.INFO();
		Menu();

		int opt; cin >> opt;
		switch (opt)
		{
		case 1:
			Person.CookAndEat();
			break;
		case 2:
			Person.DrinkWater();
			break;
		case 3:
			Person.GoHunting();
			break;
		case 4:
			Person.GatherWater();
			break;
		case 5:
			Person.ChopWood();
			break;
		case 6:
			Person.MakeFireplace();
			break;
		case 7:
			Person.MakeShelter();
			break;
		case 0:
			Person.GoSleep(COMPLETE);
			break;
		default:
			cout << "Invalid option.\n";
			break;
		}
		system("pause");
	}


	system("cls");
	Person.INFO();

	if (Person.alive)
	{
		cout << "CONGRATULATIONS, you've managed to survive!\n";
		cout << "         Thank you for playing.\n";
	}
	else
	{
		cout << "Unfortunately, You did not make it through the night\n";
		cout << "             Thank you for playing.\n";
	}

	system("pause");
	return 0;
}

*/