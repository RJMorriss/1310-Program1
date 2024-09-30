/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: Park.h
    Purpose: Header file for Park Class for CSC 1310-105 Group 4 Program 1
*/

/**
 * TODO: Add Print to file
 */

#ifndef PARK_H
#define PARK_H

#include "Ride.h"

class Park {
    private:
        int size,
            rideCount;
        Ride** rideArr;

        void arrSizeModify(bool);

    public:
        Park();
        ~Park();

        Ride* getRide(int);
        int getRideCount();
        int getSize();

        void setSize(int);
        
        void addRide();
        void addRide(string, int, string);
        void addRide(string, int, string, int, int, string, string);
        void removeRide(int);
        void printRides();
        void printToFile(ofstream&);
};

#endif