// Implementation file for the Airplane class

#include "Airplane.h"
#include <string>
using namespace std;

int Airplane::last_airplane_ID_issued = 0;

// Default Constructor
Airplane::Airplane()
{
	last_airplane_ID_issued++;
	airplane_ID = last_airplane_ID_issued;
}

// Constructor with arguments
Airplane::Airplane(string aManufacturer, string aModel, int aYear, int aHour)
{
	last_airplane_ID_issued++;
	airplane_ID = last_airplane_ID_issued;
	manufacturer = aManufacturer;
	model = aModel;
	yearBuilt = aYear;
	flightHours = aHour;
}

// Mutators
void Airplane::setManufacturer(string c)
{
	manufacturer = c;
}
void Airplane::setModel(string n)
{
	model = n;
}
void Airplane::setYearBuilt(int y)
{
	yearBuilt = y;
}
void Airplane::setFlightHours(int h)
{
	flightHours = h;
}

// Accessors
string Airplane::getManufacturer() const
{
	return manufacturer;
}
string Airplane::getModel() const
{
	return model;
}
int Airplane::getAirplane_ID() const
{
	return airplane_ID;
}
int Airplane::getYearBuilt() const
{
	return yearBuilt;
}
int Airplane::getFlightHours() const
{
	return flightHours;
}
int Airplane::get_last_airplane_ID_issued()
{
	return last_airplane_ID_issued;
}
// Virtual function to get a description of the airplane
void Airplane::getDescription() const
{
	cout << "ID#: " << getAirplane_ID() << ", manufacturer: " << getManufacturer()
		<< ", model: " << getModel() << ", year: " << getYearBuilt() << ", hours: " << getFlightHours() << endl;
}
