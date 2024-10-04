/*
    Author: Robert J. Morriss, Lloyd D. Galvez
    Date: 9/13/24
    File: Cart.h
    Purpose: Header file for Cart Class for CSC 1310-105 Group 4 Program 1
*/

#ifndef CART_H
#define CART_H

#include <iostream>
#include <fstream>
using namespace std;

class Cart {
    private:
        int rowSize;
        int rows;
        string mountType;
        string color;
        bool* rowOperationArr;

        void updateOperationalArr(int);

    public:
        Cart();
        Cart(int, int, string, string);
        ~Cart();

        int getRowSize();
        int getRows();
        string getType();
        string getColor();
        bool isRowOperational(int);
        int getCurrentCapacity();

        void setRowSize(int);
        void setRows(int);
        void setType(string);
        void setColor(string);
        void setRowStatus(int, bool);

        friend ostream& operator<<(ostream& output, const Cart& cart) {
            output << "\t\tROW SIZE:\t" << cart.rowSize << endl;
            output << "\t\tROWS:\t\t" << cart.rows << endl;
            output << "\t\tMOUNT TYPE:\t"<< cart.mountType << endl;
            output << "\t\tCOLOR:\t\t" << cart.color << endl;
            output << "\t\tROW OPERATIONAL STATUS:\n\t\t▓▓ = Active\n\t\t░░ = Inactive\n";
            for (int i = 0; i < cart.rows; i++) {
                output << "\t\t" << i + 1 << ".\t";
                for (int j = 0; j < cart.rowSize; j++) { // Colored squares not supported for printing to a raw text file
                    if (cart.rowOperationArr[i]) output << "▓▓ "; // If row is operational, print (RowSize) T's
                    else output << "░░ "; // If row is NOT operational, print (RowSize) F's
                }
                output << endl;
            }
            return output;
        }
};

#endif