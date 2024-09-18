/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: testDriver.cpp
    Purpose: Test functionality of the Park, Ride, and Cart classes (not to be used a functional program driver)
*/

// TODO: Format outputs to be visually appealing 

#include "Park.h"

int main() {
    Park* myPark = new Park();
    Ride* modify;
    int choice;
    string name,
           type,
           color,
           mountType;
    int year,
        rowSize,
        rows;

    while (choice != 5) {
        cout << "Main Menu" << endl;
        cout << "1.\tAdd Ride\n2.\tRemove Ride\n3.\tEdit Ride\n4.\tPrint Rides\n5.\tExit Program\nCHOICE: ";
        cin >> choice;
        while (choice < 1 || choice > 5) {
            cout << "invalid entry, please enter a number between 1 and 5" << endl;
            cin >> choice;
        }
        switch (choice) {
            case 1:
                cout << "Add Menu" << endl;
                cout << "1.\tBlank Ride\n2.\tRide w/out Cart\n3.\tFull Ride\n0.\tCancel\nCHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > 3) {
                    cout << "invalid entry, please enter a number between 0 and 3" << endl;
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
                        cin.ignore();
                        cout << "MOUNT TYPE:\t";
                        getline(cin, mountType);
                        cout << "COLOR:\t\t";
                        getline(cin, color);

                        myPark->addRide(name, year, type, rowSize, rows, mountType, color);
                        break;
                    default:
                        break;
                }
                choice = 0;
                break;
            case 2:
                cout << "Which Ride should be Removed:" << endl;
                for (int i = 0; i < myPark->getRideCount(); i++) {
                    cout << i + 1 << ".\t" << myPark->getRide(i)->getName() << endl;
                }
                cout << "0.\tCancel" << endl;
                cout << "CHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > myPark->getRideCount()) {
                    cout << "invalid choice. please enter a number between - and " << myPark->getRideCount() << "." << endl;
                    cout << "CHOICE: ";
                    cin >> choice;
                }
                if (choice == 0) break;
                myPark->removeRide(choice - 1);
                choice = 0;
                break;
            case 3:
                cout << "Which Ride should be Modified:" << endl;
                for (int i = 0; i < myPark->getRideCount(); i++) {
                    cout << i + 1 << ".\t" << myPark->getRide(i)->getName() << endl;
                }
                cout << "0.\tCancel" << endl;
                cout << "CHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > myPark->getRideCount()) {
                    cout << "invalid choice. please enter a number between 0 and " << myPark->getRideCount() << endl;
                    cout << "CHOICE: ";
                    cin >> choice;
                }
                if (choice == 0) break;
                modify = myPark->getRide(choice - 1);
                while(choice != 0) {
                    cout << "CURRENT RIDE ATTRIBUTES" << endl;
                    modify->printRide();
                    cout << "Which attribute do you want to change:" << endl;
                    cout << "\tRide attributes:" << endl;
                    cout << "\t1.\tRide Name\n\t2.\tRide Year\n\t3.\tRide Type\n";
                    cout << "\tCart attributes:" << endl;
                    cout << "\t4.\tRow Size\n\t5.Cart Rows\n\t6.\tMount Type\n\t7.\tCart Color\n";
                    cout << "0.\tExit Editor\nCHOICE: ";
                    cin >> choice;
                    while (choice < 0 || choice > 7) {
                        cout << "invalid choice. please enter a number between 0 and 7" << endl;
                        cout << "CHOICE: ";
                        cin >> choice;
                    }
                    cin.ignore();
                    switch (choice) {
                        case 1:
                            cout << "NEW NAME:\t";
                            getline(cin, name);
                            modify->setName(name);
                            break;
                        case 2:
                            cout << "NEW YEAR:\t";
                            cin >> year;
                            modify->setYear(year);
                            break;
                        case 3:
                            cout << "NEW TYPE:\t";
                            getline(cin, type);
                            modify->setType(type);
                            break;
                        case 4:
                            cout << "NEW ROW SIZE:\t";
                            cin >> rowSize;
                            modify->getCart()->setRowSize(rowSize);
                            break;
                        case 5:
                            cout << "NEW ROWS:\t";
                            cin >> rows;
                            modify->getCart()->setRows(rows);
                            break;
                        case 6:
                            cout << "NEW MOUNT:\t";
                            getline(cin, mountType);
                            modify->getCart()->setType(mountType);
                            break;
                        case 7:
                            cout << "NEW COLOR:\t";
                            getline(cin, color);
                            modify->getCart()->setColor(color);
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 4:
                cout << "Print Menu" << endl;
                cout << "1.\tPrint One Ride\n2.\tPrint All Rides\n0.\tCancel\nCHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > 2) {
                    cout << "invalid entry, please enter a number between 0 and 2" << endl;
                    cin >> choice;
                }

                switch (choice) {
                    case 1:
                        cout << "Which Ride should be Printed:" << endl;
                        for (int i = 0; i < myPark->getRideCount(); i++) {
                            cout << i + 1 << ".\t" << myPark->getRide(i)->getName() << endl;
                        }
                        cout << "0.\tCancel" << endl;
                        cout << "CHOICE: ";
                        cin >> choice;
                        while (choice < 0 || choice > myPark->getRideCount()) {
                            cout << "invalid choice. please enter a number between 0 and " << myPark->getRideCount() << "." << endl;
                            cout << "CHOICE: ";
                            cin >> choice;
                        }
                        if (choice == 0) break;
                        cout << string(58, '*') << endl;
                        myPark->getRide(choice - 1)->printRide();
                        break;
                    case 2:
                        myPark->printRides();
                        break;
                    default:
                        break;
                }
                choice = 0;
                break;
            default:
                break;
        }
    }

    cout << "GOODBYE!";
    
    delete modify;
    delete myPark;

    // myPark->addRide("freakCoaster", 2024, "Thrill", 4, 13, "Over", "Red");
    // myPark->printRides();

    return 0;
}