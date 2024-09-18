#include<iostream>
#include"Park.h"
#include"Cart.h"
#include"Ride.h"

using namespace std;

int main()
{
    int switchChoice;

    cout << "************************************************" << endl;
    cout << "AMUSEMENT PARK MENU" << endl;
    cout << "What would you like to do? (Enter 1-5)" << endl;
    cout << "Option 1: Print Rides" << endl;
    cout << "Option 2: Delete Rides" << endl;
    cout << "Option 3: Add Rides" << endl;
    cout << "Option 4: End Program" << endl;

    do{
        switch(switchChoice)
        {
            case 1:
                cout << "Print Submenu" << endl;
                cout << "Option 1: Print One\nOption 2: Print All" << endl;
                int sub1Choice;
                cin >> sub1Choice;
                while(sub1Choice<0 || sub1Choice>2)
                {
                    cout << "Please Enter a valid Input" << endl;
                    cin >> sub1Choice;
                }
                switch(sub1Choice)
                {
                    case 1:
                        
                        break;
                    case 2:
                        myPark->printRides();
                        break;
                }
                break;
            case 2:
            
                break;
            case 3:
            
                break;
        
        }
    }while(switchChoice != 4);
	
	cout << "\n\n*****GOODBYE! :) *****\n\n";
    return 0;
}