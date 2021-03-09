/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose:  To create a function to
 *           convert from Celsius to Fahrenheit and display in a table
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
float celsius (float, float &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float degF, //temperature in Degrees Fahrenheit
          degC; //temperature converted to Degrees Celsius  
    
    //Initialize Variables
    degF=degC=0;
    
    //Map Inputs to Outputs -> Process
    cout<<"Fahrenheit"<<setw(10)<<"Celsius"<<endl;

    //Display Inputs/Outputs
    for (;degF<=20;degF++) {
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<setw(6)<<degF<<"°"<<setw(12)<<celsius (degF,degC)<<endl;
    }
      
    //Exit the Program - Cleanup
    return 0;
}
float celsius (float degF, float &degC) {
    degC=(5.0f/9.0f)*(degF-32.0f);
    return degC;
}

