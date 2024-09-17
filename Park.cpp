/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: Park.cpp
    Purpose: Function definition file for Park Class for CSC 1310-105 Group 4 Program 1
*/

#include "Park.h"

/**
 * Called automatically by the addRide functions when the Ride Array function is full
 * Update the size variable
 * Dynamically allocates a new array with twice the size
 * Add all elements from the current array to the new array
 * Delete the current array
 * Set the new array to the class attribute
 */
void Park::arrSizeUp() {
    setSize(this->size * 2);
    Ride** newArr = new Ride*[this->size];
    for (int i = 0; i < this->rideCount; i++) {
        newArr[i] = this->rideArr[i];
    }
    delete [] this->rideArr;
    this->rideArr = newArr;
}

/**
 * Called automatically by the removeRide function when the ridecount is less than half the Ride Array size
 * Update the size variable
 * Dynamically allocate a new array with half the size with a lower limit of size 1
 * add all elemnts from the current array within the applicable range to the new array
 * delete the current array
 * set the new array to the class attribute
 */
void Park::arrSizeDown() {
    setSize(this->size / 2);
    Ride** newArr = new Ride*[this->size];
    for (int i = 0; i < this->rideCount; i++) {
        newArr[i] = this->rideArr[i];
    }
    // for (int i = 0; i < this->size * 2; i++) {
    //     delete this->rideArr[i];
    // }
    delete [] this->rideArr;
    this->rideArr = newArr;
}

/**
 * Constructor for the Park Class
 * Initializes the Ride array to a size of 1
 */
Park::Park() {
    this->rideCount = 0;
    this->size = 1;
    this->rideArr = new Ride*[this->size];
}

/**
 * Destructor for the Park Class
 * Deletes all Rides in the Ride array, the Ride array, and the Park istelf
 */
Park::~Park() {
    for (int i = 0; i < this->rideCount; i++) {
        delete this->rideArr[i];
    }
    delete [] this->rideArr;
}

/**
 * Accesses the Park's size attribute variable
 * @return int - Size size of the Park's rideArr
 */
int Park::getSize() { return this->size; };

/**
 * Sets the Park's size attribute variable
 * @param int size - the size of the Park's rideArr
 */
void Park::setSize(int size) { this->size = size; }; 

/**
 * Default addRide function, creates a pointer to a new Ride object, using the default contructor, and adds it to the Ride Array
 */
void Park::addRide() {
    Ride* newRide = new Ride();
    if (this->rideCount == this->size) {
        arrSizeUp();
    }
    this->rideArr[this->rideCount] = newRide;
    this->rideCount++;
}

/**
 * First Overloaded addRide function, creates a pointer to a new Ride object, using the first overloaded constructor
 * Adds it to the Ride Array
 * Adjusts the rideCount variable
 */
void Park::addRide(string name, int year, string type) {
    Ride* newRide = new Ride(name, year, type);
    if (this->rideCount == this->size) {
        arrSizeUp();
    }
    this->rideArr[this->rideCount] = newRide;
    this->rideCount++;
}

/**
 * Second Overloaded addRide function, creates a pointer to a new Ride object, using the second overloaded constructor
 * Adds it to the Ride Array
 * Adjusts the rideCount variable
 */
void Park::addRide(string name, int year, string type, int rowSize, int rows, bool mountType, string color) {
    Ride* newRide = new Ride(name, year, type, rowSize, rows, mountType, color);
    if (this->rideCount == this->size) {
        arrSizeUp();
    }
    this->rideArr[this->rideCount] = newRide;
    this->rideCount++;
}

/**
 * Deletes the Ride pointer at the given index in the Ride Array
 * Slides all further rides down in the ride array back to fill in the gap
 * Adjusts the rideCount variable
 */
void Park::removeRide(int index) {
    if (index < this->rideCount && index >= 0) {
        delete this->rideArr[index];
        for (int i = index; i < this->rideCount - 1; i++) {
            this->rideArr[i] = this->rideArr[i + 1];
        }
        this->rideCount--;
        if (this->rideCount <= this->size / 2 && this->size > 1) {
            arrSizeDown();
        }
    }
}

/** printRides()
 * Prints all information about all rides in the Ride array
 */
void Park::printRides() {
    for (int i = 0; i < this->rideCount; i++) {
        cout << string(25, '*') << "RIDE " << i + 1 << string(25, '*') << endl;
        this->rideArr[i]->printRide();
    }
}