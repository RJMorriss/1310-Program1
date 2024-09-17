/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: testDriver.cpp
    Purpose: Test functionality of the Park, Ride, and Cart classes (not to be used a functional program driver)
*/

#include "Park.h"

int main() {
    Park* myPark = new Park();
    int choice;
    string name,
           type,
           color;
    int year,
        rowSize,
        rows;
    bool mountType;

    while (choice != 5) {
        cout << "Menu" << endl;
        cout << "1.\tAdd Ride\n2.\tRemove Ride\n3.\tEdit Ride\n4.\tPrint Rides\n5.\tExit Program\nCHOICE: ";
        cin >> choice;
        while (choice < 1 or choice > 5) {
            cout << "invalid entry, please enter a number between 1 and 5" << endl;
            cin >> choice;
        }
        switch (choice) {
            case 1:
                cout << "Add Menu" << endl;
                cout << "1.\tBlank Ride\n2.\tRide w/out Cart\n3.\tFull Ride\nCHOICE: ";
                cin >> choice;
                while (choice < 1 or choice > 3) {
                    cout << "invalid entry, please enter a number between 1 and 3" << endl;
                    cin >> choice;
                }
                switch (choice) {
                    case 1:
                        myPark->addRide();
                        break;
                    case 2:
                        cin.ignore();
                        cout << "NAME:\t\t";
                        getline(cin, name);
                        cout << "YEAR:\t\t";
                        cin >> year;
                        cin.ignore();
                        cout << "TYPE:\t\t";
                        getline(cin, type);

                        myPark->addRide(name, year, type);
                        break;
                    case 3:
                        cin.ignore();
                        cout << "NAME:\t\t";
                        getline(cin, name);
                        cout << "YEAR:\t\t";
                        cin >> year;
                        cin.ignore();
                        cout << "TYPE:\t\t";
                        getline(cin, type);
                        cout << "ROW SIZE:\t";
                        cin >> rowSize;
                        cout << "ROWS:\t\t";
                        cin >> rows;
                        cout << "MOUNT TYPE:\t";
                        cin >> mountType;
                        cin.ignore();
                        cout << "COLOR:\t\t";
                        getline(cin, color);

                        myPark->addRide(name, year, type, rowSize, rows, mountType, color);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    }

    myPark->addRide("freakCoaster", 2024, "Thrill", 4, 13, true, "Red");
    myPark->printRides();

    return 0;
}