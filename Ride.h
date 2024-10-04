/*
    Author: Robert J. Morriss, Lloyd D. Galvez
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
        Ride(string, int, string, int, int, string, string);
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

        /** friend ostream& operator(ostream&, const Ride&)
         * Overload "<<" operator
         * Outputs the information about the ride and its cart to the referenced output stream
         */
        friend ostream& operator<<(ostream& output, const Ride& ride) {
            output << "YEAR:\t\t" << ride.year << endl;
            output << "NAME:\t\t" << ride.name << endl;
            output << "CAPACITY:\t" << ride.capacity << endl;
            output << "TYPE:\t\t" << ride.type << endl;
            output << "CART:" << endl;
            output << *ride.cart;

            return output;
        }
};


#endif