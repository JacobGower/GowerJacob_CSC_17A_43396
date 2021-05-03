/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 28, 2021, 6:16 PM
 * Purpose:  To Augment a 1-D array by 1 Element, place 0 in the first element and copy the rest from the original shifted by 1 index.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int *getData(int &);           //Read the array
int *augment(const int *,int); //Augment and copy the original array
void prntAry(const int *,int); //Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int arySize, //Dynamic Array Size Input by User
           *ary, //Dynamic Array
        *augAry; //Augmented Dynamic Array
    
    //Initialize Variables
    cin>>arySize;
    
    ary=getData(arySize);
    
    //Map Inputs to Outputs -> Process
    augAry=augment(ary,arySize);
    
    //Display Inputs/Outputs
    prntAry(ary,arySize);
    cout<<endl;
    
    prntAry(augAry,arySize+1);
      
    //Exit the Program - Cleanup
    delete []ary;
    delete []augAry;
    
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
int *augment(const int *array,int arySize){
    int *b=new int[arySize+1];
    
    b[0]=0;
    
    for(int i=0;i<arySize+1;i++){
        b[i+1]=array[i];
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