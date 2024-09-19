/*
    Author: Robert J. Morriss, Lloyd D. Galvez
    Date: 9/14/24
    File: Ride.cpp
    Purpose: Function definition file for Ride Class for CSC 1310-105 Group 4 Program 1
*/

// TODO: add comments to funtions

#include "Ride.h"

// CONSTRUCTORS:

/** Ride()
 * Default Ride constructor
 * Initializes the Ride object and default all atribute values
 */
Ride::Ride() {
    this->name = "";
    this->year = 1;
    this->type = "";
    this->cart = new Cart();
    this->capacity = this->cart->getCurrentCapacity();
}

/** Ride(string, int, string)
 * First Overloaded Ride constructor
 * Initializes the Ride object
 * Declares all Ride attributes with the given parameters
 * Points the Cart* attribute to a new Default Cart object
 */
Ride::Ride(string name, int year, string type) {
    this->name = name;
    this->year = year;
    this->type = type;
    this->cart = new Cart();
    this->capacity = this->cart->getCurrentCapacity();
}

/** Ride(string, int, string, int, int, string, string)
 * Second Overloaded Ride constructor
 * Initializes the Ride object
 * Delcares all Ride attributes with the given parameters
 * Points the Cart* attribute to a new Cart object using the overloaded constructor filled with the remaining parameters
 * Calculates the ride capacity
 */
Ride::Ride(string name, int year, string type, int rowSize, int rows, string mountType, string color) {
    this->name = name;
    this->year = year;
    this->type = type;
    this->cart = new Cart(rowSize, rows, mountType, color);
    this->capacity = this->cart->getCurrentCapacity();
}

// DESTRUCTOR:

/** ~Ride()
 * Destructor for the Ride
 * Deletes the pointer to the Cart object, then the Ride itself
 */
Ride::~Ride() { delete this->cart; }

// GETTERS:

string Ride::getName() { return this->name; };
int Ride::getCap() { return this->capacity; };
int Ride::getYear() { return this->year; };
string Ride::getType() { return this->type; };
Cart* Ride::getCart() { return this->cart; };

// SETTERS:

void Ride::setName(string name) { this->name = name; };
void Ride::setCap() { this->capacity = this->cart->getCurrentCapacity(); }; // Resets the Capacity of the ride by calculating the row size * # of operational rows
void Ride::setYear(int year) { this->year = year; };
void Ride::setType(string type) { this->type = type; };
void Ride::setCart(Cart* cart) { this->cart = cart; };

// PRINTER:

/** printRide()
 * Prints all information about the ride and it's cart 
 */
void Ride::printRide() {
    cout << "NAME:\t\t" << this->getName() << endl;
    cout << "YEAR:\t\t" << this->getYear() << endl;
    cout << "CAPACITY:\t" << this->getCap() << endl;
    cout << "TYPE:\t\t" << this->getType() << endl;
    cout << "CART:" << endl;
    this->cart->printCart();
}