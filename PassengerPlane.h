// Specification file for the PassengerPlane Class
// Obtained file from Professor Morgan
#ifndef PASSENGER_PLANE_H
#define PASSENGER_PLANE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Airplane.h"
using namespace std;

class PassengerPlane : public Airplane
{
private:
	int maxNumberOfPassengers;	// Maximum number of passengers

public:
	// Default constructor
	PassengerPlane() : Airplane() {
		maxNumberOfPassengers = 0;
	}


	// Constructor
	PassengerPlane(string manufacturer, string model, int yearBuilt,
		int flightHours, int maxNumberOfPassengers) :
		Airplane(manufacturer, model, yearBuilt, flightHours) {
		this->maxNumberOfPassengers = maxNumberOfPassengers;
	}

	virtual ~PassengerPlane() {
		cout << "Destructor for PassengerPlane " << this->getAirplane_ID() << endl;
	}

	// Mutators
	void setMaxNumberOfPassengers(int passengers);
	static PassengerPlane* addNewPassengerPlane();

	// Accessors
	int getMaxNumberOfPassengers() const;

	// Changed virtual string to virtual void
	virtual void getDescription() const;


};

#endif
