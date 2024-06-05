/****************************************************
 *  TITLE:   RentItem.h                             *
 *  AUTHOR:  April R Crockett                       *
 *  DATE:    January 16, 2019                       *
 *  PURPOSE: class specification of RentItem class  *
 ****************************************************/

#ifndef SALEITEM_H
#define SALEITEM_H

#include "Game.h"
#include "Text.h"

class RentItem
{
	private:
		Game* gameAssociation;
		Text* itemName;
		Text* itemDescription;
		float itemCost;
		int howManyInStock;	
		float rentDurationInHours;
		
	
	public:
		/*
			Function Name:  RentItem() Constructor (overloaded)
			Purpose:  this function is automatically called when the new RentItem object is created 
					(and the game associated with this rent item IS NOT known).   This function will
					set the following attributes to the data that was sent to the function:  itemName, 
					itemDescription, itemCost, howManyInStock, and rentDurationInHours.  The name and
					description of the game are dynamically created with the new operator. 
		*/	
		RentItem(Text*, Text*, float, int, float);
		
		/*
			Function Name:  RentItem() Constructor (overloaded)
			Purpose:  this function is automatically called when the new RentItem object is created 
					(and the game associated with this rent item IS known).   This function will
					set ALL attributes to the data that was sent to the function:  gameAssociation, itemName, 
					itemDescription, itemCost, howManyInStock, and rentDurationInHours.  The name and 
					description of the game are dynamically created with the new operator. 
		*/	
		RentItem(Game*, Text*, Text*, float, int, float);

		/*
			Function Name:  RentItem() Destructor
			Purpose:  this function is automatically called when the RentItem object is destroyed.  It's purpose
					is to release the dynamically allocated memory for the name and description of the RentItem.
		*/			
		~RentItem();

		/*
			Function Name:  printRentItemDetails()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints all details (attributes) describing the RentItem including the game the item is
					used with, the name of the item, description of the item, cost of the item, how many are
					in stock, and how long the item can be rented.
		*/			
		void printRentItemDetails();
		
		/*
			Function Name:  printRentItemName()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints the name attribute of the RentItem object (with no formatting)
		*/	
		void printRentItemName();
		
		/*
			Function Name:  editRentItemDetails()
			Parameters:  none
			Returns:  none (void)
			Purpose:  prints out a menu of options listing out each thing that can be edited about the RentItem object.
					Then, allows the user to select which thing they want to edit.  It prints out the current
					value and then asks the user what the new value should be. This function calls the
					editText function to change the value to the new value if it is of Text data type (name or description).  The game association can't be edited with this function.  
		*/	
		void editRentItemDetails();		

		/*
			The following six functions are accessor functions to retrieve attribute values from the RentItem object
		*/			
		Game* getGameAssociation() const;
		Text* getItemName() const;
		Text* getItemDescription() const;
		float getItemCost() const;
		int getHowManyInStock() const;
		float getRentDurationInHours() const;

		/*
			Function Name:  setGameAssociation() mutator function
			Parameters:  a pointer to a Game object
			Returns:  none (void)
			Purpose:  sets the gameAssociation attribute to a pointer to a Game object sent to this function.
		*/			
		void setGameAssociation(Game*);
		
		
};

#endif