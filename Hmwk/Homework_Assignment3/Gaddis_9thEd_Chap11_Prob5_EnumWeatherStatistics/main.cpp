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

enum Months{JANUARY, FEBRUARY, MARCH, APRIL, MAY,
            JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER,
            NOVEMBER, DECEMBER};

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
   //Initialize the Random Number Seed
    
    //Declare Variables
    Months month;
    int    year=12,  //Size of the static Structure array
         hottest=0,  //The coldest month's temperature in Fahrenheit
       coldest=140;  //The hottest month's temperature in Fahrenheit
    WStats stats[year];
    float anFall=0, //Annual Average Rainfall in inches
          anTemp=0; //Annual Average temperature in Fahrenheit
    //string hMonth,  //String for the Hottest Month's name
           //cMonth;  //String for the Coldest Month's name
    
    //Initialize Variables
    
    for (month=JANUARY;month<JULY;month=static_cast<Months>(month+1)){
        //cin>>stats[i].month;
        cout<<"Enter the total rainfall for the month:\n";
        cin>>stats[month].ttlRain;
        cout<<"Enter the high temp:\n";
        do{
            cin>>stats[month].hiTemp;
            if (stats[month].hiTemp>140){
                cout<<"That's literally out of this world."<<endl;
            }
        }while(stats[month].hiTemp>140);
        cout<<"Enter the low temp:\n";
        do{
            cin>>stats[month].loTemp;
            if (stats[month].loTemp<-100){
                cout<<"That's literally out of this world."<<endl;
            }
        }while(stats[month].loTemp<-100);
        stats[month].avTemp=(stats[month].hiTemp+stats[month].loTemp)/2.0f;
        anFall+=stats[month].ttlRain;
        anTemp+=stats[month].avTemp;
        if (stats[month].hiTemp>hottest){
            hottest=stats[month].hiTemp;
            //hMonth=stats[i].month;
        }
        if (stats[month].loTemp<coldest){
            coldest=stats[month].loTemp;
            //cMonth=stats[i].month;
        }
    }
    
    //Map Inputs to Outputs -> Process
    anFall/=6.0f;
    anTemp/=6.0f;

    //Display Inputs/Outputs
    cout<<"Average monthly rainfall:"<<fixed<<setprecision(2)<<anFall<<endl;
    cout<<"High Temp:"<<hottest<<endl;
    cout<<"Low Temp:"<<coldest<<endl;
    cout<<"Average Temp:"<<fixed<<setprecision(1)<<anTemp;
    
      
    //Exit the Program - Cleanup*/
    return 0;
}