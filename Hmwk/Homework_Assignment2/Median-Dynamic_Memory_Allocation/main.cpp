/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 28, 2021, 6:16 PM
 * Purpose:  To find the Median of a set of numbers using dynamic memory allocation
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int *getData(int &);        //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);   //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);      //Print the median Array
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int      *ary, //Pointer for integer array
          arySize; //Array size, input by user
    float *medAry; //Pointer for float array
    
    cin>>arySize;
    
    //Initialize Variables
    
    ary=getData(arySize);
    
    prntDat(ary,arySize);
    
    medAry=median(ary,arySize);
    
    prntMed(medAry);
    
    //Map Inputs to Outputs -> Process

    //Display Inputs/Outputs
    
    delete []ary;
    delete []medAry;
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
    
    arySize+=2;
    
    return (a);
} 
void prntDat(int *ary,int arySize){  //Print the integer array
    for(int i=0;i<arySize-2;i++){
        cout<<*(ary+i);
        if(i<arySize-3){
            cout<<" ";
        }
    }
    cout<<endl;
}
float *median(int *ary,int arySize){ //Fill the median Array with the Float array size, the median, and the integer array data
    float *b, //pointer for float array
         med=0; //Median
         
    
    b=new float[arySize];
    b[0]=arySize;
    
    for(int i=0,j=2;j<arySize;i++,j++) {
        *(b+j)=*(ary+i);
    }
    mrkSort(ary,(arySize-2));
    if(arySize%2==0){
        med=(static_cast<float>(*(ary+(((arySize)/2)-1)))+static_cast<float>(*(ary+((arySize)/2)-2)))/2.0f;
    }else{
        med=*(ary+(((arySize)/2)-1));
    }
    b[1]=med;
    return b;
}
void prntMed(float *medAry){    //Print the median Array
    for(int i=0;i<medAry[0];i++){
        if(i==0){
            cout<<medAry[i]<<" ";
        }else if(i<(medAry[0]-1)){
            cout<<fixed<<setprecision(2)<<showpoint<<medAry[i]<<" ";
        }else{
            cout<<fixed<<setprecision(2)<<showpoint<<medAry[i];
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