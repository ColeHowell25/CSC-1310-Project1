/****************************************************
 *  TITLE:   Business.cpp                           *
 *  AUTHOR:  Cole Howell                            *
 *  DATE:    January 27, 2019                       *
 *  PURPOSE: class implementation of Business class *
 ****************************************************/


#include "Business.h"

using namespace std;

Business::Business(Text* name, int maxGames, int maxRentItems){ //assigns values to the private members of the class
	this->maxGames = maxGames;
	this->maxRentItems = maxRentItems;
	numRentItems = 0;
	numGames = 0;
	businessName = name;
	gameArray = new Game*[maxGames];
	rentItemArray = new RentItem*[maxRentItems];
}
	
//destructor
Business::~Business(){ //deletes all pointers that were defined by the constructor
	cout << "Business Destructor: Releasing memory for the games in the game array.\n";
	for (int i=0; i<numGames; i++){
		delete gameArray[i];
	}
	cout << "Business Destructor: Releasing Memory for the rent items in rent item array.\n";
	for (int i=0; i<numRentItems; i++){
		delete rentItemArray[i];
	}
	cout << "Business Destructor: Releasing Memory for the business Name\n";
	delete businessName;
	cout << "Business Destructor: Releasing memory for the game array\n";
	delete [] gameArray;
	cout << "Business Destructor: Releasing memory for the rent item array\n";
	delete [] rentItemArray;
}
	
//accessors for number of games and number of rent items
int Business::getNumGames() const{
	return numGames;
}

int Business::getNumRentItems() const{
	return numRentItems;
}
	
void Business::addGamesFromFile(){
	int numGamesReadFromFile = 0;
	
	string filename;
	ifstream inFile;
	char temp[1000];
	Text* gameName;
	Text* gameDescription;
	float gameCost;
	int numPlayers;	
	int maxOccupancy; 
	float gameDurationInHours;
	
	cin.ignore();
	cout << "Please enter the name of the file you wish to access : "; //prompts user to enter a filename to access
	getline(cin, filename);
	inFile.open(filename.c_str());
	
	if (inFile.good()){ //check if the file entered exists in directory
		inFile.getline(temp, 1000);
		while (!inFile.eof()){
			gameName = new Text(temp);
			inFile.ignore();
			inFile.getline(temp,1000);
			gameDescription = new Text(temp);
			inFile.ignore();
			inFile >> gameCost;
			inFile >> numPlayers;
			inFile >> maxOccupancy;
			inFile >> gameDurationInHours;
			inFile.ignore(); //removes \n from buffer
			
			
			//after reading in the game, create a new game object
			Game* oneGame = new Game(gameName, gameDescription, gameCost, numPlayers, maxOccupancy, gameDurationInHours);
			
			
			if (numGames == maxGames){
				resizeGameArray(); //doubles size of array
			}
			
			gameArray[numGames] = oneGame;
			
			

			(numGames)++;
			
			
			cout << endl;
			gameName->displayText(); //communicate to user that the game has been added
			cout << " was added to the game library!\n";
						
			inFile.getline(temp, 100); //read in the next game title if there is one
			
			numGamesReadFromFile++;
			cout << "Num games read: " << numGamesReadFromFile << endl;
		}
		cout << numGamesReadFromFile << " games were read from the file." << endl;
		inFile.close();
	}
	else{
		cout << "This file does not exist. Please try again.\n";
	}
	
	
}

void Business::addItemsFromFile(){
	int numRentItemsReadFromFile = 0;
	string filename;
	ifstream inFile;
	char temp[1000];
	Text* itemName;
	Text* itemDescription;
	RentItem* oneItem;
	float itemCost;
	int howManyInStock;	
	float rentDurationInHours;
	
	cin.ignore();
	cout << "Please enter the name of the file you wish to access : ";
	getline(cin, filename);
	inFile.open(filename.c_str());
	
	if (inFile.good()){ //occurs if the input file exists in the directory
		inFile.getline(temp, 1000);
		while (!inFile.eof()){ //while there is still data in file this sequence will continue
			itemName = new Text(temp);
			inFile.ignore();
			inFile.getline(temp,1000);
			itemDescription = new Text(temp);
			inFile.ignore();
			inFile >> itemCost;
			inFile >> howManyInStock;
			inFile >> rentDurationInHours;
			inFile.ignore();
			
			//constructor call passing the entered data
			oneItem = new RentItem(itemName, itemDescription, itemCost, howManyInStock, rentDurationInHours);
			
			if (numRentItems == maxRentItems){
				resizeRentItemArray(); //doubles size of array
			}
			rentItemArray[numRentItems] = oneItem;
			
			numRentItems++;
			
			cout << endl;
			itemName->displayText(); //communicate to user that the item has been added
			cout << " was added to the rent item library!\n";
						
			inFile.getline(temp, 100); //read in the next item title if there is one
			
			numRentItemsReadFromFile++;
		}
		inFile.close();
		cout << numRentItemsReadFromFile << " rent items were read from the file." << endl;
	}
	else{
		cout << "This file does not exist. Please try again.\n";
	}
	
}

void Business::addGameToItem(){ //basically setting the game association for an item
	int choice; 
	for (int i=0;i<numRentItems;i++){
		cout << "Which game is ";
		rentItemArray[i]->printRentItemName(); 
		cout << " associated with?\n";
		cout << "Choose a game from these choices : \n";
		printGameNames();
		cout << "Game Association : ";
		cin >> choice;
		int index = choice - 1;
		rentItemArray[i]->setGameAssociation(gameArray[index]); //setting the game association at rent item i with the choice of game
	}
}

void Business::addGameToArray(){ //manually adding a game to the game array
	char temp[1000];
	Text* gameName;
	Text* gameDescription;
	float gameCost;
	int numPlayers;	
	int maxOccupancy; 
	float gameDurationInHours;
	
	cout << "Please enter the details for the new game.\n";
	cin.ignore();
	cout << "Name of the game : ";
	cin.getline(temp, 1000);
	gameName = new Text(temp);
	cin.ignore();
	cout << "Enter a description for the game : " << endl;
	cin.getline(temp,1000);
	gameDescription = new Text(temp);
	cin.ignore();
	cout << "Enter the cost to play the game : $";
	cin >> gameCost;
	cout << "Enter the number of players : ";
	cin >> numPlayers;
	cout << "Enter the maximum number of players : ";
	cin >> maxOccupancy;
	cout << "Enter how long the game lasts in hours : ";
	cin >> gameDurationInHours;
	cin.ignore();
	//Pass entered info into constructor function for a new game
	Game* oneGame = new Game(gameName, gameDescription, gameCost, numPlayers, maxOccupancy, gameDurationInHours);
	
	if (numGames == maxGames){
		resizeGameArray(); //doubles size of array
	}
	gameArray[numGames] = oneGame;
	numGames++; //increment the number of games
}
	
void Business::editGameInArray(){
	int gameChoice;
	cout << "Choose a game to edit from the list : ";
	printGameNames();
	
	cout << "Choose a game to edit between 1 and " << numGames << " : ";
	cin >> gameChoice;
	int index = gameChoice - 1;
	while (gameChoice < 1 || gameChoice > numGames){ //input validation
		cout << "Error: Please enter a choice between 1 and " << numGames << " : ";
		cin >> gameChoice;
	}
	
	Game* oneGame = gameArray[index]; //indication which game in array to edit
	
	oneGame->editGameDetails(); //calls game member function
}

void Business::removeGameFromArray(){
	int gameChoice;
	cout << "Games in database : \n";
	printGameNames();
	
	cout << "Choose a game to delete between 1 and " << numGames << " : ";
	cin >> gameChoice;
	
	while (gameChoice < 1 || gameChoice > numGames){ //input validation
		cout << "Error: Please enter a choice between 1 and " << numGames << " : ";
		cin >> gameChoice;
	}
	
	int index = gameChoice - 1;
	
	for (int i=0; i<numRentItems; i++){ //will go through every game to see if there is any association with a rental item
		if (gameArray[index] = rentItemArray[i]->getGameAssociation()){
			cout << "This game is associated with a rental item named : " << rentItemArray[i]->getItemName() << endl;
			cout << "Association with this rental item will be removed before deleting.\n";
			
			rentItemArray[i]->setGameAssociation(NULL);
		}
	}
	cout << "The game ";
	gameArray[index]->printGameName();
	cout << " has been deleted.\n";
	
	delete gameArray[index]; //deleting single component of array
		
	int numElementsToMoveBack = (numGames) - 1; //defining how much to move the array size back for every deletion
	
	for(int i = index; i < numElementsToMoveBack; i++)
	{
		gameArray[i] = gameArray[i+1]; //move array elements!
	}
	
	//set the last game to a null pointer
	gameArray[numElementsToMoveBack] = NULL;
	
	//decrement the current number of games
	(numGames)--;
}
	
void Business::addRentItemToArray(){
	char temp[1000];
	Game* gameAssociation;
	Text* itemName;
	Text* itemDescription;
	float itemCost;
	int howManyInStock;	
	float rentDurationInHours;
	int gameAssociationChoice;
	
	if (numGames == 0){ //if there are no games no point in adding rent items
		cout << "There are no games to associate with a rental item.\n";
		cout << "Returning to main menu.\n\n\n";
		return;
	}
	cout << "Choose the game associated with the new rent item from the list below:\n"; //manual entry for user to add rent items
	printGameNames();
	cout << "This item is associated with game number : ";
	cin >> gameAssociationChoice;
	gameAssociation = gameArray[gameAssociationChoice];
	cout << "Please enter the rest of the details for the new rent item.\n";
	cin.ignore();
	cout << "Name of the item : ";
	cin.getline(temp, 1000);
	itemName = new Text(temp);
	cin.ignore();
	cout << "Enter a description for the new item : " << endl;
	cin.getline(temp,1000);
	itemDescription = new Text(temp);
	cin.ignore();
	cout << "Enter the cost to play the rent the item : $";
	cin >> itemCost;
	cout << "Enter how many of the items are in stock : ";
	cin >> howManyInStock;
	cout << "Enter how long the rental lasts in hours : ";
	cin >> rentDurationInHours;
	cin.ignore();
	//Pass entered info into constructor function for a new item
	RentItem* oneRentItem = new RentItem(gameAssociation, itemName, itemDescription, itemCost, howManyInStock, rentDurationInHours);
	
	if (numRentItems == maxRentItems){
		resizeRentItemArray(); //doubles size of array
	}
	rentItemArray[numRentItems] = oneRentItem;
	numRentItems++;
}
	
void Business::editRentItemInArray(){
	int itemChoice;
	cout << "Choose a game to edit from the list : ";
	printRentItemNames();
	
	cout << "Choose a rent item to edit between 1 and " << numRentItems << " : ";
	cin >> itemChoice;
	int index = itemChoice-1; //for making sure the correct item in array is being edited and no seg fault occurs 
	while (itemChoice < 1 || itemChoice > numRentItems){ //input validation
		cout << "Error: Please enter a choice between 1 and " << numRentItems << " : ";
		cin >> itemChoice;
	}
	
	RentItem* oneRentItem = rentItemArray[index];
	
	oneRentItem->editRentItemDetails();
}
	
void Business::removeRentItemFromArray(){
	int itemChoice;
	cout << "Rent Items in database : \n";
	printRentItemNames();
	
	cout << "Choose an item to delete between 1 and " << numRentItems << " : ";
	cin >> itemChoice;
	
	while (itemChoice < 1 || itemChoice > numRentItems){ //input validation
		cout << "Error: Please enter a choice between 1 and " << numRentItems << " : ";
		cin >> itemChoice;
	}
	
	int index = itemChoice - 1;
 
	cout << "The rent item " << rentItemArray[index]->getItemName() << " has been deleted.\n";
	
	delete rentItemArray[index];
		
	int numElementsToMoveBack = (numRentItems) - 1;
	
	for(int i = index; i < numElementsToMoveBack; i++)
	{
		rentItemArray[i] = rentItemArray[i+1]; //move array elements!
	}
	
	//set the last game to a null pointer
	rentItemArray[numElementsToMoveBack] = NULL;
	
	//decrement the current number of games
	(numRentItems)--;
	
}
	
void Business::printGames() const{ //prints all game information for every game
	for (int i = 0; i<numGames; i++){
		cout << i+1 << ": ";
		gameArray[i]->printGameDetails();
	}
}

void Business::printRentItems() const{ //prints all rent item information for every rent item
	for (int i=0; i<numRentItems; i++){
		cout << i+1 << ": "; 
		rentItemArray[i]->printRentItemDetails();
	}
}

void Business::saveData(){ //no clue how to implement in this context, no examples that I'm aware of to look at, code works otherwise
	string filenameGames,
		   filenameRentItems;
	ofstream myGameFile,
			 myRentItemFile;
			 
	cout << "What would you like to name the file for the games? : ";
	cin.ignore();
	getline(cin, filenameGames);
	myGameFile.open(filenameGames.c_str());
	for (int i=0; i<numGames; i++){
		myGameFile << "Games: /n";
		//myGameFile << gameArray[i]->printGameDetails() << endl;
		myGameFile << gameArray[i]->getGameDescription() << endl;
		myGameFile << gameArray[i]->getGameCost() << endl;
		myGameFile << gameArray[i]->getNumPlayers() << endl;
		myGameFile << gameArray[i]->getMaxOccupancy() << endl;
		myGameFile << gameArray[i]->getGameDurationInHours() << endl;
		myGameFile << "\n\n******************************************************\n";
	}
	myGameFile.close();
	
	cout << "What would you like to name the file for rent items? : ";
	cin.ignore();
	getline(cin, filenameRentItems);
	myRentItemFile.open(filenameRentItems.c_str());
	for (int i=0; i<numRentItems; i++){
		myRentItemFile << "Rent Items: \n";
		myRentItemFile << rentItemArray[i]->getGameAssociation() << endl;
		myRentItemFile << rentItemArray[i]->getItemName() << endl;
		myRentItemFile << rentItemArray[i]->getItemDescription() << endl;
		myRentItemFile << rentItemArray[i]->getItemCost() << endl;
		myRentItemFile << rentItemArray[i]->getHowManyInStock() << endl;
		myRentItemFile << rentItemArray[i]->getRentDurationInHours() << endl;
		myRentItemFile << "\n\n******************************************************\n";
	}
	myRentItemFile.close();
}

void Business::resizeGameArray(){
	int newMax = 2*maxGames; //doubles the max size of the array
	Game** biggerArray = new Game*[newMax];
	cout << "The Game array is being resized to : " << newMax << " from " << maxGames << endl;
	
	for (int i=0; i<numGames; i++){ //makes the new array equal to the old in appropriate subscripts
		biggerArray[i] = gameArray[i];
	}
	delete []gameArray; //deletes the old array
	gameArray = biggerArray; //the resized array is now called the gameArray
	maxGames = newMax;
}

void Business::resizeRentItemArray(){
	int newMax = 2*maxRentItems; //doubles the max size of the array
	RentItem** biggerArray = new RentItem*[newMax];
	cout << "The Rent Item array is being resized to : " << newMax << " from " << maxRentItems << endl;
	
	for (int i=0; i<numRentItems; i++){ //makes the new array equal to the old in appropriate subscripts
		biggerArray[i] = rentItemArray[i];
	}
	delete []rentItemArray; //deletes the old array
	rentItemArray = biggerArray; //the resized array is now called the gameArray
	maxRentItems = newMax;
}

void Business::printGameNames() const{
	for (int i = 0; i<numGames; i++){ //prints the game name for each game in the array
		cout << i+1 << ": "; 
		gameArray[i]->printGameName(); 
		cout << "\n\n";
	}
}

void Business::printRentItemNames() const{ //prints the rent item name for each one in the array
	for (int i=0; i<numRentItems; i++){
		cout << i+1 << ": ";
		rentItemArray[i]->printRentItemName();
		cout << "\n\n";
	}
}	

