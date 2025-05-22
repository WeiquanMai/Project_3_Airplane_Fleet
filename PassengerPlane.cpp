// Implementation file for PassengerPlane.h
#include "PassengerPlane.h"
#include <string>

using namespace std;

// Mutators
void PassengerPlane::setMaxNumberOfPassengers(int p)
{
	maxNumberOfPassengers = p;
}

// Create a new Passenger Plane and add it to airplane fleet
PassengerPlane* PassengerPlane::addNewPassengerPlane()
{
	// Variables
		// Variables
	string aManufacturer;
	string aModel;
	int year;
	int hours;
	int maxPassenger;

	// Ask user for information
	cout << "Enter name of manufacturer: ";
	getline(cin, aManufacturer);
	cout << "Enter model: ";
	getline(cin, aModel);
	cout << "Enter year built: ";
	cin >> year;
	cout << "Enter flight hours: ";
	cin >> hours;
	cout << "Enter maximum passenger count: ";
	cin >> maxPassenger;
	cin.ignore();

	// Call constructor to create new passenger plane
	PassengerPlane* newPlane = new PassengerPlane(aManufacturer, aModel, year, hours, maxPassenger);

	return newPlane;
}

// Accessor
int PassengerPlane::getMaxNumberOfPassengers() const
{
	return maxNumberOfPassengers;
}
// Virtual function to get a description of the airplane
void PassengerPlane::getDescription() const
{
	cout << "ID#: " << getAirplane_ID() << ", manufacturer: " << getManufacturer()
		<< ", model: " << getModel() << ", year: " << getYearBuilt() << ", hours: " << getFlightHours()
		<< ", max cargo: " << getMaxNumberOfPassengers() << endl;
}
