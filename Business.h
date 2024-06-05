/****************************************************
 *  TITLE:   Business.h                             *
 *  AUTHOR:  Cole Howell                            *
 *  DATE:    January 26, 2019                       *
 *  PURPOSE: class specification of Business class  *
 ****************************************************/

#ifndef BUSINESS_H
#define BUSINESS_H

#include "Game.h"
#include "Text.h"
#include "RentItem.h"
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Business{
	private:
	int numGames,
		maxGames,
		numRentItems,
		maxRentItems;
	Text* businessName;
	Game** gameArray;
	RentItem** rentItemArray;
	
	/*
			Function Name:  resizeGameArray() 
			Purpose:  Doubles the max size of the game array to avoid segmentation faults when the number of games equals 
					  the max 
		*/	
	void resizeGameArray();
	/*
			Function Name:  resizeRentItemArray() 
			Purpose:  Doubles the max size of the rent item array to segmentation faults when the number of rent items
					  equals the max value
		*/	
	void resizeRentItemArray();
	

	public:
	/*
			Function Name:  Business() Constructor (overloaded)
			Purpose:  this function is automatically called when the new Business object is created.
					This function will set the following attributes to the data that was sent to the function: 
					businessName, maxGames, and maxRentItems. The gameArray and rentItemArray are dynamically allocated 
					within this function. numGames and numRentItems are set to zero
		*/	
	Business(Text* businessName, int maxGames, int maxRentItems);
	
	/*
			Function Name:  ~Business() Destructor
			Purpose:  this function is automatically called when the Business object is destroyed. It destroys all pointer 
					  variables created within the constructor.
		*/	
	~Business();
	
	/*
			Function Name:  getNumGames() Accessor
			Purpose:  Returns the value of the numGames object 
		*/	
	int getNumGames() const;
	/*
			Function Name:  getNumRentItems() Accessor
			Purpose:  Returns the value of the numRentItems object 
		*/	
	int getNumRentItems() const;
	/*
			Function Name:  addGamesFromFile() 
			Purpose:  Allows the adding of game objects that were written on a file. It reads in all information
					  about the game and then connects this information to the appropriate subscript on the gameArray
		*/	
	void addGamesFromFile();
	/*
			Function Name:  addItemsFromFile() 
			Purpose:  Does the same thing as the addGamesFromFile function except it records parameters for a 
					  Rent Item and the Rent Item array respeectively
					  
		*/	
	void addItemsFromFile();
	/*
			Function Name:  addGameToItem() 
			Purpose:  Allows the user to pick which game is associated with any given rental item 
		*/	
	void addGameToItem();
	/*
			Function Name:  addGameToArray() 
			Purpose:  Manual addition of one game to the game array, user must enter all appropriate information via terminal 
		*/	
	void addGameToArray();
	/*
			Function Name:  editGameInArray() 
			Purpose:  Let's the user manually edit any chosen game within the database. 
		*/	
	void editGameInArray();
	/*
			Function Name:  removeGameFromArray() 
			Purpose:  Deletes a game from the array and moves the other members down. Also decrements the total number of games  
		*/	
	void removeGameFromArray();
	/*
			Function Name:  addRentItemToArray() 
			Purpose:  Manual addition of a rent item to the rent item array. Game association is done manually as well
					  as the other components of the rent item
		*/	
	void addRentItemToArray();
	/*
			Function Name:  editRentItemInArray() 
			Purpose:  Editing of chosen rent item array component controlled by user
		*/	
	void editRentItemInArray();
	/*
			Function Name:  removeRentItemFromArray() 
			Purpose:  Deletes chosen rent item from array and decrements the total number of rent items 
		*/	
	void removeRentItemFromArray();
	/*
			Function Name:  printGames() Accessor
			Purpose:  Prints all games and associated information to the terminal. 
		*/	
	void printGames() const;
	/*
			Function Name:  printRentItems() Accessor
			Purpose:  Prints all rent items and their associated information to the terminal
		*/	
	void printRentItems() const;
	/*
			Function Name:  saveData() 
			Purpose:  Saves the game data and rent item data to separate text files 
		*/	
	void saveData();
	/*
			Function Name:  printGameNames() 
			Purpose:  Prints only the game names for each game in the array 
		*/	
	void printGameNames() const;
	/*
			Function Name:  printRentItemNames() 
			Purpose:  Prints only the rent item name for each rent item in the array 
		*/	
	void printRentItemNames() const;
};

#endif