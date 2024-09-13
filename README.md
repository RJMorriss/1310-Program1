# 1310-Program1
An introductory program into utilizing git and group programming

This program will represent an amusement park, The park will contain a series of attractions with its own unique set of attributes 

## Classes
### Storage Class (Park Class)
This will represent the Amusement Park itself, all of the parks rides will be stored in an array within the class
#### Attributes
- Ride** rideArr
    - A pointer to an array of ride pointers, will have a default size of 2
- int size
    - current size of rideArr

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
        - update the size variable
        - add all elements from the current array to the new array
        - delete current array
        - set the new array to the class attribute
    - void setSize(int)
        - Sets the size attribute to parameter
- Public
    - Park()
        - Constructor for the Park class, Initilizes the Ride array to a size of 2
    - ~Park()
        - Destructor for the Park class, deletes all Rides in the Ride array, the Ride array, and the park itself
    - int getSize()
        - Returns the size of rideArr

### Data Class (Ride Class)
This class will represents the rides, the ride will contain a series of information about themselves describing a variety of attributes
#### Attributes: 
* string Name
* int Capacity
* int Year of Creation
* string Classification
    * The type of Ride of the object (i.e. Thrill, Coaster, Carnival, etc.)
* Cart* cart
    * A pointer to a Cart object that represents the Ride Passenger Cart

#### Data Class Functions
- Ride()
    - Default Ride contructor, Initializes the Ride object and defaults all attribute values
- Ride(string, int, int, string, Cart*)
    - Overloaded Ride constructor, Initializes the Ride object and sets the attribute values based on the parameters
- ~Ride()
    - Ride destructor, deletes the Ride's Cart pointer and the Ride itself
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

