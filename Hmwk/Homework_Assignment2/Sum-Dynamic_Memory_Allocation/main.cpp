/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 28, 2021, 6:16 PM
 * Purpose:  To Create a parallel array that represents the successive sum of preceding members in the given array
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int *getData(int &);           //Return the array size and the array from the inputs
int *sumAry(const int *,int);  //Return the array with successive sums
void prntAry(const int *,int); //Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int arySize, //Dynamic Array Size Input by User
           *ary, //Dynamic Array
           *sum; //Sum Array
            
    
    //Initialize Variables
    cin>>arySize;
    
    ary=getData(arySize);
    
    sum=sumAry(ary,arySize);
    
    //Map Inputs to Outputs -> Process

    //Display Inputs/Outputs
    prntAry(ary,arySize);
    
    cout<<endl;
    
    prntAry(sum,arySize);
    
    delete []ary;
    delete []sum;
    //Exit the Program - Cleanup
    return 0;
}
int *getData(int &arySize){      //Return the array size and the array
    int *a; //Pointer for integer array
    
    a=new int[arySize];
    int i=0;
    while (i<arySize){
        cin>>a[i];
        i++;
    }
    return (a);
}
int *sumAry(const int *ary, int arySize){
    int *b=new int[arySize], //Allocate Memory for Parallel Array
                    total=0; //Placeholder for running total
    for(int i=0;i<arySize;i++){
        total+=ary[i];
        b[i]=total;
    }
    return b;
}
void prntAry(const int *array,int arySize){
    for(int i=0;i<arySize;i++){
        cout<<*(array+i);
        if(i<arySize-1){
            cout<<" ";
        }
    }
}