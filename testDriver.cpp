/*
    Author: Robert J. Morriss
    Date: 9/16/24
    File: testDriver.cpp
    Purpose: Test functionality of the Park, Ride, and Cart classes (not to be used a functional program driver)
*/

/** TODO:
 * Format outputs to be visually appealing
 * Comment the driver for readability
 */
#include "Park.h"

int main() {
    Park* myPark = new Park();
    Ride* modify;
    ofstream outfile;
    ifstream f; // Used to test if a filename already exists when printing to a file
    string name,
           type,
           color,
           mountType,
           filename;
    char input;
    int choice,
        year,
        rowSize,
        rows;

    cout << " _       __     __                             ______         __  __                    ____             __      __" << endl;
    cout << "| |     / /__  / /________  ____ ___  ___     /_  __/___      \\ \\/ /___  __  _______   / __ \\____ ______/ /__   / /" << endl;
    cout << "| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\     / / / __ \\      \\  / __ \\/ / / / ___/  / /_/ / __ `/ ___/ //_/  / / " << endl;
    cout << "| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/    / / / /_/ /      / / /_/ / /_/ / /     / ____/ /_/ / /  / ,<    /_/  " << endl;
    cout << "|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/    /_/  \\____/      /_/\\____/\\__,_/_/     /_/    \\__,_/_/  /_/|_|  (_)   " << endl;

    while (choice != 5) {
        cout << "\n\nPark Main Menu:" << endl;
        cout << "\t1. Add Ride\n\t2. Remove Ride\n\t3. Edit Ride\n\t4. Print Rides\n\t5. Exit Program\nCHOICE: ";
        cin >> choice;
        while (choice < 1 || choice > 5) {
            cout << "invalid entry, please enter a number between 1 and 5" << endl;
            cout << "CHOICE: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: // 1. ADD RIDE
                cout << "\n\nAdd Menu:" << endl;
                cout << "\t1. Blank Ride\n\t2. Ride w/out Cart\n\t3. Full Ride\n\t0. Cancel\nCHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > 3) {
                    cout << "\n\ninvalid entry, please enter a number between 0 and 3" << endl;
                    cout << "CHOICE: ";
                    cin >> choice;
                }
                switch (choice) {
                    case 1: // 1.1 ADD BLANK RIDE
                        myPark->addRide();
                        break;
                    case 2: // 1.2 CUSTOM RIDE, DEFUALT CART
                        cin.ignore();
                        cout << "\nNAME:\t\t";
                        getline(cin, name);
                        cout << "\nYEAR:\t\t";
                        cin >> year;
                        cin.ignore();
                        cout << "\nTYPE:\t\t";
                        getline(cin, type);

                        myPark->addRide(name, year, type);
                        break;
                    case 3: // 1.3 CUSTROM RIDE, CUSTOM CART
                        cin.ignore();
                        cout << "\nNAME:\t\t";
                        getline(cin, name);
                        cout << "\nYEAR:\t\t";
                        cin >> year;
                        cin.ignore();
                        cout << "\nTYPE:\t\t";
                        getline(cin, type);
                        cout << "\nROW SIZE:\t";
                        cin >> rowSize;
                        cout << "\nROWS:\t\t";
                        cin >> rows;
                        cin.ignore();
                        cout << "\nMOUNT TYPE:\t";
                        getline(cin, mountType);
                        cout << "\nCOLOR:\t\t";
                        getline(cin, color);

                        myPark->addRide(name, year, type, rowSize, rows, mountType, color);
                        break;
                    default: // 1.0 CANCEL
                        break;
                }
                choice = 0;
                break;
            case 2: // 2. REMOVE RIDE
                cout << "\n\nWhich Ride should be Removed:" << endl;
                for (int i = 0; i < myPark->getRideCount(); i++) {
                    cout << "\t" << i + 1 << ". " << myPark->getRide(i)->getName() << endl;
                }
                cout << "\t0. Cancel" << endl;
                cout << "CHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > myPark->getRideCount()) {
                    cout << "invalid choice. please enter a number between 0 and " << myPark->getRideCount() << "." << endl;
                    cout << "CHOICE: ";
                    cin >> choice;
                }
                if (choice == 0) break;
                myPark->removeRide(choice - 1);
                choice = 0;
                break;
            case 3: // 3. EDIT RIDE
                cout << "\n\nWhich Ride should be Modified:" << endl;
                for (int i = 0; i < myPark->getRideCount(); i++) {
                    cout << "\t" << i + 1 << ". " << myPark->getRide(i)->getName() << endl;
                }
                cout << "\t0. Cancel" << endl;
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
                    cout << "\nCURRENT RIDE ATTRIBUTES:" << endl;
                    modify->printRide();
                    cout << "\nWhich attribute do you want to change:" << endl;
                    cout << "\tRide attributes:" << endl;
                    cout << "\t\t1. Ride Name\n\t\t2. Ride Year\n\t\t3. Ride Type\n";
                    cout << "\tCart attributes:" << endl;
                    cout << "\t\t4. Row Size\n\t\t5. Cart Rows\n\t\t6. Mount Type\n\t\t7. Cart Color\n\t\t8. Row Status\n";
                    cout << "\t\t0. Exit Editor\nCHOICE: ";
                    cin >> choice;
                    while (choice < 0 || choice > 8) {
                        cout << "invalid choice. please enter a number between 0 and 8" << endl;
                        cout << "CHOICE: ";
                        cin >> choice;
                    }
                    cin.ignore();
                    switch (choice) {
                        case 1: // 3.1 CHANGE NAME
                            cout << "\nNEW NAME:\t";
                            getline(cin, name);
                            modify->setName(name);
                            break;
                        case 2: // 3.2 CHANGE YEAR
                            cout << "\nNEW YEAR:\t";
                            cin >> year;
                            modify->setYear(year);
                            break;
                        case 3: // 3.3 CHANGE RIDE TYPE
                            cout << "\nNEW TYPE:\t";
                            getline(cin, type);
                            modify->setType(type);
                            break;
                        case 4: // 3.4 CHANGE ROW SIZE
                            cout << "\nNEW ROW SIZE:\t";
                            cin >> rowSize;
                            modify->getCart()->setRowSize(rowSize);
                            break;
                        case 5: // 3.5 CHANGE ROW COUNT
                            cout << "\nNEW ROWS:\t";
                            cin >> rows;
                            modify->getCart()->setRows(rows);
                            break;
                        case 6: // 3.6 CHANGE CART MOUNT TYPE
                            cout << "\nNEW MOUNT:\t";
                            getline(cin, mountType);
                            modify->getCart()->setType(mountType);
                            break;
                        case 7: // 3.7 CHANGE COLOR
                            cout << "\nNEW COLOR:\t";
                            getline(cin, color);
                            modify->getCart()->setColor(color);
                            break;
                        case 8: // 3.8 ROW OPERATIONS EDITOR
                            cout << "\nCURRENT ROW STATUS:" << endl;
                            for (int i = 0; i < modify->getCart()->getRows(); i++) {
                                cout << "\t" << i + 1 << ".\t";
                                for (int j = 0; j < modify->getCart()->getRowSize(); j++) {
                                    // cout << char(177 + (42 * (modify->getCart()->isRowOperational(i)))) << " ";
                                    if (modify->getCart()->isRowOperational(i)) cout << "\033[42m  \033[0m ";
                                    else cout << "\033[41m  \033[0m ";
                                    
                                }
                                cout << endl;
                            }
                            cout << "\t0. CANCEL" << endl;
                            cout << "\nWhich Row do you want to modify?\nCHOICE: ";
                            cin >> choice;
                            while (choice < 0 || choice > modify->getCart()->getRows()) {
                                cout << "invalid choice. please enter a number between 0 and " << modify->getCart()->getRows() << "." << endl;
                                cout << "CHOICE: ";
                                cin >> choice;
                            }
                            if (choice == 0) break;
                            cout << "\nIs this row Operational? (y/n):  ";
                            cin >> input;
                            while (toupper(input) != 'Y' && toupper(input) != 'N') {
                                cout << "invalid input. please enter a \'y\' or \'n\'\nCHOICE: ";
                                cin >> input;
                            }
                            modify->getCart()->setRowStatus(choice - 1, toupper(input) == 'Y');
                            modify->setCap();
                            break;
                        default: // 3.0 CANCEL
                            break;
                    }
                }
                break;
            case 4: // 4. PRINT RIDE(S)
                cout << "\n\nPrint Menu" << endl;
                cout << "\t1. Print One Ride\n\t2. Print All Rides\n\t3. Print To File\n\t0. Cancel\nCHOICE: ";
                cin >> choice;
                while (choice < 0 || choice > 3) {
                    cout << "invalid entry, please enter a number between 0 and 3" << endl;
                    cin >> choice;
                }

                switch (choice) {
                    case 1: // 4.1 PRINT ONE RIDE
                        cout << "\n\nWhich Ride should be Printed:" << endl;
                        for (int i = 0; i < myPark->getRideCount(); i++) {
                            cout << "\t" << i + 1 << ". " << myPark->getRide(i)->getName() << endl;
                        }
                        cout << "\t0. Cancel" << endl;
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
                    case 3: // 4.3 PRINT TO FILE
                        cout << "\n\nWhat filename should the park be printed to? (example.txt)" << endl;
                        cin.ignore();
                        getline(cin, filename);
                        f.open(filename);
                        if (f.good()) {
                            cout << "\nFilename \"" << filename << "\" already exists, continuing will override the current file.\n\n Do you want to continue? (y/n): ";
                            cin >> input;
                            while (toupper(input) != 'Y' && toupper(input) != 'N') {
                                cout << "invalid input. please enter a \'y\' or \'n\'\nCHOICE: ";
                                cin >> input;
                            }
                            if (toupper(input) == 'N') break;
                        }
                        f.close();
                        outfile.open(filename);
                        outfile << "AMUSEMENT PARK RIDE LIST:" << endl;
                        myPark->printToFile(outfile);
                        outfile.close();
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

    cout << "\n\n********** GOODBYE! **********\n\n";
    
    delete myPark;

    return 0;
}