// Implementation file for CarcoPlane.h
#include "CargoPlane.h"
#include <string>

using namespace std;

// Mutators
void CargoPlane::setMaxCargoWeight(int m)
{
	maxCargoWeight = m;
}

// Create a new Cargo Plane and add it to airplane fleet
CargoPlane* CargoPlane::addNewCargoPlane()
{
	// Variables
	string aManufacturer;
	string aModel;
	int year;
	int hours;
	int maxCargoWeight;

	// Ask user for information
	cout << "Enter name of manufacturer: ";
	getline(cin, aManufacturer);
	cout << "Enter model: ";
	getline(cin, aModel);
	cout << "Enter year built: ";
	cin >> year;
	cout << "Enter flight hours: ";
	cin >> hours;
	cout << "Enter maximum cargo weight: ";
	cin >> maxCargoWeight;
	cin.ignore();

	// Call constructor to create new cargo plane
	CargoPlane* newPlane = new CargoPlane(aManufacturer, aModel, year, hours, maxCargoWeight);
	
	return newPlane;
}

// Accessors
int CargoPlane::getMaxCargoWeight() const
{
	return maxCargoWeight;
}
// Virtual function to get a description of the airplane
void CargoPlane::getDescription() const
{
	cout << "ID#: " << getAirplane_ID() << ", manufacturer: " << getManufacturer()
		<< ", model: " << getModel() << ", year: " << getYearBuilt() << ", hours: " << getFlightHours()
		<< ", max cargo: " << getMaxCargoWeight() << endl;
}
