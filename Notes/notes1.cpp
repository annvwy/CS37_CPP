#include <iostream>
#include <iomanip>


using namespace std;
    //to access other namespace in this use "[spacename]::cout <<"

    int main(){
//review
        //i++ == i=i+1
        //i+=b == i=i+b
        // != means not equal to
//strings:
    //string [name] =
    //funcs: append, compare, get length, indexing
    //append: 
        string first = "John";
        string last = "Doe";
        string full = first+""+last;
    //comparison
        //if condition == compares:
        if (first==last)
            cout <<"First equals last";
    //get size
        int namelength = full.size();
    //indexing
        cout << first[2] << endl; //not desireable
        cout << first.at(2) << endl; // will flag if there's nothing

//iostream:
        //std::cin>>
            //takes information (input)
            //spaces, tabs and newlines are delimiters
                int i; double d; string s; 
                cout << "Enter an integer, double, and string." << endl;
                cin >> i >> d >> s; //stores all from one input
                cin >> i; //only picks up integer
                cin >> d >> s; //cin always same array, when array is empty (does not contain wanted variable), terminal will prompt input
                //when cin finds illegal character, it will usually succesfully store identifiable characters into designated variables
                //cin will always stop at delimiters, extra string info at other side delimiter is stored in cin, no where else
                //to get this extra info:
                    cout << "Enter a string" << endl;
                    getline(cin,s); //get line gets whole line until \n
                //cin.get removes autoprocessing, gets one character at a time
                    cout << "Enter 3 letters" << endl;
                    char letter;
                    for (int i=0; i>3; i++) {
                        letter = cin.get();
                        cout << letter << " ";
                    }
                //cin.ignore(size) to ignore set amount of characters
                int age;
                string name;
                cout << "Enter age then name" << endl;
                cin >> age;
                cin.ignore(2);
                getline(cin, name);
                //ignore is only usually useful when input format is known or repeated
        //end of file marker
            //user hits cntrl z to end terminal prompt
            //end of file marks cin as false
            //getline and EOF
                    string line;
                    while (getline(cin, line)) {
                        cout << "You entered: " << line << endl;
                    }
        //std::cout<<
            //"cout" is print
                 cout << "Fullname:" << full << ".\n";
                // doing below only adds something to cout stream
                cout << "Yo"; //will print at return 0;
            //endl;
                //endl will signal cout stream to print into terminal
                    cout << "Hello" << endl;
                //using endl will help with memory mangement (less memory used for cout stream)
                //using endl for every little print makes program slow
                //balance memory and speed
            //cout followed by cin flushes cout automatically
            //handling one character:
                    //cin.get() gets one character into cin stream
                    //cout.put() puts on character into cout stream
            //different ways to flush
                    cout.flush(); //function that flushes 
                    cout << "Hello" << flush; // flush will clear
            //setprecision:
                    //sets number of slots avaliable
                    //stays throughout
                    double dec=2.4958;
                    double dec1=2345566.34;

                    cout.precision(2); //no fixed means only 2 spots total 
                    cout<<dec1<<endl;
                    cout<<setprecision(2)<< fixed; //2 decimal places
                    cout<<dec1<<endl;
            //width
                    //sets total characters
                    //does not stay, needs to be reassigned
                    //cin.width(number) or cin>>setw(number)
                    //cout.width(number) or cout<<setw(number)
                    //if not enough characters, width will be filled with white space padding
                    //auto puts padding on left, (right justified text)
                    //set left justified
                        //cout << left << setw(number)<< x << endl; 
            //exit program with cntrl c



        return 0;
    }

