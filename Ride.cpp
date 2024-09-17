/*
    Author: Robert J. Morriss
    Date: 9/14/24
    File: Ride.cpp
    Purpose: Function definition file for Ride Class for CSC 1310-105 Group 4 Program 1
*/

#include "Ride.h"

Ride::Ride() {
    this->name = "";
    this->year = 1;
    this->type = "";
    this->cart = new Cart();
    this->capacity = this->cart->getCurrentCapacity();
}

Ride::Ride(string name, int year, string type) {
    this->name = name;
    this->year = year;
    this->type = type;
    this->cart = new Cart();
    this->capacity = this->cart->getCurrentCapacity();
}

Ride::Ride(string name, int year, string type, int rowSize, int rows, string mountType, string color) {
    this->name = name;
    this->year = year;
    this->type = type;
    this->cart = new Cart(rowSize, rows, mountType, color);
    this->capacity = this->cart->getCurrentCapacity();
}

Ride::~Ride() { delete this->cart; }

string Ride::getName() { return this->name; };
int Ride::getCap() { return this->capacity; };
int Ride::getYear() { return this->year; };
string Ride::getType() { return this->type; };
Cart* Ride::getCart() { return this->cart; };

void Ride::setName(string name) { this->name = name; };
void Ride::setCap() { this->capacity = this->cart->getCurrentCapacity(); };
void Ride::setYear(int year) { this->year = year; };
void Ride::setType(string type) { this->type = type; };
void Ride::setCart(Cart* cart) { this->cart = cart; };

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