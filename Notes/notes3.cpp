#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    /* 
CLASSES (part one)
    foundation of object oriented programming
    All C++ data types have the following defined:
    • The amount of memory required
    • The layout of the memory, what to store and where
    • The operators used to modify the object
    • Member functions
    • Attributes initialization
    • Whether and how to copy and move the object

    in a class:
    variables
    - class attributes
    - specify data stored
    - defined memory allocation
    functions
    - class methods
    - Specify operations the class can perform
    - Class function can only be executed from a class (regular functions can be run everywhere)

    classes require interfaces(prototype):
    - interface classes with readability in mind
    - define functions within a class as
        void Car::start(){}
    - Functions in a class can use any variable or function within that class inside of itself
    */

   class Car 
   {
    string color;
    float current_speed;
    int mileage;
  public:
    void start();
    void accelerate();
    void turn();
    void stop();
   };

   void Car::start(){/*define function*/}

   /* 
HEADER FILE VS SOURCE CODE

   Headers:
   [class name].h or [class name].hpp

   Implementation:
   [class name].cpp

   Typically, there's always a main.cpp, where all code runs from

   FOR HEADERS
   To make sure class is only defined once:
   AT TOP
        #ifndef [class name]_H //this does not have to be the name, just a unique class identifier 
        #define [class name]_H
    AT BOTTOM
        #endif // STUDENT_H

    FOR IMPLEMENTATION
    Make sure to include
    AT TOP
        #include "[class name].h"
        NEEDED IN MAIN FUNCTION, OR WHEREVER CLASS IS USED OR DEFINED

NAMESPSACE VS CLASS
    - namespaces avoid naming collisions
    - CLASSES defined OUTSIDE a namespace (in the void) is BAD, always use classes in a namespace
    
    
ACCESS SPECIFIERS
    - Public: can be accessed outside of class
    - Private: can only be accessed by code inside the class (DEFAULT)
    - Protected: can be accessed by derived classes only (u dont know what this is yet)

    MUTATORS AND ACCESSORS
    - when something is private,it will be inaccessable, even when #include is used
    - to allow access, create access role
    void Class::setVariable(x,y,z)
    {
        if (Class:AccessRole == "Admin")
        {
            //code
        }
    }
    void Class::see/getVariable(x,y,z)
    {
        //code (no parameters)
    }

    !!>> where the functions getVariable and setVariable, are public access within Class
    
   CONSTRUCTOR
   - Function, usually with same name as class, that initializes certain variables
   - Useful for setting default variables/conditional variables
        :defaults are set within the header file, when initializing the constructor
            Account(string accountName, float initialBalance=0.0);
    > only set val at time of installation (object creation)
    > can't overwrite existing values
    > only triggered once
   SETTER
   - similar to constructor, but with arrays
        > set value any time
        > overwrite vlaues
        > can be triggered repearedly (looped)
    DESTRUCTOR
    function that
    - When the object goes out of scope, the object will be destructed.
    - Function ends
    - Program ends
    - Loop ends
        Account::~Account(){}
   - If we do not write our own destructor in class, compiler will create a
        default destructor for us.
    - The default destructor will delete local attributes owned by the class
    - The default destructor won’t release memory. When a class contains a
        pointer to memory allocated in class, we should write a destructor to
        release memory before the class instance is destroyed. This must be
        done to avoid memory leak
    FRIEND FUNCTION
    FRIEND CLASSES
    CONST
    TIME CLASS
    CONST GETTER
    THIS POINTER
    CASCADED FUNCTION CALL
    DEFERENCE THIS
    STATIC MEMBERS
    TEMPLATES WITH CLASSES

    */

    return 0;
}