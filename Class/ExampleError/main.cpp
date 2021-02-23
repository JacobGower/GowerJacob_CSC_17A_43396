/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To show computers can't add/subtract
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
    short op1,  //Operand 1
            op2,  //Operand 2
            sumRslt;  //Sum of Operand 1 and 2
    
    //Initialize Variables
    op1=30000;
    op2=4000;
    
    //Map Inputs to Outputs -> Process
    sumRslt=op1+op2;
          
    //Display Inputs/Outputs
    cout<<sumRslt<<" = "<<op1<<" + "<<op2<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}

