/*
    Author: Robert J. Morriss
    Date: 9/13/24
    File: Cart.h
    Purpose: Header file for Cart Class for CSC 1310-105 Group 4 Program 1
*/

#ifndef CART_H
#define CART_H

#include <iostream>
using namespace std;

class Cart {
    private:
        int rowSize;
        int rows;
        bool mountType;
        string color;
        bool* rowOperationArr;

        void updateOperationalArr(int);

    public:
        Cart();
        Cart(int, int, bool, string);
        ~Cart();

        int getRowSize();
        int getRows();
        bool getType();
        string getColor();
        bool isRowOperational(int);
        int getCurrentCapacity();

        void setRowSize(int);
        void setRows(int);
        void setType(bool);
        void setColor(string);
        void setRowStatus(int, bool);
};

#endif