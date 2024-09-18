#include<iostream>
#include"Park.h"
#include"Cart.h"
#include"Ride.h"

using namespace std;

int main()
{
    int switchChoice;

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
                int sub1Choice;
                cin >> sub1Choice;
                while(sub1Choice<0 || sub1Choice>2)
                {
                    cout << "Please Enter a Valid Input" << endl;
                    cin >> sub1Choice;
                }
                switch(sub1Choice)
                {
                    case 1:
                        cout << "WHICH RIDE DO YOU WANT TO PRINT?" << endl;
                        for(int i=0; i<myPark->getRideCount(); i++)
                        {
                            cout << i+1 << ".\t" << myPark->getRide(i)->getName() << endl;
                        }
                        int printChoice;
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
            case 2:
                cout << "WHICH RIDE WOULD YOU LIKE TO REMOVE?";
                for(int i=0; i<myPark->getRideCount(); i++)
                {
                    cout << i+1 << ".\t" << myPark->getRide(i)->getName() << endl;
                }
                cout << "0.\tCancel" << endl;
                int sub2Choice;
                cin >> sub2Choice;
                while(sub2Choice<0 || sub2Choice>myPark->getRideCount())
                {
                    cout << "Please Enter Valid Input(1-" << myPark->getRideCount() << ")\nChoice: ";
                    cin >> sub2Choice;
                }
                cout << "Ride " << myPark->getRide(sub2Choice)->getname << " was successfully deleted" << endl;
                myPark->removeRide(sub2Choice-1);
                break;
            case 3:
                
                break;
            case 4:

                break;
        
        }
    }while(switchChoice != 5);   
    cout << "\n\n*****GOODBYE! :) *****\n\n";
    return 0;
}