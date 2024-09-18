/*
    Author: Robert J. Morriss, Lloyd D. Galvez
    Date: 9/13/24
    File: Cart.cpp
    Purpose: Function definition file for Cart Class for CSC 1310-105 Group 4 Program 1
*/

#include "Cart.h"

/**
 * Default constructor for the Cart object
 * Initialzes all attributes of the object to their default
 */
Cart::Cart() {
    this->rowSize = 1;
    this->rows = 1;
    this->mountType = true;
    this->color = "";
    this->rowOperationArr = new bool[1];
    this->rowOperationArr[0] = true;
}

/**
 * Overloaded constructor for the Cart object
 * Initializes all atributes based on the parameters
 * @param int rowSize - Amount of seats in each row
 * @param int rows - Amount of rows in the cart
 * @param bool mountingType - How the cart is mounted to the rail, true for over (Cart sits on top of the ride rail), False for Under (Top of Cart is attached to the bottom of the ride rail)
 * @param string color - Color of the Cart
 */
Cart::Cart(int rowSize, int rows, string mountingType, string color) {
    this->rowSize = rowSize;
    this->rows = rows;
    this->mountType = mountingType;
    this->color = color;
    this->rowOperationArr = new bool[this->rows];
    for (int i = 0; i < this->rows; i++) { this->rowOperationArr[i] = true; }
}

/**
 * Destructor for the Cart object
 * Deletes the dynamic boolean array
 */
Cart::~Cart(){ delete [] this->rowOperationArr; }

/**
 * @return Amount of seats in each row
 */
int Cart::getRowSize() { return this->rowSize; };

/**
 * @return Amount of rows in the Cart
 */
int Cart::getRows() { return this->rows; };

/**
 * @return The mounting type of the Cart
 */
string Cart::getType() { return this->mountType; };

/**
 * @return The Color of the Cart
 */
string Cart::getColor() { return this-> color; };

/**
 * Determines if a specified row of the Cart is operational
 * @param int Index of the row in the rowOperationArr to check
 * @return If the row is operational
 */
bool Cart::isRowOperational(int index) { return this->rowOperationArr[index]; };

/**
 * Multiplies the number of seats in a row by the number of operational rows
 * @return The operational capacity of the Cart
 */
int Cart::getCurrentCapacity() {
    int cap = 0;
    for (int i = 0; i < this->rows; i++) { if (isRowOperational(i)) cap += this->rowSize; }
    return cap;
}

/**
 * Sets a new amount of seats in the rows of the Cart
 * @param int Rowsize - New amount of seats in a row
 */
void Cart::setRowSize(int rowSize) { this->rowSize = rowSize; };

/**
 * Sets a new amount of rows and updates the size of the rowOperationArr for the Cart
 * @param int Rows - New amount of rows in the Cart
 */
void Cart::setRows(int rows) { 
    updateOperationalArr(rows);
    this->rows = rows; 
};

/**
 * Sets a new mounting type for the Cart
 * @param bool Type - New mounting type of the Cart
 */
void Cart::setType(string type) { this->mountType = type; };

/**
 * Sets a new color for the Cart
 * @param string Color - New color of the Cart
 */
void Cart::setColor(string color) { this->color = color; };

/**
 * Changes the operational status of a specified row in the Cart
 * @param int Index - Index of the row in the Cart being modified
 * @param bool Stat - New status of the selected row 
 */
void Cart::setRowStatus(int index, bool stat) { this->rowOperationArr[index] = stat; };

/**
 * Called by the setRows function
 * 
 * dynamically allocate a new boolean area with the given size
 * 
 * if smaller than current rowOperation array, populates the new arr with the first "x" elements of the current array where "x" is the given int 
 * 
 * if bigger than current rowOperation array, populates the first "y" elements of the new array with the current array where "y" is the size of the current array
 * 
 * initializes remaining elements to True
 * @param int newRows - Size of the new boolean array
 */
void Cart::updateOperationalArr(int newRows) {
    bool* newArr = new bool[newRows];
    for (int i = 0; i < newRows; i++) {
        if (i < this->rows) newArr[i] = this->rowOperationArr[i];
        else newArr[i] = true;
        delete [] this->rowOperationArr;
        this->rowOperationArr = newArr;
    }
}

/** printCart()
 * prints all information about the cart
 */
void Cart::printCart() {
    cout << "\t\tROW SIZE:\t" << this->getRowSize() << endl;
    cout << "\t\tROWS:\t\t" << this->getRows() << endl;
    cout << "\t\tMOUNT TYPE:\t"<< this->getType() << endl;
    cout << "\t\tCOLOR:\t\t" << this->getColor() << endl;
}