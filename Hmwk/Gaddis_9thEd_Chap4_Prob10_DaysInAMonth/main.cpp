/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose:  To Tell the User the Number of days in a given month based on
 *           User input
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    short   month,  //Month number, input by User
             year;  //Year number, input by User
    char  address;  //For referencing the address in the days array
                //Number of days in each month 1-12. 29 at index 0 for leap year
    const char days[]={29,31,28,31,30,31,30,31,31,30,31,30,31};
    
    //Initialize Variables
    month=year=0;
    
    while (month<1||month>12) { //Input Validation for months
        cout<<"Enter a month (1-12): ";
        cin>>month;
        cout<<endl;
        
        if (month<1||month>12) { //Invalid input Message
           cout<<"You must not be using any calendar I've ever heard of."<<endl;
           cout<<"Please enter a number between 1 and 12"<<endl;
        }
        
    }
    //Technically some BC values are Valid, but for simplicity, limit to AD (>0)
    while (year<1) { //Input Validation for years
        cout<<"Enter a year (AD only): ";
        cin>>year;
        cout<<endl;
        if (year<1) { //Invalid input Message
            cout<<"Please enter a valid year."<<endl;
        }
    }
    
    //Map Inputs to Outputs -> Process
    if (month==2) { //Test for Leap Year 
        address=(year%100==0&&year%400==0?0:
                 year%100!=0&&year%4==0?0:2);
                   
    }else {
        address=month;
    }

    //Display Inputs/Outputs
    //Static cast days address value to an int to avoid displaying ASCII value
    cout<<static_cast<int>(days[address])<<" days";
      
    //Exit the Program - Cleanup
    return 0;
}

