/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 28, 2021, 6:16 PM
 * Purpose:  To Read in a dynamic array and Output the reverse sorted dynamic array by first sorting from smallest to largest.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int *getData(int &);           //Fill the array
int *sort(const int *,int);    //Sort smallest to largest
int *reverse(const int *,int); //Sort in reverse order
int *srtCopy(const int *,int); //Copy the Array
void prntDat(const int *,int); //Print the array
void swap(int *,int *);        //Swap
void minPos(int *,int,int);    //Find min Position
void mrkSort(int *,int);       //Mark Sort

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int arySize, //Dynamic Array Size Input by User
           *ary, //Dynamic Array
        *sorted, //Copy to be Sorted
           *rev; //Copy to be Reversed
            
    
    //Initialize Variables
    cin>>arySize;
    
    ary=getData(arySize);
    
    //Map Inputs to Outputs -> Process
    sorted=sort(ary,arySize);
    prntDat(sorted,arySize);
    cout<<endl;

    //Display Inputs/Outputs
    rev=reverse(sorted,arySize);
    prntDat(rev,arySize);
    
    delete []rev;
    delete []sorted;  
    delete []ary;  
    //Exit the Program - Cleanup
    return 0;
}
int *getData(int &arySize){  //Return the array
    int *a; //Pointer for integer array
    
    a=new int[arySize];
    int i=0;
    while (i<arySize){
        cin>>a[i];
        i++;
    }
    
    return (a);
}
int *sort(const int *ary,int arySize){
    //Declare and allocate an array
    int *array=new int[arySize];
    //Fill with passed array
    
    for(int i=0;i<arySize;i++){
        array[i]=ary[i];
    }
    mrkSort(array,arySize);
    return array;
    
    //Return the copy
}
int *reverse(const int *ary,int arySize){
    int *array=new int[arySize];
    //Fill with passed array
    for(int i=0;i<arySize;i++){
        array[i]=ary[(arySize-(i+1))];
    }
    return array;
}
void prntDat(const int *array,int arySize){  //Print the integer array
    for(int i=0;i<arySize;i++){
        cout<<*(array+i);
        if(i<arySize-1){
            cout<<" ";
        }
    }
}
void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}
void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}