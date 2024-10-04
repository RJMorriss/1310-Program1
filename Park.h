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

        /** friend ostream& operator(ostream&, const Park&)
         * Overload "<<" operator
         * Outputs the information about all rides in the rideArr to the referenced output stream
         */
        friend ostream& operator<<(ostream& output, const Park& park) {
            for (int i = 0; i < park.rideCount; i++) {
                output << string(25, '*') << " RIDE " << i + 1 << " " << string(25, '*') << endl;
                output << *park.rideArr[i];
            }

            return output;
        }
};

#endif