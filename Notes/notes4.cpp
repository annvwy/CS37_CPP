#include <iostream>
#include <iomanip>

/*
CLASSES:
- defines what it means to be something
- each "OBJECTS" is an iteration of that class (individual instances of that class)

BankAccount account1;
account1.name= "name"
account1.balance = 3000;

and there can be account2,3,4 etc

- member functions are "methods" and variables as "attributes"

CONSTRUCTORS:
- setup member function (method)
- function with the same name as class, is called automatically when object is made

NORMAL OBJECT CREATION
class Cat{};
Cat cat1; //calls constructor, uses default values
SPECIFIED CREATION
Cat cat2("Salem", "Tuxedo", "Bird toy"); // calls constructor and uses arguments in consutrction function

!! DEFAULT arguments can be set in constructor argument slots 
Cat(string n, string c, string ft = "Ball of Yarn"){xyz};//where ball of yarn is the default

FRIEND FUNCTIONS:
- given access to protected and private members and methods
- DECLARED INSIDE CLASS, DEFINED OUTSIDE OF CLASS AND MAIN
- pass by REFERENCE to modify private/protected members
- can be friend to MULTIPLE classes 
- CAN BE a member of a class and a friend function of another class at the same time

DECLARATION
friend void double_x(MyClass &object); //declaration IN CLASS but NOT under private OR public, stand alone (not NECCESARY, can put anywhere)

DEFINITION
void double_x(MyClass &object)
{
	object.x *=2
}

CALLING (in main)
double_x(myobject);

FRIEND IN TWO CLASSES 
class Revenue
{
	friend bool profit(Revenue rev, Costs cos);

private:
	int revenue;
public:
	Revenue(int revenue) : revenue(revenue);
};

class Costs
{
friend bool profit(Revenue rev, Costs cos);

private:
	int costs;
public:
	Costs(int costs) : costs(costs) {}
};

bool profit(Revenue rev, Costs cos)
{
	if(rev.revenue > cos.costs) return true;
	else return false;
}

DESTRUCTORS
- destroy objects/clean up
- class name with ~ "~[class name]"
- auto runs at end of program
- 

STATIC MEMBER FUNCTIONS
- allows us to manipulate static member variables (static int/string/etc [name])
- every object in the class SHARE the static variable, they don't each have their own (variable associated with class not per object)
- initialize static member variables outside of class AND outside of main (set it to 0 or defualt)
- static functions (static int/whatever [name](){}) allow us to access an maniuplate static variables
- static functions are usually getters
- static function can also be made to increment static variable (private static, more secure)
- can access static thru object2.functionname but is better to use class::functionname
- static function can't access specific object variables
- static functions can't use this keyword

	THIS KEYWORD
	- NON-STATIC MEMBERS
	- points to object specific instance of a variable
	- "this" in a class function, serves as the MEMORY ADDRESS for the current object
	example:
	class student
	public:
	somefunction(){cout << this << endl;} //prints the memory address of this itteration of student

	and 

	int main(){
	student student1()
	cout << &student1 << endl;} //print student 1

	will print the exact same memory address 

this use cases:
	when class has variables (for example name, age) that are set in constructor, and constructor takes variables with the same name (example: name, age)
	then constructor will only work when structured as:
		Student(string name, int age)
		{
		this -> name = name;
		this -> age = age;
		}
		//basically saying THIS version of member variable "name/age" is equal to name/age

	can also be used to call member functions in another member function
	- for example, saying use THIS version of a function then output THAT variable it give us

	passing a this pointer to a function that takes a pointer as a parameter, so that that fucntion can use object specific information
		void function1(Class *pointer) //OUTSIDE OF MAIN AND CLASS
		{
			cout << pointer->variable << " " << pointer->variable2 << endl;
		}
	INSIDE CLASS
		void function2()
		{
		function1(this);
		}

	method chaining: setting multiple member variables of a student variable using setter methods in a chain
	IN MAIN
		object1.setname("John").setage(23);
	IN CLASS
		Student& setname(string name)
		{
			this->name = name;
			return *this;//star dereferences pointer, with ampersand for student, implies returning a reference to this student object
		}

		Student& setage(int age)
		{
			this->age = age;
			return *this;//star dereferences pointer, with ampersand for student, implies returning a reference to this student object
		}
	

OPERATOR OVERLOADING
- cannot make new ones, but can overwrite old ones
- cannot touch member operator(.), pointer to member(.star), scope operator(::), conditional operator (?)

Class_name operator+/-/=/wtvr(const Class_name &numA)
{
	return Class_name(this->n +0)
}

**Ways to overload**
Binary Operators
1. When left operand is an object of the class (s1 < s2)
▪ Non-static member function with one parameter
▪ Non-member function with two parameters
2. When left operand is not an object of the class(cout << s1)
▪ Non-member function with two parameters
▪ Unary Operators
▪ Non-static member function with no parameter
▪ Non-member function with one parameter




Member function overloading

vs

Non-member overloading
- 


To give private information: friend function

--
Member function
- comparison=bool
- not changing anything=constant

Object parameter
- not changing (const &+
- changing (&)

--
Cin and Cout;; allow cascaded function call

INHERITANCE: Implementing multiple classes that are so similar, they absorb each other
- c
- 

DOUBLE INHERITANCE
StudentAccount : public Student , public Account
- inherits student first, then account
- constructors go in order of declaration 

BASE CLASS:
- a class that other classes inherit from
DERIVED CLASS:
- inherits and adds new/modifies base class

• Base class: Student  
	• Derived class: GraduateStudent / UndergradStudent  
• Base class: Shape  
	• Derived class: Circle / Triangle / Rectangle / Cube  
• Base class: Account  
	• Derived class: AdminAccount / UserAccount

DON'T INHERIT: 
- constructors, 
- destructors, and 
- assignment operator overloading

BUT has access to CALL constructor, destructor

**Public inheritance** will give class B access to ONLY public and protected members of class A (private is for class A and class A only)
- DESPITE THIS, GradStudent will 'have' all private things, but only student class can access them (think jewelry box with some jewels locked in tiny boxes, still inside the jewlery box but inaccesible)

PROTECTED ACCESS SPECIFICERS
- made specifically for inheritance
- derived class can access protected members of a base class
- inaccesible to rest of program
- IF "class GradStudent : public Student {" base class is specificed as PUBLIC, protected member of base BECOME protected members of derived thus second derivative can access protected members

INHERITANCE OPERATOR (:)
	class GradStudent : public Student {
		public:
			GradStudent(string, int, int, int, int); //constructor since it's not inherited
			string grade(); //overriding Student::grade
		private:
			int researchCredit; //new variable/object
		}
CALLING BASE CLASS THROUGH DERIVED CLASS
	string GradStudent::grade()
	{
		string testPass= Student::grade();
		if (testPass == "Pass" && this->research > 70) 
		{
			return "Pass.";
		} 
		else
		{
			return "Fail";
		}
	}
Derived constructor can call base constructor!!!
- CALLING BASE CONSTRUCTOR HASSS TO BE THE FIRST THING IN DERIVED CONSTRUCTOR
- destructor runs in reverse order of constructor 
- 

POLYMORPHISM INTRO
- work with a bunch of classes
- family tree of inheritance (FAMILY OF CLASSES)
- 

CLASS POINTERS
BY VALUE
GradStudents("Zen", 95, 86, 92, 69);
s.print();

BY POINTER
GradStudent* ptr = &s
ptr->prnit().

BY REFERENCE
GradStudent& ref=s;
ref.print();

- base class pointer can point to derived BUT derived class pointer cannot point to base class 
- triggers based on what kind of pointer, not based on the pointed to object

WHEN TO USE CLASS POINTERS
- when u want to constrain things (template it too loose)

STATIC BINDING
- making a class pointer binds all functions to pointer
DYNAMIC BINDING
- happens to virtual functions
- Virtual function will be bounded at run time based on the object type instead of the pointer type.
- Thus, virtual function will bind to subclass by pointer, but if there's no overwritten function, then base function is used

VIRTUAL FUNCTIONS
virtual void talk();
- exception to static binding, virtual functions dynamically bind
PURE VIRTUAL FUNCTION
- blueprint for shared function
- REQUIRES that base function is overwritten
virtual void talk() const = 0;
- sometimes there's no foundational base definition of a function, this ensures each derived class has their own

ABSTRACT BASE CLASS
- any pure virtual function having base class is abstract
- abstracts CANNOT exist/function without derivatives

POLYMORPHISM summary
- when there's abstract classes that enforces derived classes to complete definitions so that class pointers execute accurately
	- Class Pointer can take in all inherited classes of Mammal because of Virtual Functions, when m->talk() is triggered, it will trigger based on object
	type by dynamic binding
	- All inherited classes must override the pure virtual function pointed to because theres no definition for function in the base class


INITIALIZATION LIST
	- default for cpp is decleration, definition before initialization 
	- initialization list combines assignment and initialization
	Exception1()
{
	message="hi" //normal
	response = "hello"
};
	vs

	Exception() : message("hi"), response("ok") {};

	- after c++11, can initialize non-static variables at decelartion (header file)
	- after c++17, can initialize static and non-static variables at decleration
	-BUT if you want to use constructor parameters to initialize constant variable, you still need to use init list

EXCEPTION 
	- problem that u do not expect
	- exception handling terminates gracefully
	- without exception handling, program may run incorrectly
	HOW IT WORKS
	- 

	TRY CATCH BLOCK EXCEPTION
	- try: try a function (when this function runs succesfully, do xyz)
	- catch: output explaining exception
	- multiple catch blocks that work in order, with ifs (if this exception matches this catch, run this catch, if not move to next)
	- after explaining catch, you can throw exception to next place
	- CATCH ALL: "catch (...){cout<< "Error." << endl;}" ,, catches all exceptions ,, not recommended unless rethrowing
	CATCHING BY REFERENCE
	- required for polymorphism/exception family

	- print cause of exception with pass by reference for clarity
	





*/