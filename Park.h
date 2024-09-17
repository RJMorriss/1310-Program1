/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: Park.h
    Purpose: Header file for Park Class for CSC 1310-105 Group 4 Program 1
*/

#ifndef PARK_H
#define PARK_H

#include "Ride.h"

class Park {
    private:
        int size,
            rideCount;
        Ride** rideArr;

        void arrSizeUp();
        void arrSizeDown();

    public:
        Park();
        ~Park();
        int getSize();
        void setSize(int);
        void addRide();
        void addRide(string, int, string);
        void addRide(string, int, string, int, int, bool, string);
        void removeRide(int);
        void printRides();
};

#endif