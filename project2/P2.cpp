/* Annette van Wyk -- Project 2*/

//Given raw input, (numbers), parse meaning
//Given D.Va's power, and enemies power, calculate what D.Va needs to win

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


using namespace std; 

//PROTOTYPES
float matrix_power(int bots[], int size, float boss);
void load_dva(float& defaultpower, float& requiredpower);
void load_dva(int& defaultmisnum, float& reqmispower);
template <typename T>
T single_missile_power(T botpower);

//PROCESSING
int main()
{
    //variables
    int numbots=0;
    float bossdmg=0;
    int missilesnum=0;
    float defpower=0;
    float matrixPowerRequired=0;
    float missilePowerRequired=0;

    //read combat info

    ifstream combatinfo;
    combatinfo.open("combat.txt"); //open file
    if (combatinfo.fail()) //logic to check fail 
    {
        cout << "Failed to open file." << endl; 
        return 0;
    } 

    combatinfo >> numbots;
    int botsdmg[numbots]; 
    for (int i=0; i < numbots; i++)
    {
        combatinfo >> botsdmg[i];
    }

    combatinfo >> bossdmg;
    combatinfo >> missilesnum;
    combatinfo >> defpower;

    combatinfo.close();

    //STEP 1: Calculate how much power mech needs

        //mech defense

    matrixPowerRequired = matrix_power(botsdmg, numbots, bossdmg);

        //micro missiles
    
        for (int i=0; i < numbots; i++)
    {
        missilePowerRequired += single_missile_power(botsdmg[i]);
    }
    
    missilePowerRequired += single_missile_power(bossdmg);

    //STEP 2: Load mech with required power

    load_dva(defpower, matrixPowerRequired);
    load_dva(missilesnum, missilePowerRequired);

    //STEP 3: Pre-combat report

    ofstream combatreport;
    combatreport.open("report.txt");
    if (combatreport.fail()) //logic to check fail 
    {
        cout << "Failed to open file." << endl; 
        return 0;
    } 
    combatreport << "D.Va's Combat Report \nCombat with " << numbots << " enemy bots, and one enemy boss with power " << bossdmg << ".\nLoaded mech with " << missilesnum << " micro missiles, and the defense matrix with power " << defpower << ".\nReady for combat!" << endl;
    combatreport.close();

    return 0;
}

//FUNCTIONS

//calc total dmg of bots
float matrix_power(int bots[], int size, float boss)
{
    float total=0;

    for (int i=0; i < size; i++)
    {
        total = total + bots[i];
    }

    total = total + boss;
    
    return total;
}

//calc power needed per missile
template <typename T>
T single_missile_power(T botpower)
{
    if (botpower <= 15)
    {
        return botpower*3;
    } 
    else
    {
        return botpower*5;
    }
}

//load matrix
void load_dva(float& defaultpower, float& requiredpower)
{
    if (defaultpower < requiredpower)
    {

        defaultpower=requiredpower;
        return;

    } else {return;}
}

//load missiles
void load_dva(int& defaultmisnum, float& reqmispower)
{
    float rawneeded=0;
    int needed=0;
    rawneeded = reqmispower/30;
    needed=ceil(rawneeded);

    if (defaultmisnum < needed)
    {

        defaultmisnum = needed; 
        return;

    } else {return;}
}

/*
TESTS

test 1 combat report:

D.Va's Combat Report 
Combat with 5 enemy bots, and one enemy boss with power 87.15.
Loaded mech with 19 micro missiles, and the defense matrix with power 127.15.
Ready for combat!

test 2 combat report:

D.Va's Combat Report 
Combat with 8 enemy bots, and one enemy boss with power 127.15.
Loaded mech with 53 micro missiles, and the defense matrix with power 327.15.
Ready for combat!

test 3 combat report:

D.Va's Combat Report 
Combat with 1 enemy bots, and one enemy boss with power 27.15.
Loaded mech with 8 micro missiles, and the defense matrix with power 100.
Ready for combat!

*/