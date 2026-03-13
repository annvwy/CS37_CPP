#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

int main()
{
/*FILES
    - Persistent storage
    - Files come with end of file markers, no need to insert one
    - When file is opened, file object is maade with a stream association 
        > <fstream> contains of and if stream
        > <ofstream> write files
        > <ifstream> read files
*/

//Opening a file, and adding content
    ofstream myfile; //creates output file stream
    myfile.open("example.txt"); //opens the file named "example.txt"
    myfile << "Hello.\n"; //adds text into the file/ofstream
    myfile.close(); //closes file

/* MODES
    - modes exist in the IOS namespace
        ios::in > use during fstream to classify mode as in
        ios::out > use during fstream to classify mode as out
        ios::binary > 
        ios::ate > sets position at end of the file, default is begining of the file (overwrite)
        ios::app > add new content at end of previous content, without this, default is to overwrite previous content
        ios::trunc > 
    - combine modes with |
*/

//Using modes
    ofstream myfile; 
    myfile.open("example.txt", ios::out | ios::app); //append adds new text after previous text
    myfile << "Goodbye.\n"; 
    myfile.close(); 

//You can open and attach at the same time
    ofstream myfile("example.txt");

/* CHECK FILE
    - When files fails to open, cpp won't tell you
    - myfile.is_open checks if a file is open
    - Use if statements to ensure program only runs when file is open (if file doesnt open, error message and return 0)
    - Or use myfile.fail() that will return true if file failed to open, or failed writing
    - Use if file fails, error message, return 0
    Reasons file might not open:
        don't have access
        directory doesn't exist (folder containing file doesn't exist)
        file doesn't exist
        no disk space
*/

/* CLOSING FILES
    - important for memory management
    - myfile.close();
    - close files when you're DONE using it
    - file will always close at end of program, but if kept open during rest of program, it takes up memory throughout run
*/

/* READ FROM A FILE
    - 
*/

//opening and reading file
    ifstream myfile;
    myfile.open("example.txt");
    string line;
    if (myfile.fail())
    {
    cout << "Failed to open file." << endl;
    }
    myfile >> line; //reads myfile until delimiter and adds to string "line"
    cout << line << endl;
    myfile.close();

//reading file with getline
    ifstream myfile("example.txt");
    string line;
    if (myfile.fail())
    {
    cout << "Failed to open file." << endl;
    }
    getline(myfile, line); //grabs entire line from file
    cout << line << endl;
    myfile.close();

//reading with getline until end of file
    ifstream myfile("example.txt");
    string line;
    if (myfile.fail())
    {
    cout << "Failed to open file." << endl;
    }
    while(getline(myfile, line)) { //grabs lines until EoF
    cout << line << endl;
    }
    myfile.close();

/* QUOTED TEXT
    - some text in files is quoted, there's a way to remove quote marks when reading
    - from <iomanip>
    - quoted(name) identifies read object to be everything within the quotes, then removes quote marks
*/

//Example 
    ifstream myfile("example.txt");
    string name;
    int id;
    if (myfile.fail())
    {
    cout << "Failed to open file." << endl;
    }
    myfile >> id >> quoted(name);
    myfile.close(); 

/* FUNCTIONS
    - specify return type: int/string/float/void/etc [name](parameters){/code here/ return [something];}
    - prototyping: implementation at the top (DO THIS!)
    - parameters in prototype don't even need name
    - function implementation can be in diff file, or even folder
*/

/* PASSING PARAMETERS
    - by value: copy para value into function
        default
        will not change og paramater

        expensive
        but safe (harder to hack)

    - by ref: giving a variable multiple names/points of reference
        int i=3; and int& j = i; just says i is also named j
        function can change original paramater
        void fool(int& x) -- DEFINING function to pass by reference
        
        less memory usage
        not safe, careful how you change it
        cannot be reassigned

    - by pointer: 
        int i = 3; and int* j = &i; j will equal i's memory address
        printing j will print i's memoery address
        printing *j will print the value of i (3)
        modifying *j: j*=j*+2; will modify pointed to value as well 
            j will still equal i's address
            j* will equal 5
            i will equal 5
        j and i are NOT the same thing. 
        fool(&i); -- CALLING the function
        fool(int* x) -- DEFINING the function
            put *x anywhere variable is used in function

        C compatible
        UNSAFEST!! gives access to address 
        flexible: can be changed to point to many different addresses

    POINTERS CAN POINT TO FUNCTIONS:
        - pass function name as parameter to different function

    DIFFERENCE POINTING VS REFERENCE:
        - pass by referene does not take extra memory
        - reference equates two names to one variable
        - pointer creates address varaible to use to point to other variable
*/

/* FUNCTION OVERLOAD
    - can have same name function as long as each has diff # parameters or diff parameter types 
*/

/* INLINE FUNCTIONS
    - Return control: Use return to control when function ends
        in void function, "return;" useable
    - INLINE as function type: 
        "inline void fool(int x){}"
        when fool is called, fool code is copied into main (or into function calling it)
        use when function is small 
        compiler can CHOOSE whether inline is optimal or not
            > INCREASES COMPILING TIME especially if you use too many inlines
            > Every choice (should i inline or not?) takes processing power from compiler
*/
 
/* DEFAULT ARGUMENTS
    - define each parameter in a function to set a "default value"
    - this makes adding parameters optional when calling function
    - giving new parameter overrides default
    - to add last parameter, all parameters before it become required
    - REQUIRE FIRST, DEFUALT LAST
*/

/* TEMPLATES
    - DON'T REPEAT YOURSELF! if code function is repeated, use a function, OR 
    - use a TEMPLATE

    template <typename T>
    T sum(T a, T b)
    {
    return a+b;
    }

    - when calling, will use for function matching exact calling ,then for a template
    - if called variables are int, new function is generated where T will be replaced with int for all T in called function
    - templates are flexible
    - easily hackable

    - CAN HAVE TWO DIFF TYPES IN ONE FUNCTION
    template <typename T, typename U>
    T sum(T a, U b)
    {
    return a+b;
    }
    - type of "U" will be set to variable type passed, same with T
    REMEMBER turning floats into ints, always rounds down (removes .00, regardless of its magnitude)
    - can set type when calling if necessary
    cout<<sum <double, double> (3.5,1)<<endl;

    THEN WHY WOULD I NEED OVERLOADING?
    - when u dont have the same # of parameters, codeblock, or type patterns
*/

/* STANDARD TEMPLATE LIBRARY (STL)
        Algorithms
        - Sorting, searching, partitioning, standard array algorithm, etc
        Containers
        - Vector, list, array, queue, stack, set, map, etc
        Functions
        - Allow us to overload some function operators
        Iterators
        - Allow us to iterate over a sequence of values
    (for this class: we're using
    Arrays: Sort
     )

    ALGORITHMS: 

        Sorting
    sort(array, array + array_size); //array + array_size = index of end of array
    - to calc size of array: sizeof(array) / sizeof(array[0]) //where 0 is index of first variable
    - sorts from smallest to biggest number
    reverse(array, array+array_size); //does same thing from big to small

        Count
    num=count(array, array+array_size, index); //counts how many times this variable occurs in the array

        Copying
    copy_n(where from, how many, where to); //copies array into another array



*/
    return 0;
}