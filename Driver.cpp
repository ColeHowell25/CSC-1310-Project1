/****************************************************
 *  TITLE:   Driver.cpp                             *
 *  AUTHOR:  April R Crockett                       *
 *  DATE:    January 16, 2019                       *
 *  PURPOSE: Fun Park Business Program              *
 ****************************************************/

#include <iostream>
#include "Text.h"
#include "Business.h"
#include "Game.h"
#include "RentItem.h"
using namespace std;

int main()
{
	int choice, maxGames, maxItems;
	char businessName[100];
	cout << "\n\nWhat is the name of your game business?\n";
	cin.getline(businessName, 100);
	
	cout << "\nWhat is the maximum number of games your business can hold?\n";
	cin >> maxGames;
	
	cout << "\nWhat is the maximum number of rental items your business can have?\n";
	cin >> maxItems;
	
	//create a new business
	Text* name = new Text(businessName);
	Business* myBusiness = new Business(name, maxGames, maxItems);
	
	do
	{
	
		cout << "\n\nWhat do you wish to do?\n";
		cout << "\t1.\tAdd Games From a File\n";
		cout << "\t2.\tAdd Rental Items From a File\n";
		cout << "\t3.\tAssociate Rental Items with Games\n";
		cout << "\t4.\tAdd One Game\n";
		cout << "\t5.\tEdit One Game\n";
		cout << "\t6.\tRemove One Game\n";
		cout << "\t7.\tAdd One Rental Item\n";
		cout << "\t8.\tEdit One Rental Item\n";
		cout << "\t9.\tRemove One Rental Item\n";
		cout << "\t10.\tPrint All Games\n";
		cout << "\t11.\tPrint All Rent Items\n";
		cout << "\t12.\tSave All Data\n";
		cout << "\t13.\tQuit the Program\n";
		cout << "CHOOSE 1-13:  ";
		cin >> choice;
		
		while(choice < 1 || choice > 13)
		{
			cout << "\nOops!  That was an invalid choice.\n";
			cout << "CHOOSE 1-12:  ";
			cin >> choice;
		}

		switch(choice)
		{
			case 1:	//add games from a file
					myBusiness->addGamesFromFile();
					break;
			case 2: //add rental items from a file
					myBusiness->addItemsFromFile();
					break;
			case 3: //associate rental items with games
					myBusiness->addGameToItem();
					break;
			case 4:	//add one game
					myBusiness->addGameToArray();
					break;
			case 5: //edit one game
					myBusiness->editGameInArray();
					break;
			case 6:	//remove one game
					myBusiness->removeGameFromArray();
					break;
			case 7:	//add one rental item
					myBusiness->addRentItemToArray();
					break;
			case 8:	//edit one rental item
					myBusiness->editRentItemInArray();
					break;
			case 9:	//remove one rental item
					myBusiness->removeRentItemFromArray();
					break;
			case 10://print all games
					myBusiness->printGames();
					break;
			case 11://print all rent items
					myBusiness->printRentItems();
					break;
			case 12://save all data
					myBusiness->saveData();
					break;
			case 13://quit the program
					cout << "\n\nGoodbye!\n\n";
			
		}
	}while(choice != 13);

	//release dynamically allocated memeory
	delete myBusiness;
	delete name;
	
	return 0;
}