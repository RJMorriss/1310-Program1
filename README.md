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

