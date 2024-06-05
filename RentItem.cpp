/****************************************************
 *  TITLE:   RentItem.cpp                           *
 *  AUTHOR:  April R Crockett                       *
 *  DATE:    January 16, 2019                       *
 *  PURPOSE: class implementation of RentItem class *
 ****************************************************/

#include <iostream>
#include <iomanip>
#include "RentItem.h"

using namespace std;

	
RentItem::RentItem(Text* name, Text* desc, float cost, int s, float h)
{
	gameAssociation = NULL;
	itemName = new Text(name->getText());
	itemDescription = new Text(desc->getText());
	itemCost = cost;
	howManyInStock = s;
	rentDurationInHours = h;
}

RentItem::RentItem(Game* g, Text* name, Text* desc, float cost, int s, float h)
{
	gameAssociation = g;
	itemName = new Text(name->getText());
	itemDescription = new Text(desc->getText());
	itemCost = cost;
	howManyInStock = s;
	rentDurationInHours = h;
}

RentItem::~RentItem()
{
	cout << "\nRentItem Destructor:  RELEASING MEMORY FOR itemName & itemDescription.\n";
	delete itemName;
	delete itemDescription;
}



void RentItem::printRentItemDetails()
{
	cout << setprecision(2) << fixed;
	
	cout << "\n\tGAME ASSOCIATION: \t";
	if(gameAssociation != NULL)
		gameAssociation->getGameName()->displayText();
	else
		cout << "NONE";
	cout << "\n\tITEM NAME: \t";
	itemName->displayText();
	cout << "\n\tDESCRIPTION: \t";
	itemDescription->displayText();
	if(itemCost == 0)
		cout << "\n\tCOST: \tFREE!!\n";
	else
		cout << "\n\tCOST: \t" << itemCost << endl;
	cout << "\tHOW MANY IN STOCK: \t" << howManyInStock << endl;
	cout << "\tRENT DURATION IN HOURS: \t" << rentDurationInHours << endl << endl;
}



void RentItem::printRentItemName()
{
	itemName->displayText();
}



void RentItem::editRentItemDetails()
{
	int choice;
	char temp[1000];
	
	do
	{
		cout << "\n\nWhat would you like to edit?\n";
		cout << "\t1.\tName\n";
		cout << "\t2.\tDescription\n";
		cout << "\t3.\tCost\n";
		cout << "\t4.\tHow Many In Stock\n";
		cout << "\t5.\tRent Duration In Hours\n";
		cout << "\t6.\tDONE EDITING\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\n\nInvalid choice.  You must select a number between 1 and 6.\n";
			cout << "CHOOSE 1-6:  ";
			cin >> choice;
		}
		cin.ignore();
		switch(choice)
		{
			case 1:
				cout << "\nCurrent Name:  ";
				itemName->displayText();
				cout << "\nNew Name:  ";
				cin.getline(temp, 1000);
				itemName->editText(temp);
				break;
			case 2:
				cout << "\nCurrent Description:  \n";
				itemDescription->displayText();
				cout << "\nNew Description:  \n";
				cin.getline(temp, 1000);
				itemDescription->editText(temp);
				break;
			case 3:
				cout << "\nCurrent Cost:  " << itemCost;
				cout << "\nNew Cost:  ";
				cin >> itemCost;
				break;
			case 4:
				cout << "\nCurrent Number in Stock:  " << howManyInStock;
				cout <<"\nNew Number in Stock:  ";
				cin >> howManyInStock;
				break;
			case 5:
				cout << "\nCurrent Rent Duration in Hours:  " << rentDurationInHours;
				cout << "\nNew Rent Duration in Hours:  ";
				cin >> rentDurationInHours;
				break;		
		}
	}while(choice != 6);
}		

Game* RentItem::getGameAssociation() const
{
	return gameAssociation;
}
Text* RentItem::getItemName() const
{
	return itemName;
}
Text* RentItem::getItemDescription() const
{
	return itemDescription;
}
float RentItem::getItemCost() const
{
	return itemCost;
}
int RentItem::getHowManyInStock() const
{
	return howManyInStock;
}
float RentItem::getRentDurationInHours() const
{
	return rentDurationInHours;
}

void RentItem::setGameAssociation(Game* g)
{
	gameAssociation = g;
}