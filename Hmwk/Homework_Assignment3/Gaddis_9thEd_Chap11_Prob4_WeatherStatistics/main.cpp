/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on April 4, 2021, 10:13 PM
 * Purpose:  To store weather data utilizing a structure
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries
#include "Wstats.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
     int    year=12,  //Size of the static Structure array
          hottest=0,  //The coldest month's temperature in Fahrenheit
        coldest=140;  //The hottest month's temperature in Fahrenheit
    WStats stats[year];
    float anFall=0, //Annual Average Rainfall in inches
          anTemp=0; //Annual Average temperature in Fahrenheit
    string hMonth,  //String for the Hottest Month's name
           cMonth;  //String for the Coldest Month's name
    
    //Initialize Variables
    
    for (int i=0;i<year;i++){
        cout<<"Please input Month Name: ";
        cin>>stats[i].month;
        cout<<endl<<"Please in put Total Monthly Rainfall in Inches: ";
        cin>>stats[i].ttlRain;
        do{
            cout<<endl<<"Please in put the month's lowest Temperature in °F: ";
            cin>>stats[i].loTemp;
            if (stats[i].loTemp<-100){
                cout<<"That's literally out of this world."<<endl;
            }
        }while(stats[i].loTemp<-100);
        do{
            cout<<endl<<"Please in put the month's highest Temperature in °F: ";
            cin>>stats[i].hiTemp;
            if (stats[i].hiTemp>140){
                cout<<"That's literally out of this world."<<endl;
            }
        }while(stats[i].hiTemp>140);
        stats[i].avTemp=(stats[i].hiTemp+stats[i].loTemp)/2.0f;
        anFall+=stats[i].ttlRain;
        anTemp+=stats[i].avTemp;
        if (stats[i].hiTemp>hottest){
            hottest=stats[i].hiTemp;
            hMonth=stats[i].month;
        }
        if (stats[i].loTemp<coldest){
            coldest=stats[i].loTemp;
            cMonth=stats[i].month;
        }
    }
    
    //Map Inputs to Outputs -> Process
    anFall/=12.0f;
    anTemp/=12.0f;

    //Display Inputs/Outputs
    cout<<"Average Rainfall "<<fixed<<setprecision(1)<<anFall<<" inches/month"<<endl;
    cout<<"Lowest  Temperature "<<cMonth<<setw(4)<<coldest<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<hMonth<<setw(5)<<hottest<<" Degrees Fahrenheit"<<endl;
    cout<<"Average Temperature for the year "<<fixed<<setprecision(0)<<anTemp;
    cout<<" Degrees Fahrenheit"<<endl;
      
    //Exit the Program - Cleanup
    return 0;
}