/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To factor input between 2 and 10000 into prime numbers
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include "Prime.h"
#include "Primes.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
Primes *factor(int); //Input an integer, return all prime factors
void prntPrm(Primes *); //-> Output all prime factors
void cleanUp(Primes *); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int num; //Number between 2 and 10000 input by user
    Primes *array; //Pointer to dynamic array structure
    
    
    num=0;
    //Initialize Variables
    cout<<"Enter a number to check for prime factors."<<endl;
    do{ 
        cin>>num;
        if(num<2||num>10000){
        cout<<"Invalid Input. Input must be between 2 and 10000.\n";    
        }
    }while (num<2||num>10000);
    
    //Fill the Array
    array=factor(num);
    
    //Map Inputs to Outputs -> Process
    

    //Display Inputs/Outputs
    //Print the Array
    prntPrm(array);
      
    //Exit the Program - Cleanup
    //Reallocate memory
    cleanUp(array);
    //delete array;
    return 0;
}
void cleanUp(Primes *array){
    //Just like Dr. Lehr showed us, work from the inner array outward
    delete []array->prime;
    delete array;
}

Primes *factor(int n){ //Input an integer, return all prime factors
    //Allocate memory for the structure
    Primes *array=new Primes;
    //Allocate memory for the array inside of the structure
    array->prime=new Prime[n];
    //Initialize number of Primes variable to 1, since it will have at least 1
    array->nPrimes=1;
    //Initialize 0 position to input, to allow it to pass between functions
    array->prime[0].prime=n;
    //Initialize 1 position to 0 have something to work with
    array->prime[1].prime=0;
    //Initialize 0 position to 0 to have it initialized to something
    array->prime[0].power=0;
    //Create temp variable to avoid changing input
    int temp=n, loops=0;
    
    //For loop going from 2 to the temp variable to try avoid excessive looping
    for(int i=2, j=1;i<=temp;i++){
        loops=i;
        //Test with mod operator to see if temp is divisible by iterator
        if(temp%i==0){
            //cout<<temp<<" / "<<i<<" = ";
            //If it is divisible, then divide and set new value for temp
            temp/=i;
            //cout<<temp<<endl;
            
            //If 1 position is not filled, then fill first position
            //Set position equal to iterator
            if(array->prime[1].prime==0){
                array->prime[1].prime=i;
            }
            
            //If Prime factor in current position is not equal to iterator
            if(array->prime[j].prime!=i){
                //Increment position
                j++;
                //Increment number of prime factors
                array->nPrimes+=1;
                //Set current position equal to iterator
                array->prime[j].prime=i;
                //Reset power value to 1
                array->prime[j].power=1;
            //If Prime Factor in current position is equal to the iterator
            }else{
                //Increment number of times current prime position factors into
                //temp value
                array->prime[j].power=array->prime[j].power+1;
            }
            //Decrement iterator to retest value again
            i=i-1;
        }
        
    }
    //cout<<"This program took "<<loops<<" loops to calculate primes\n";
    
    return array;
}
void prntPrm(Primes *a){ //-> Output all prime factors
    cout<<"Number of Prime Factors: "<<static_cast<int>(a->nPrimes)<<endl;
    cout<<a->prime[0].prime<<" = ";
    
    for(int i=1;i<=static_cast<int>(a->nPrimes);i++){
    
        cout<<a->prime[i].prime<<"^"<<static_cast<int>(a->prime[i].power);
        if(i<static_cast<int>(a->nPrimes)){
            cout<<" * ";
        }
    }
    
    
    
}

