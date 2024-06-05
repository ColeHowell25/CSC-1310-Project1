/****************************************************
 *  TITLE:   Game.cpp                               *
 *  AUTHOR:  April R Crockett                       *
 *  DATE:    January 16, 2019                       *
 *  PURPOSE: class implementation of Game class     *
 ****************************************************/
 
#include <iostream>
#include <iomanip>
#include "Game.h"

using namespace std;

Game::Game(Text* n, Text* d, float c, int p, int m, float h)
{
	gameName = n;
	gameDescription = d;
	gameCost = c;
	numPlayers = p;
	maxOccupancy = m;
	gameDurationInHours = h;
}
		
Game::~Game()
{
	cout << "\nGame Destructor:  RELEASING MEMEORY FOR gameName & gameDescription.\n";
	delete gameName;
	delete gameDescription;
}

void Game::printGameDetails()
{
	cout << setprecision(2) << fixed;
	
	cout << "\tNAME: \t";
	gameName->displayText();
	cout << "\n\tDESCRIPTION: \t";
	gameDescription->displayText();
	if(gameCost == 0)
		cout << "\n\tCOST: \t FREE!!\n";
	else
		cout << "\n\tCOST: \t" << gameCost << endl;
	if(numPlayers == 0)
		cout << "\tNUMBER OF PLAYERS: \t Not Applicable\n";
	else
		cout << "\tNUMBER OF PLAYERS: \t" << numPlayers << endl;
	if(maxOccupancy == 0)
		cout << "\tMAXIMUM OCCUPANCY: \t Not Applicable\n";
	else
		cout << "\tMAXIMUM OCCUPANCY: \t" << maxOccupancy << endl;
	if(gameDurationInHours < 1)
		cout << "\tGAME DURATION: \t Not Applicable\n\n";
	else
		cout << "\tGAME DURATION: \t" << gameDurationInHours << endl << endl;
	
}

void Game::printGameName()
{
	gameName->displayText();
}

void Game::editGameDetails()
{
	int choice;
	char temp[1000];
	
	do
	{
		cout << "\n\nWhat would you like to edit?\n";
		cout << "\t1.\tName\n";
		cout << "\t2.\tDescription\n";
		cout << "\t3.\tCost\n";
		cout << "\t4.\tNumber of Players\n";
		cout << "\t5.\tMaximum Occupancy\n";
		cout << "\t6.\tGame Duration\n";
		cout << "\t7.\tDONE EDITING\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 7)
		{
			cout << "\n\nInvalid choice.  You must select a number between 1 and 7.\n";
			cout << "CHOOSE 1-7:  ";
			cin >> choice;
		}
		cin.ignore();
		switch(choice)
		{
			case 1:
				cout << "\nCurrent Name:  ";
				gameName->displayText();
				cout << "\nNew Name:  ";
				cin.getline(temp, 1000);
				gameName->editText(temp);
				break;
			case 2:
				cout << "\nCurrent Description:  \n";
				gameDescription->displayText();
				cout << "\nNew Description:  \n";
				cin.getline(temp, 1000);
				gameDescription->editText(temp);
				break;
			case 3:
				cout << "\nCurrent Cost:  " << gameCost;
				cout << "\nNew Cost:  ";
				cin >> gameCost;
				break;
			case 4:
				cout << "\nCurrent Number of Players:  " << numPlayers;
				cout << "\nNew Number of Players:  ";
				cin >> numPlayers;
				break;
			case 5:
				cout << "\nCurrent Maximum Occupancy:  " << maxOccupancy;
				cout << "\nNew Maximum Occupancy:  ";
				cin >> maxOccupancy;
				break;
			case 6:
				cout << "\nCurrent Game Duration in Hours:  " << gameDurationInHours;
				cout << "\nNew Game Duration in Hours:  ";
				cin >> gameDurationInHours;
				break;		
		}
	}while(choice != 7);
}



Text* Game::getGameName() const
{
	return gameName;
}
Text* Game::getGameDescription() const
{
	return gameDescription;
}
float Game::getGameCost() const
{
	return gameCost;
}
int Game::getNumPlayers() const
{
	return numPlayers;
}
int Game::getMaxOccupancy() const
{
	return maxOccupancy;
}
float Game::getGameDurationInHours() const
{
	return gameDurationInHours;
}

void Game::setGameName(Text* n)
{
	gameName = n;
}
void Game::setGameDescription(Text* d)
{
	gameDescription = d;
}
void Game::setGameCost(float c)
{
	gameCost = c;
}
void Game::setNumberPlayers(int p)
{
	numPlayers = p;
}
void Game::setMaxOccupancy(int m)
{
	maxOccupancy = m;
}
void Game::setGameDurationInHours(float h)
{
	gameDurationInHours = h;
}
