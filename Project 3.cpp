/*
* CSC237 Project3: Airplane Fleet
* Student: Weiquan Mai
* Due Date: May 7, 2025
* Description: 
* Program utilizes a command-loop structure to create and manage a fleet of airplane objects
* Command Loop has the following commands:
* A- ADD a new airplane to the fleet
* F- FLY a plane in the fleet
* H- Print HELP text
* P- PRINT current fleet information
* Q- QUIT (end the program).
* R- REMOVE airplane from the fleet
*/

#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"
#include "CargoPlane.h"
#include "PassengerPlane.h"

using namespace std;

// Function Prototype
void outputHelpText();
bool quit();
bool confirmYN();
void addFleet(vector<Airplane*> &fleet);
void flyFleet(vector<Airplane*> &fleet);
void printFleet(const vector<Airplane*> &fleet);
void removeFleet(vector<Airplane*> &fleet);

int main()
{
	// Variables
	string command;
	bool keepRunning = true;
	vector <Airplane*> fleet;

	// Prompt user for command input. Use command input to control function of the progrma
	while (keepRunning == true)
	{
		cout << "Enter command (or 'h' for help): ";
		getline(cin, command);

		// ignore empty commands
		if (command == " ") {
			cin.ignore();
		}
		else if (command == "a" || command == "A") 
		{
			addFleet(fleet);
		}
		else if (command == "f" || command == "F") 
		{
			flyFleet(fleet);
		}
		else if (command == "h" || command == "H") 
		{
			outputHelpText();
		}
		else if (command == "p" || command == "P") 
		{
			printFleet(fleet);
		}
		else if (command == "q" || command == "Q") 
		{
			keepRunning = !quit();
		}
		else if (command == "r" || command == "R") 
		{
			removeFleet(fleet);
		}
		else {
			cout << "Invalid command: " << command << endl;
		}
	} // End while loop
	
	// Clear dynamically allocated memory
	for (Airplane* airplane : fleet)
	{
		delete airplane;
	}
	fleet.clear();

	cout << "Exiting the program";
	return 0;
}// End of function main

/*________________________________________________________________________________________
* Function: outputHelpText
* Description: Outputs a brief summary of the user commands
*/
void outputHelpText()
{
	// Output list of supported commands
	cout << "Supported commands: " << endl;
	cout << "		a		add a new airplane to the fleet." << endl;
	cout << "		f		fly a plane in the fleet." << endl;
	cout << "		h		print help text." << endl;
	cout << "		p		print fleet information." << endl;
	cout << "		q		quit (end the program)." << endl;
	cout << "		r		remove airplane from the fleet." << endl;
} // End of function outputHelpText

/*________________________________________________________________________________________
* Function: confirmYN
* Description: Ask user to confirm if they want to quit the program.
* If user enters y or Y, then the program ends.
* If user enters n or N, then the program continues running.
* If user inputs any other value, then loop disregards value and runs again.
*/
bool confirmYN()
{
	string inputString;
	bool confirmationValue = false;
	bool inputIsOk = false;
	do
	{
		// Obtain input from user. If input is y or Y, close do-while loop, and return true to quit function. If input is n or N, close do-while loop, and return false to quit function
		// For any other input, tell user that the input is invalid, and prompt for another input.
		cout << "Are you sure that you want to exit the program? (y/n)" << endl;
		getline(cin, inputString);

		if (inputString == "y" || inputString == "Y")
		{
			confirmationValue = true;
			inputIsOk = true;
		}
		else if (inputString == "n" || inputString == "N")
		{
			confirmationValue = false;
			inputIsOk = true;
		}
		else
		{
			cout << "Invalid input: " << inputString << ". Please input y or n." << endl;
		}
	} while (inputIsOk == false);
	return confirmationValue;
} // End of function confirmYN

/*________________________________________________________________________________________
* Function: quit
* Description: Calls confirmYN function to confirm if user wants to exit the program
*/
bool quit()
{
	return confirmYN();
} // End of function quit

/*________________________________________________________________________________________
* Function: addFleet
* Description: Ask user to specify c for cargo plane or p for passenger plane.
* Then call the addNewCargoPlane function through CargoPlane.cpp if user specifies c,
* or call addNewPassengerPlane function through PassengerPlane.cpp if user specifies p.
*/
void addFleet(vector<Airplane*>& fleet)
{
	// Variables
	char planeType;

	// Output prompt asking user to specify c for cargo plane or p for passenger plane
	cout << "Enter type of airplane (c = cargo, p = passenger): ";
	cin >> planeType;
	cin.ignore();

	// If user specifies c, create a new cargo plane
	if (planeType == 'c' || planeType == 'C')
	{
		Airplane* newCargoPlane = CargoPlane::addNewCargoPlane();
		fleet.push_back(newCargoPlane);
		cout << "New airplane: ";
		newCargoPlane->getDescription();
		cout << "addNewAirplane: Size of fleet = " << fleet.size() << endl;
	}
	// Else if user specifies p, create a new passenger plane
	else if (planeType == 'p' || planeType == 'P')
	{
		Airplane* newPassengerPlane = PassengerPlane::addNewPassengerPlane();
		fleet.push_back(newPassengerPlane);
		cout << "New airplane: ";
		newPassengerPlane->getDescription();
		cout << "addNewAirplane: Size of fleet = " << fleet.size() << endl;
	}
	// Else input is invalid
	else
	{
		cout << "Invalid plane type" << planeType << endl;
		cin.ignore();
	}
} // End of addFleet function

/*________________________________________________________________________________________
* Function: printFleet
* Description: Use for loop to iterate through the vector to getDescription of each airplane.
*/
void printFleet(const vector<Airplane*> &fleet)
{
	cout << "Current fleet contains " << fleet.size() << " airplane(s): " << endl;

	// Utilize for loop to iterate through the vector to display description of each airplane
	for (int i = 0; i < fleet.size(); i++) 
	{
		const Airplane* airplanePtr = fleet[i];
		
		if (airplanePtr != nullptr)
		{
			airplanePtr->getDescription();
		}
		else
		{
			cout << "Error." << endl;
		}
	} // End of for loop
} // End of printFleet function

/*________________________________________________________________________________________
* Function: flyFleet
* Description: Prompt the user for specified airplaneID and number of hours in flight.
* If airplaneID exists in vector, then add flight hours to the airplane. 
* If airplaneID does not exist in vector, then display error message.
*/
void flyFleet(vector<Airplane*>& fleet)
{
	// Variables
	int airplaneNum;
	int flightLength;
	bool found = false;

	// Output prompts asking user to specify airplaneID and length of flight
	cout << "Which airplane do you want to fly? ";
	cin >> airplaneNum;
	cout << "Length of flight (in hours): ";
	cin >> flightLength;

	// Iterate through vector, if airplane ID is found, add flightLength to flightHours
	for (int i = 0; i < fleet.size(); i++)
	{
		Airplane* airplanePtr = fleet[i];

		if (airplanePtr != nullptr && airplanePtr->getAirplane_ID() == airplaneNum)
		{
			cout << "Choosing Airplane: ";
			airplanePtr->getDescription();
			airplanePtr->setFlightHours(airplanePtr->getFlightHours()+ flightLength);
			cout << "Flight complete: ";
			airplanePtr->getDescription();
			found = true;
			cin.ignore();
			break;
		}
	}// End of for loop

	// If airplaneID is not found, display error message
	if (!found)
	{
		cout << "Airplane " << airplaneNum << " not found in the fleet." << endl;
		cin.ignore();
	}
} // End of flyFleet function

/*________________________________________________________________________________________
* Function: removeFleet
* Description: Prompt user for specific airplaneID to remove.
* If airplaneID exists in vector, remove specified airplaneID.
* If airplaneID does not exist in vector, output error message.
*/
void removeFleet(vector<Airplane*>& fleet)
{
	// Variables
	int airplaneNum;
	bool found = false;

	// Output prompt asking user which airplane they wish to remove
	cout << "Which airplane do you want to remove? ";
	cin >> airplaneNum;
	cin.ignore();

	// Use for loop to iterate through vector. If specified airplaneID is found, delete the specified airplane.
	for (int i = 0; i < fleet.size(); i++)
	{
		Airplane* airplanePtr = fleet[i];

		if (airplanePtr != nullptr && airplanePtr->getAirplane_ID() == airplaneNum)
		{
			cout << "Choosing Airplane: ";
			airplanePtr->getDescription();
			delete fleet[i];
			fleet.erase(fleet.begin() + i);
			cout << "Removal Complete." << endl;
			found = true;
			break;
		}
	}// End of for loop

	// If airplaneID is not found, output error message.
	if (!found)
	{
		cout << "Airplane " << airplaneNum << " not found in the fleet." << endl;
	}
} // End of removeFleet function
