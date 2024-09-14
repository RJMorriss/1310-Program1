# 1310 Program 1: Amusement Park Administration
An introductory program into utilizing git and group programming

This program will represent an amusement park, The park will contain a series of attractions, each with its own unique set of attributes 

## Program Flow
The program will operate using a user-input navigated menu in the terminal. The user will be prompted with a set of options all with an indicated selector to allow the user to interact with their Park through the terminal input.

## Role Breakdown
### Navigator-Driver Pair Programming
Our group has chosen to take a pair programming approach to this program, we've divided ourselves into two subgroups where each group will tackle two major aspects of the project
#### Group 1
**Bryce and Everett**
Tasks:
* Program Driver
    * Driver.cpp
* Park Class
    * Park.cpp
    * Park.h

#### Group 2
**Lloyd and Robert**
Tasks:
* Ride Class
    * Ride.cpp
    * Ride.h
* Cart Class
    * Cart.cpp
    * Cart.h

## Classes
### Storage Class (Park Class)
This will represent the Amusement Park itself, all of the parks rides will be stored in an array within the class
#### Attributes
* Private
    * Ride** rideArr
        * A pointer to an array of ride pointers
        * default size of 1
    * int size
        * current size of rideArr
        * default 1

#### Storage Class Functions
- Private
    - void arrSizeUp(int)
        - Called after a ride is created and added to the ride array but array is at max capacity
        - Pass in the current size of the Ride array
        - dynamically allocate a new array with twice the size
        - update the size variable
        - add all elements from the current array to the new array
        - delete current array
        - set the new array to the class attribute
    - void arrSizeDown(int)
        - Called after a ride is deleted from the Ride Array which lowers the size to equal or below half capacity
        - Pass in the current size of the Ride array
        - dynamically allocate a new array with half the size
            - lower limit of size 1
        - update the size variable
        - add all elements from the current array to the new array
        - delete current array
        - set the new array to the class attribute
    - void setSize(int)
        - Sets the size attribute to parameter
- Public
    - Park()
        - Constructor for the Park class
        - Initializes the Ride array to a size of 2
    - ~Park()
        - Destructor for the Park class
        - deletes all Rides in the Ride array, the Ride array, and the park itself
    - int getSize()
        - Returns the size of rideArr

### Data Class (Ride Class)
This class will represents a ride, the ride will contain a series of information about themselves describing a variety of attributes
#### Attributes:
* Private
    * string name
        * Name of the Ride
        * default ""
    * int capacity
        * Maximum capacity of the Ride
        * default 1
    * int year
        * Year of the Ride's creation
        * default 1
    * string type
        * The type of Ride of the object (i.e. Thrill, Coaster, Carnival, etc.)
        * default ""
    * Cart* cart
        * A pointer to a Cart object that represents the Ride Passenger Cart
        * default Cart()

#### Data Class Functions
- Public
    - Ride()
        - Default Ride constructor
        - Initializes the Ride object and defaults all attribute values
    - Ride(string, int, int, string, Cart*)
        - Overloaded Ride constructor
        - Initializes the Ride object and sets the attribute values based on the parameters
    - ~Ride()
        - Ride destructor
        - deletes the Ride's Cart pointer and the Ride itself
    - string getName()
        - Returns the name of the Ride
    - void setName(string)
        - Sets the name of the Ride to the parameter
    - int getCap()
        - Returns the capacity of the Ride
    - void setCap(int)
        - Sets the capacity of the Ride to the parameter
    - int getYear()
        - Returns the year of creation of the Ride
    - void setYear(string)
        - Sets the year of the Ride to the parameter
    - string getClass()
        - Returns the class of the Ride
    - void setClass(string)
        - Sets the class of the Ride to the parameter
    - Cart* getCart()
        - Returns a pointer to the Ride's Cart object
    - void setCart(Cart*)
        - Set the Ride's Cart to the parameter

### Other Class (Cart Class)
This class will store information about a passenger cart for a specific ride
#### Attributes 
* Private
    * int rowSize
        * Amount of seats in each row
        * default 1
    * int rows
        * Amount of rows in the cart
        * default 1
    * bool mountType
        * Stores how the cart is mounted to the Ride
            * True for Over (Cart sits on top of the ride rail)
            * False for Under (top of Cart is attached to the bottom of the ride rail)
        * default True
    * string color
        * Color of the cart
        * default ""
    * bool* rowOperation
        * pointer to boolean area with size equal to the number of rows
        * True/False value for each row
            * True means operational row
            * False mean non-operational row
        * default size 1
        * default True
#### Other Class Functions
- Private
    - void updateOperationalArr(int)
        - Called by the setRows function
        - dynamically allocate a new boolean area with the given size
            - if smaller than current rowOperation array 
                - populates the new arr with the first "x" elements of the current array where "x" is the given int
            - if bigger than current rowOperation array 
                - populates the first "y" elements of the new array with the current array where "y" is the size of the current array
                - initializes remaining elements to True
        - Delete current array
        - Set new array to rowOperation attribute
            
- Public
    - Cart()
        - Default constructor for the Cart object
        - Initializes the Class object and defaults all attribute values
    - Cart(int, int, bool, string)
        - Overloaded constructor for the Cart object
        - Initializes the Cart object and sets the attribute values based on the parameter
    - ~Cart()
        - Destructor for the Cart object
        - Deletes the Cart itself
    - int getRowSize()
        - Returns the amount of seats in each row
    - void setRowSize(int)
        - Seta the amount of seats in each row
    - int getRows()
        - Returns the number of rows in the cart
    - void setRows(int) 
        - Seta the number of rows in the cart
        - Update size of rowOperation array
    - bool getType()
        - Returns the mounting type of the cart
    - void setType(bool)
        - Sets the mounting type of the cart
    - string getColor()
        - Returns the color of the cart
    - void setColor(string)
        - Sets the color of the cart
    - bool isRowOperational(int) 
        - Returns a boolean value for the operational status of the row at a given index
    - void setRowStatus(int, bool)
        - Sets the operation status of a row at a given index to the given value
    - int getCurrentCapacity(void)
        - Returns the maximum capacity of the Cart based on row size * number of operational rows
