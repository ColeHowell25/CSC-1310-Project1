/****************************************************
 *  TITLE:   Game.h                                 *
 *  AUTHOR:  April R Crockett                       *
 *  DATE:    January 16, 2019                       *
 *  PURPOSE: class specification of Game class      *
 ****************************************************/
 
#ifndef GAME_H
#define GAME_H

#include "Text.h"

class Game
{
	private:
		Text* gameName;
		Text* gameDescription;
		float gameCost;
		int numPlayers;	//for pricing information - 0 means pricing is per game not per person
		int maxOccupancy; //how many can play simultaneously
		float gameDurationInHours; //for pricing information - zero means pricing is per person not per hour
		
		//if both numPlayers and gameDurationInHours is zero, then pricing is just per game.
	
	public:
		/*
			Function Name:  Game() Constructor
			Purpose:  this function is automatically called when the new Game object is created and will 
					set all the attributes to the data that was sent to the function.  The name and 
					description of the game are dynamically created with the new operator.
		*/	
		Game(Text*, Text*, float, int, int, float);

		/*
			Function Name:  Game() Destructor
			Purpose:  this function is automatically called when the Game object is destroyed.  It's purpose
					is to release the dynamically allocated memory for the name and description of the game.
		*/		
		~Game();

		/*
			Function Name:  printGameDetails()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints all details (attributes) describing the game including the name, description,
					cost, number of players if game is priced per person, how many players can play
					simultaneously, and game duration
		*/		
		void printGameDetails();
		
		/*
			Function Name:  printGameName()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints the gameName attribute of the Game object (with no formatting)
		*/	
		void printGameName();
		
		/*
			Function Name:  editGameDetails()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints out a menu of options listing out each thing that can be edited about the Game object.
					Then, allows the user to select which thing they want to edit.  It prints out the current
					value and then asks the user what the new value should be. This function calls the
					editText function to change the value to the new value if it is of Text data type (name or description).
		*/	
		void editGameDetails();

		/*
			The following six functions are accessor functions to retrieve attribute values
		*/			
		Text* getGameName() const;
		Text* getGameDescription() const;
		float getGameCost() const;
		int getNumPlayers() const;
		int getMaxOccupancy() const;
		float getGameDurationInHours() const;
		
		/*
			The following six functions are mutator functions to change the attribute values
		*/	
		void setGameName(Text*);
		void setGameDescription(Text*);
		void setGameCost(float);
		void setNumberPlayers(int);
		void setMaxOccupancy(int);
		void setGameDurationInHours(float);
		
		
};

#endif