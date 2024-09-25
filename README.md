# CSC 1310 Program 1: Amusement Park Administration
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
    * int rideCount
        * Count of rides in the park
        * default 0

#### Storage Class Functions
- Private
    - void arrSizeModify(bool)
        - Called automatically by the addRide and removeRide functions when the ridecount is either equal to the Ride Array size or less than half the Ride Array size
        - Update the size attribute variable
            - Double for a size increase
            - Half for a size decrease
        - Dynamically allocate a new array with the new size with a lower limit of size 1
        - add all elements from the current array within the applicable range to the new array
        - delete the current array
        - set the new array to the class attribute
        - boolean parameter
            - true for a size up
            - false for a size down
- Public
    - Park()
        - Constructor for the Park class
        - Initializes the Ride array to a size of 1
    - ~Park()
        - Destructor for the Park class
        - deletes all Rides in the Ride array, the Ride array, and the park itself
    - Ride* getRide(int)
        - Returns the Ride pointer at the given index in the Ride array
    - int getRideCount()
        - Returns the value of the rideCount attribute variable
    - int getRideCount()
        - Returns the current value of the rideCount attribute variable
    - int getSize()
        - Returns the size of rideArr
    - void setSize(int)
        - Sets the size attribute to parameter
    - void addRide()
        - Add a default Ride to the rideArr using the default Ride constructor
    - void addRide(string, int, string, Cart*)
        - Add a custom ride using the first overloaded Ride constructor
    - void addRide(string, int, string, int, int, bool, string)
        - Add a custom ride using the secodn overloaded Ride constructor and overloaded Cart constructor
    - void removeRide(int)
        - Remove the ride at the specified index in the rideArr
        - Move all further rides down
        - Update rideCount
    - void printRides()
        - Loops through all rides in the rideArr
            - Prints a numerical identifier
            - Calls the printRide member function on each ride
    - void printRides()
        - Loops through the rideArr and calls the printRide() member function on each Ride

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
    - Ride(string, int, string, Cart*)
        - Overloaded Ride constructor
        - Initializes the Ride object and sets the attribute values based on the parameters
    - Ride(string, int, string, int, int, bool, string)
        - Second overloaded Ride constructor
    - ~Ride()
        - Ride destructor
        - deletes the Ride's Cart pointer and the Ride itself
    - string getName()
        - Returns the name of the Ride
    - int getCap()
        - Returns the capacity of the Ride
    - int getYear()
        - Returns the year of creation of the Ride
    - string getType()
        - Returns the type of the Ride
    - Cart* getCart()
        - Returns a pointer to the Ride's Cart object
    - void setName(string)
        - Sets the name of the Ride to the parameter
    - void setCap()
        - Sets the capacity of the Ride using the Cart getCurrentCapacity() function
    - void setYear(int)
        - Sets the year of the Ride to the parameter
    - void setType(string)
        - Sets the type of the Ride to the parameter
    - void setCart(Cart*)
        - Set the Ride's Cart to the parameter
    - void printRide() 
        - Prints all the rides attributes in a neat, readable, format to the console
        - Calls the printCart member function on its Cart* attribute
    - void printRide()
        - Prints a formatted description of the member variables of the Ride object to the console
        - Calls the printCart member function of its Cart object

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
    * string mountType
        * Stores how the cart is mounted to the Ride
        * defualt ""
    * string color
        * Color of the cart
        * default ""
    * bool* rowOperationArr
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
    - int getRows()
        - Returns the number of rows in the cart
    - string getType()
        - Returns the mounting type of the cart
    - string getColor()
        - Returns the color of the cart
    - bool isRowOperational(int) 
        - Returns a boolean value for the operational status of the row at a given index
    - int getCurrentCapacity()
        - Returns the maximum capacity of the Cart based on row size * number of operational rows
    - void setRowSize(int)
        - Sets the amount of seats in each row
    - void setRows(int) 
        - Seta the number of rows in the cart
        - Update size of rowOperation array
    - void setType(bool)
        - Sets the mounting type of the cart
    - void setColor(string)
        - Sets the color of the cart
    - void setRowStatus(int, bool)
        - Sets the operation status of a row at a given index to the given value
    - int getCurrentCapacity()
        - Returns the maximum capacity of the Cart based on row size * number of operational rows
    - void printCart()
        - Prints a formatted description of the member variables of the Cart object to the console
