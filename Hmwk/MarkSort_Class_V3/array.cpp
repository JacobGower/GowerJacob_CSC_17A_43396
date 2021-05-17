/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 6th, 2021, 6:14 PM
 * Purpose:  Array Class on Specification
 */

#include "array.h"
#include <cstdlib>
using namespace std;


//Function Implementations
//No need to pass in any data because many parameters are internal to the class
//Only data not internal to class must be passed to funtions here

//Array:: is an appending statement to show it is included in the class

void Array::setData(int indx,int val){  //Modify Data
    if(indx>=0&&indx<size){
        //Disallows the index from going outside the bounds of the array
        data[indx]=val;
    }
}

int Array::getData(int indx){       //Retrieve Data
     if(indx>=0&&indx<size){
        //Disallows the index from going outside the bounds of the array
        return data[indx];
    }
    
}
void Array::markSrt(){
    //Find the smallest element in List i
    for(int i=0;i<size-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<size;j++){
            //Logic swap
            if(data[i]>data[j]){
                data[i]=data[i]^data[j];
                data[j]=data[i]^data[j];
                data[i]=data[i]^data[j];
            }
        }
    }
}




void Array::filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    data=new int[n];
    size=n;
    for(int i=0;i<n;i++){
        data[i]=rand()%90+10;//2 Digit Random Array
    }
    //No need to return anything 
}