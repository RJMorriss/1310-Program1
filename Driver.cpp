
/*
#include<iostream>
#include"Park.h"
#include"Cart.h"
#include"Ride.h"

using namespace std;

int main()
{
    int switchChoice;
    Park * myPark = new Park();

    string rideName, rideType, rideCart, rideColor;
    int rideYear, numRows, rowSize;
    int sub1Choice, printChoice, sub2Choice, sub3Choice, sub4Choice, modChoice;

    do{
        cout << "************************************************" << endl;
        cout << "AMUSEMENT PARK MENU" << endl;
        cout << "What would you like to do? (Enter 1-5)" << endl;
        cout << "Option 1: Print Rides" << endl;
        cout << "Option 2: Delete Rides" << endl;
        cout << "Option 3: Add Rides" << endl;
        cout << "Option 4: Edit Rides" << endl;
        cout << "Option 5: End Program" << endl;

        switch(switchChoice)
        {
            case 1:
                cout << "Print Submenu" << endl;
                cout << "Option 1: Print One\nOption 2: Print All" << endl;
                cin >> sub1Choice;
                while(sub1Choice<0 || sub1Choice>2)
                {
                    cout << "Please Enter a Valid Input" << endl;
                    cin >> sub1Choice;
                }
                switch(sub1Choice)
                {
                    //print Rides
                    case 1:
                        cout << "WHICH RIDE DO YOU WANT TO PRINT?" << endl;
                        for(int i=0; i<myPark->getRideCount(); i++)
                        {
                            cout << i+1 << ".\t" << myPark->getRide(i)->getName() << endl;
                        }
                        cin >> printChoice;
                        while(printChoice<0 || printChoice>myPark->getRideCount())
                        {
                            cout << "Please Enter Valid Input(1-" << myPark->getRideCount() << ")\nChoice: ";
                            cin >> printChoice;
                        }
                        myPark->getRide(printChoice-1)->printRide();
                        break;
                    case 2:
                        myPark->printRides();
                        break;
                }
                break;

            // Ride Delete
            case 2:
                cout << "WHICH RIDE WOULD YOU LIKE TO REMOVE?";
                for(int i=0; i<myPark->getRideCount(); i++)
                {
                    cout << i+1 << ".\t" << myPark->getRide(i)->getName() << endl;
                }
                cout << "0.\tCancel" << endl;
                cin >> sub2Choice;
                while(sub2Choice<0 || sub2Choice>myPark->getRideCount())
                {
                    cout << "Please Enter Valid Input(1-" << myPark->getRideCount() << ")\nChoice: ";
                    cin >> sub2Choice;
                }
                cout << "Ride " << myPark->getRide(sub2Choice)->getName() << " was successfully deleted" << endl;
                myPark->removeRide(sub2Choice-1);
                break;
            //Add rides
            case 3:
                cout << "\n*****ADD A RIDE*****\n";
                cout << "1.\tAdd Ride Without A Cart\n2.\tAdd A Full Ride\n0.\tCancel\n  ENTER YOUR CHOICE: ";
                cin >> sub3Choice;
                while (sub3Choice < 0 || sub3Choice > 2) 
                {
                    cout << "invalid entry, please enter a number between 0 and 3" << endl;
                    cin >> sub3Choice;
                }
                if (sub3Choice == 1){
                    cout << "******Good Choice*******";
                    cin.ignore();
                    cout << "Ride Name: \t\t";
                    getline(cin, rideName);
                    cin.ignore();
                    cout << "Ride Year: \t\t";
                    cin >> rideYear;
                    cin.ignore();
                    cout << "Ride Type: \t\t";
                    getline(cin, rideType);

                    myPark->addRide(rideName, rideYear, rideType);
                    cout << "*****RIDE SUCCESSFULLY CREATED*****" << endl;
                }
                else if (sub3Choice == 2){
                    cout << "******Good Choice*******";
                    cin.ignore();
                    cout << "Ride Name: \t\t";
                    getline(cin, rideName);
                    cin.ignore();
                    cout << "Ride Year: \t\t";
                    cin >> rideYear;
                    cin.ignore();
                    cout << "Ride Type: \t\t";
                    getline(cin, rideType);
                    cin.ignore();
                    cout << "Cart Type: \t\t";
                    getline(cin, rideType);
                    cout << "How Long Is A Row of Seats: \t\t";
                    cin >> rowSize;
                    cout << "How Many Rows In a Cart?: \t\t";
                    cin >> numRows;
                    cin.ignore();
                    cout << "Cart Color: \t\t";
                    getline(cin, rideColor);

                    myPark->addRide(rideName, rideYear, rideType, rowSize, numRows, rideCart, rideColor);
                    cout << "*****RIDE SUCCESSFULLY CREATED*****" << endl;

                }

                break;

            //Edit Rides
            case 4:
                cout << "*****WHICH RIDE WOULD YOU LIKE TO MODIFY?*****" << endl;
                for(int i=0; i<myPark->getRideCount(); i++)
                {
                    cout << i+1 << ".\t" << myPark->getRide(i)->getName() << endl;
                }
                cout << "0.\tCancel" << endl;

                cin >> sub4Choice;
                while(sub4Choice<0 || sub4Choice>myPark->getRideCount())
                {
                    cout << "Please Enter Valid Input(1-" << myPark->getRideCount() << ")\nChoice: ";
                    cin >> sub4Choice;
                }
                //Add function to test if ride has cart. If ride has cart give user option to modify just cart, just ride, or both.
                cout << "WHICH PART OF THE RIDE WOULD YOU LIKE TO MODIFY?" << endl << endl;
                cout << "1.\t\tModify Name\n2.\t\tModfy Year\n3.\t\tModify Type\n4.\t\tModify Cart Type\n";
                cout << "5.\t\tModify Color\n6.\t\tModify Number of Rows\n7.\t\tModify Row Size\n0.\t\tCancel" << endl;
                cin >> modChoice;
                while(modChoice<0 || modChoice>7)
                {
                    cout << "Please Enter Valid Input (0-7)" << endl;
                    cin >> modChoice;
                }
                
                switch(modChoice)
                {
                    case 1:
                        cout << "Please Enter the New Name: ";
                        getline(cin, rideName);
                        modify->setName(rideName);
                        break;
                    case 2:
                        cout << "Please Enter the New Year: ";
                        cin >> rideYear;
                        modify->setYear(rideYear);
                        break;
                    case 3:
                        cout << "Please Enter the New Type: ";
                        getline(cin, rideType);
                        modify->setType(rideType);
                        break;
                    case 4:
                        cout << "Please Enter the New Cart Type: ";
                        getline(cin, rideCart);
                        modify->getCart()->setType(rideCart);
                        break;
                    case 5:
                        cout << "Please Enter the New Color: ";
                        getline(cin, rideColor);
                        modify->getCart()->setColor(rideColor);
                        break;
                    case 6:
                        cout << "Please Enter the New Number of Rows: ";
                        cin >> numRows;
                        modify->getCart()->setRows(numRows);
                        break;
                    case 7:
                        cout << "Please Enter the New Size of the Rows: ";
                        cin >> rowSize;
                        modify->getCart()->setRowSize(rowSize);
                        break;
                }
                break;
        
        }
    }while(switchChoice != 5);   
    cout << "\n\n*****GOODBYE! :) *****\n\n";
    return 0;
}
*/