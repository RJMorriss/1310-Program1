/*
    Author: Robert J. Morriss
    Date: 9/14/24
    File: Ride.h
    Purpose: Header file for Ride Class for CSC 1310-105 Group 4 Program 1
*/

#ifndef RIDE_H
#define RIDE_H

#include "Cart.h"

class Ride {
    private:
        string name;
        int capacity;
        int year;
        string type;
        Cart* cart;
    
    public:
        Ride();
        Ride(string, int, string);
        Ride(string, int, string, int, int, bool, string);
        ~Ride();

        string getName();
        int getCap();
        int getYear();
        string getType();
        Cart* getCart();

        void setName(string);
        void setCap();
        void setYear(int);
        void setType(string);
        void setCart(Cart*);
        void printRide();
};


#endif