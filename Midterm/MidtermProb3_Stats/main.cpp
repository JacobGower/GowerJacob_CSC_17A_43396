/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    
    cout<<endl<<"Stat function that was completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    stats->modFreq=0;
    stats->avg=0;
    int nModes=0,
         count=0;
    
    //Let's mix and match pointer notation for giggles
    for(int i=0;i<array->size;i++){
        //When i==0 there is no previous element, so just increment
        if(i==0){
            count++;
        //Test if current element matches previous element
        }else if(*((*array).data+i)==*((*array).data+(i-1))){
            //If match is detected, increment counter
            count++;
        }else{
            //If no match is detected, reset counter
            count=1;
        }
        //Use counter to set frequency
        if(count>stats->modFreq){
            //If counter is larger than current max frequency
            //set frequency equal to counter
            stats->modFreq=count;
        }
        stats->avg+=*((*array).data+i);
    }
    (*stats).avg/=array->size;
    count=0;
    for(int i=0;i<array->size;i++){
        //Increment counter the same way
        if(i==0){
            count++;
        
        }else if(array->data[i]==(*array).data[i-1]){
            //If match is detected, increment counter
            count++;
        }else{
            //If no match is detected, reset counter
            count=1;
        }
        //If counter equals max frequency and is greater than one, then it is a mode.
        if(count==(*stats).modFreq&&count>1){
            //Increment number of modes
            nModes++;
        }
    }
    //Set the size that can be passed through the structure equal to the
    //number of modes
    (*stats).mode->size=nModes;
    
    if(nModes!=0)stats->mode->data=new int[nModes];
    count=0;
    for(int i=0,j=0;i<array->size;i++){
        //Find modes with the same method
        if(i==0){
            count++;
        }else if(*((*array).data+i)==array->data[i-1]){
            count++;
        }else{
            count=1;
        }
        //If count is greater than 1 and count is equal to max frequency, then it is a mode and goes into the array
        
        if(count==stats->modFreq&&count>1){
            //Use separate counter for mode Array since the positions in the different arrays will not necessarily correspond
            *(stats->mode->data+j)=array->data[i];
            //Increment the stats->mode->data position
            j++;
        }
    }
    //Initialize median value
    stats->median=0;
    //Test to see if array size is even
    if((*array).size%2==0){
        //If array has even number of values, add two middle values together
        //and divide by 2.0f
        //Static cast values as floats and append literal with f to make sure
        //that not integer division happens
        stats->median=(static_cast<float>(*((*array).data+(((array->size)/2)-1)))
                      +static_cast<float>(array->data[((array->size)/2)]))/2.0f;
    }else{
        //If array has odd number of values, then mode is just the value in the
        //middle position
        stats->median=array->data[((array->size)/2)];
    }
    return stats;
}