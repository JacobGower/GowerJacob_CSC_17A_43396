/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose:  To store and report Meteorological data
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>   //File Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int sum(int arr[], const int SIZE);
int most( int arr[],const int SIZE);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    fstream          in; //Input for fstream
    string      rnOrShn, //RainOrShine file that holds Data
                mnthNme; //Month Name
    const short DAYS=30, //Days in a month that data is being recorded
               MONTHS=3; //Number of months that data is being recorded
    int  rainy[MONTHS]={0},      //Array for rainy days
        cloudy[MONTHS]={0},      //Array for cloudy days
         sunny[MONTHS]={0};      //Array for sunny days
    char data[MONTHS][DAYS],     //3x30 Array for Data collected
                    weather;     //Weather for a given day, read from file
    
    //Initialize Variables
    rnOrShn="RainOrShine.dat";
    //Open Rain or Shine File with Meteorological Data
    in.open(rnOrShn.c_str(),ios::in);
    
    
    //Map Inputs to Outputs -> Process
    //Display Inputs/Outputs
    for(int month=0;month<MONTHS;month++){
        for(int day=0;day<DAYS;day++){
            in>>weather;
            data[month][day]=(weather=='R'?rainy[month]++:
                              weather=='C'?cloudy[month]++:
                              weather=='S'?sunny[month]++:'\0');
                
                    
        }
    }
    
    
    
    for(int month=0;month<MONTHS;month++){
        mnthNme=(month==0?"June    ":
                 month==1?"July    ":
                 month==2?"August  ":"");
            cout<<"The number of rainy days in "<<mnthNme;
            cout<<" : "<<rainy[month]<<endl;
    }
    cout<<setw(39)<<"The total number of rainy days   : ";
    cout<<sum(rainy,MONTHS)<<endl<<endl;
        
    for(int month=0;month<MONTHS;month++){
        mnthNme=(month==0?"June  ":
                 month==1?"July  ":
                 month==2?"August":"");
        cout<<" The number of cloudy days in "<<mnthNme;
        cout<<" : "<<cloudy[month]<<endl;
    }
    cout<<setw(39)<<"The total number of cloudy days : ";
    cout<<sum(cloudy,MONTHS)<<endl<<endl;
        
    for(int month=0;month<MONTHS;month++){
        mnthNme=(month==0?"June   ":
                 month==1?"July   ":
                 month==2?"August ":"");
        cout<<" The number of sunny days in "<<mnthNme;
        cout<<" : "<<sunny[month]<<endl;
    }
    cout<<setw(39)<<"The total number of sunny days : ";
    cout<<sum(sunny,MONTHS)<<endl<<endl;
    
    mnthNme=(most(rainy,MONTHS)==0?"June":
             most(rainy,MONTHS)==1?"July":
             most(rainy,MONTHS)==2?"August":"");
    
    cout<<mnthNme<<" had the most rainy days."<<endl;
    
    //Exit the Program - Cleanup
    in.close();
    return 0;
}
int sum(int arr[], const int SIZE){
    int total=0;
    for(int i=0; i<SIZE; i++){
        total+=arr[i];
    }
    return total;
}
int most(int arr[], const int SIZE){
        int max=0;
        for(int i=1;i<SIZE;i++){
            if(arr[max]<arr[i]){
                max=i;
            }
        }
    return max;
}

