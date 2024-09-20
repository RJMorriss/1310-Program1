/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: testDriver.cpp
    Purpose: Test functionality of the Park, Ride, and Cart classes (not to be used a functional program driver)
*/

/** TODO:
 * @line 169 Add row operational status to the Ride editor
 * Format outputs to be visually appealing
 */
#include "Park.h"

int main() {
    Park* myPark = new Park();
    Ride* modify;
    int choice;
    string name,
           type,
           color,
           mountType;
    char input;
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
            case 1: // 1. ADD RIDE
                cout << "Add Menu" << endl;
                cout << "1.\tBlank Ride\n2.\tRide w/out Cart\n3.\tFull Ride\n0.\tCancel\nCHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > 3) {
                    cout << "invalid entry, please enter a number between 0 and 3" << endl;
                    cin >> choice;
                }
                switch (choice) {
                    case 1: // 1.1 ADD BLANK RIDE
                        myPark->addRide();
                        break;
                    case 2: // 1.2 CUSTOM RIDE, DEFUALT CART
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
                    case 3: // 1.3 CUSTROM RIDE, CUSTOM CART
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
                    default: // 1.0 CANCEL
                        break;
                }
                choice = 0;
                break;
            case 2: // 2. REMOVE RIDE
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
            case 3: // 3. EDIT RIDE
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
                    cout << "\t4.\tRow Size\n\t5.\tCart Rows\n\t6.\tMount Type\n\t7.\tCart Color\n\t8.\tRow Status\n";
                    cout << "\t0.\tExit Editor\nCHOICE: ";
                    cin >> choice;
                    while (choice < 0 || choice > 8) {
                        cout << "invalid choice. please enter a number between 0 and 8" << endl;
                        cout << "CHOICE: ";
                        cin >> choice;
                    }
                    cin.ignore();
                    switch (choice) {
                        case 1: // 3.1 CHANGE NAME
                            cout << "NEW NAME:\t";
                            getline(cin, name);
                            modify->setName(name);
                            break;
                        case 2: // 3.2 CHANGE YEAR
                            cout << "NEW YEAR:\t";
                            cin >> year;
                            modify->setYear(year);
                            break;
                        case 3: // 3.3 CHANGE RIDE TYPE
                            cout << "NEW TYPE:\t";
                            getline(cin, type);
                            modify->setType(type);
                            break;
                        case 4: // 3.4 CHANGE ROW SIZE
                            cout << "NEW ROW SIZE:\t";
                            cin >> rowSize;
                            modify->getCart()->setRowSize(rowSize);
                            break;
                        case 5: // 3.5 CHANGE ROW COUNT
                            cout << "NEW ROWS:\t";
                            cin >> rows;
                            modify->getCart()->setRows(rows);
                            break;
                        case 6: // 3.6 CHANGE CART MOUNT TYPE
                            cout << "NEW MOUNT:\t";
                            getline(cin, mountType);
                            modify->getCart()->setType(mountType);
                            break;
                        case 7: // 3.7 CHANGE COLOR
                            cout << "NEW COLOR:\t";
                            getline(cin, color);
                            modify->getCart()->setColor(color);
                            break;
                        case 8: // 3.8 ROW OPERATIONS EDITOR
                            cout << "CURRENT ROW STATUS:" << endl;
                            for (int i = 0; i < modify->getCart()->getRows(); i++) {
                                cout << i + 1 << ".\t";
                                for (int j = 0; j < modify->getCart()->getRowSize(); j++) {
                                    // cout << char(177 + (42 * (modify->getCart()->isRowOperational(i)))) << " ";
                                    if (modify->getCart()->isRowOperational(i)) cout << "\033[42m  \033[0m ";
                                    else cout << "\033[41m  \033[0m ";
                                    
                                }
                                cout << endl;
                            }
                            cout << "0.\tCANCEL" << endl;
                            cout << "Which Row do you want to modify?\nCHOICE: ";
                            cin >> choice;
                            while (choice < 0 || choice > modify->getCart()->getRows()) {
                                cout << "invalid choice. please enter a number between - and " << modify->getCart()->getRows() << "." << endl;
                                cout << "CHOICE: ";
                                cin >> choice;
                            }
                            cout << "Is this row Operational? (T/F):  ";
                            cin >> input;
                            if (toupper(input) != 'T' && toupper(input) != 'F') {
                                cout << "invalid input. please enter a \'T\' or \'F\'";
                                cin >> input;
                            }
                            modify->getCart()->setRowStatus(choice, toupper(input) == 'T');
                            modify->setCap();
                            break;
                        default: // 3.0 CANCEL
                            break;
                    }
                }
                break;
            case 4: // 4. PRINT RIDE(S)
                cout << "Print Menu" << endl;
                cout << "1.\tPrint One Ride\n2.\tPrint All Rides\n0.\tCancel\nCHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > 2) {
                    cout << "invalid entry, please enter a number between 0 and 2" << endl;
                    cin >> choice;
                }

                switch (choice) {
                    case 1: // 4.1 PRINT ONE RIDE
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
                    case 2: // 4.2 PRINT ALL RIDES
                        myPark->printRides();
                        break;
                    default:
                        break;
                }
                choice = 0;
                break;
            default: // 5. EXIT
                break;
        }
    }

    cout << "GOODBYE!";
    
    // delete modify;
    delete myPark;

    // myPark->addRide("freakCoaster", 2024, "Thrill", 4, 13, "Over", "Red");
    // myPark->printRides();

    return 0;
}