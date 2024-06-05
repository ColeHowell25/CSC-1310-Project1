# this is the Makefile for the Buisiness program
# all you have to do is type the word "make" in the command prompt to compile
# or you can type "make clean" to delete all object & executable files

all			:	Business

Business	:	Business.o Driver.o RentItem.o Game.o Text.o
			g++ -o Business.exe Driver.o Business.o RentItem.o Game.o Text.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
Driver.o	:	Driver.cpp
			g++ -I ./ -c Driver.cpp
				
Business.o	:	Business.cpp
			g++ -I ./ -c Business.cpp
			
RentItem.o	:	RentItem.cpp
			g++ -I ./ -c RentItem.cpp
	
Game.o		:	Game.cpp
			g++ -I ./ -c Game.cpp
			
Text.o		:	Text.cpp
			g++ -I ./ -c Text.cpp

clean		:	Business.exe
			del *.o 
			del Business.exe
			
			