/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: Park.cpp
    Purpose: Function definition file for Park Class for CSC 1310-105 Group 4 Program 1
*/

#include "Park.h"


// CONSTRUCTOR:

/** Park()
 * Constructor for the Park Class
 * Initializes the Ride array to a size of 1
 */
Park::Park() {
    this->rideCount = 0;
    this->size = 1;
    this->rideArr = new Ride*[this->size];
}

// DESTRUCTOR:

/** ~Park()
 * Destructor for the Park Class
 * Deletes all Rides in the Ride array, the Ride array, and the Park istelf
 */
Park::~Park() {
    for (int i = 0; i < this->rideCount; i++) {
        delete this->rideArr[i];
    }
    delete [] this->rideArr;
}

// GETTERS:

/** getRide(int)
 * Access the Ride array to a specified index and returns the pointer element to the user
 * @param int index - The index of the desired Ride in the Ride array
 * @return Ride* - A Ride pointer from the Ride array at the specified index
 */
Ride* Park::getRide(int index) { return this->rideArr[index]; }
int Park::getRideCount() { return this->rideCount; };
int Park::getSize() { return this->size; };

// SETTERS:

void Park::setSize(int size) { this->size = size; }; 

// HELPERS:

/** arrSizeModify(bool)
 * Called automatically by the addRide and removeRide functions when the ridecount is either equal to the Ride Array size or less than half the Ride Array size
 * Update the size variable
 * - Double for a size increase
 * - Half for a size decrase
 * Dynamically allocate a new array with the new size with a lower limit of size 1
 * add all elements from the current array within the applicable range to the new array
 * delete the current array
 * set the new array to the class attribute
 * @param bool true to size up, false to size down
 */
void Park::arrSizeModify(bool up) {
    // cout << "Modifying array size:\t";
    // if (up) cout << "size up";
    // else cout << "size down";
    // cout << endl;
    // cout << "Size before: " << this->getSize() << endl;
    
    if (up) setSize(this->getSize() * 2);
    else setSize(this->getSize() / 2);

    // cout << "Size after: " << this->getSize() << endl;

    Ride** newArr = new Ride*[this->size];
    for (int i = 0; i < this->rideCount; i++) {
        newArr[i] = this->rideArr[i];
    }
    delete [] this->rideArr;
    this->rideArr = newArr;
}

/** addRide()
 * Default addRide function, creates a pointer to a new Ride object, using the default contructor, and adds it to the Ride Array
 */
void Park::addRide() {
    Ride* newRide = new Ride();
    if (this->rideCount == this->size) {
        // arrSizeUp();
        arrSizeModify(true);
    }
    this->rideArr[this->rideCount] = newRide;
    this->rideCount++;
}

/** addRide(string, int, string)
 * First Overloaded addRide function, creates a pointer to a new Ride object, using the first overloaded constructor
 * Adds it to the Ride Array
 * Adjusts the rideCount variable
 */
void Park::addRide(string name, int year, string type) {
    Ride* newRide = new Ride(name, year, type);
    if (this->rideCount == this->size) {
        // arrSizeUp();
        arrSizeModify(true);
    }
    this->rideArr[this->rideCount] = newRide;
    this->rideCount++;
}

/** addRide(string, int, string, int, int, string, string)
 * Second Overloaded addRide function, creates a pointer to a new Ride object, using the second overloaded constructor
 * Adds it to the Ride Array
 * Adjusts the rideCount variable
 */
void Park::addRide(string name, int year, string type, int rowSize, int rows, string mountType, string color) {
    Ride* newRide = new Ride(name, year, type, rowSize, rows, mountType, color);
    if (this->rideCount == this->size) {
        // arrSizeUp();
        arrSizeModify(true);
    }
    this->rideArr[this->rideCount] = newRide;
    this->rideCount++;
}

/** removeRide(int)
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
            // arrSizeDown();
            arrSizeModify(false);
        }
    }
}
