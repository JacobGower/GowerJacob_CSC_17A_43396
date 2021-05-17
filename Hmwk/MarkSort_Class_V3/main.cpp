/* //wod Take the Survey
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 6th, 2021, 6:14 PM
 * Purpose:  
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void prntAry(Array &,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=100;
    int perLine=10;
    Array array(size);
    
    //Initialize all known variables
    cout<<"Before Sorting"<<endl;
    prntAry(array,perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    array.markSrt();
    
    //Display the Inputs/Outputs
    cout<<"After Sorting"<<endl;
    prntAry(array,perLine);

    //Clean up the code, close files, deallocate memory, etc....
    
    //Exit stage right
    return 0;
}
void prntAry(Array &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.getSize();i++){
        cout<<a.getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}