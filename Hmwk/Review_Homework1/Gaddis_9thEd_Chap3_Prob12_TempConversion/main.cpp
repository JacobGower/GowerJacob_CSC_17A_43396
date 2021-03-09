/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose: To Convert Celsius to Fahrenheit
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float degC, //temperature input by user, in Degrees Celsius
          degF; //temperature converted to Degrees Fahrenheit  
    
    //Initialize Variables
    cout<<"Input temperature in Degrees Celsius"<<endl;
    cin>>degC;
    cout<<endl;
    
    
    
    //Map Inputs to Outputs -> Process
    degF=(9.0f/5.0f)*degC+32;

    //Display Inputs/Outputs
    cout<<fixed<<showpoint<<setprecision(2)<<degC<<"° Celsius = ";
    cout<<fixed<<showpoint<<setprecision(2)<<degF<<"° Fahrenheit";
      
    //Exit the Program - Cleanup
    return 0;
}

