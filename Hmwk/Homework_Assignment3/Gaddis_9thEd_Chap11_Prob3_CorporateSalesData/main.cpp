/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on April 4, 2021, 10:13 PM
 * Purpose:  To store company data utilizing a structure
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries
#include "Dvsn.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Dvsn north, //North Division
         west,  //West Division
         east,  //East Division
         south; //South Division
         
    
    //Initialize Variables
    north.anSales=west.anSales=east.anSales=south.anSales=0;
    
    north.avSales=west.avSales=east.avSales=south.avSales=0;
    
    //North Divisions sales first
    cout<<"North"<<endl;
    //Collect Input
    cout<<"Enter first-quarter sales:"<<endl<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl<<"Enter fourth-quarter sales:"<<endl;
    cin>>north.q1>>north.q2>>north.q3>>north.q4;
    
    //Map Inputs to Outputs -> Process
    //Calculate Totals and Averages
    north.anSales=north.q1+north.q2+north.q3+north.q4;
    
    north.avSales=north.anSales/4.0f;
    
    //Display Inputs/Outputs;
    cout<<fixed<<setprecision(2)<<showpoint<<"Total Annual sales:$"<<north.anSales<<endl;
    
    cout<<fixed<<setprecision(2)<<showpoint<<"Average Quarterly Sales:$"<<north.avSales<<endl;
    
    //West Divisions sales second
    cout<<"West"<<endl;
    //Collect Input
    cout<<"Enter first-quarter sales:"<<endl<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl<<"Enter fourth-quarter sales:"<<endl;
    cin>>west.q1>>west.q2>>west.q3>>west.q4;
    
    //Map Inputs to Outputs -> Process
    //Calculate Totals and Averages
    west.anSales=west.q1+west.q2+west.q3+west.q4;
    
    west.avSales=west.anSales/4.0f;
    
    //Display Inputs/Outputs;
    cout<<fixed<<setprecision(2)<<showpoint<<"Total Annual sales:$"<<west.anSales<<endl;
    
    cout<<fixed<<setprecision(2)<<showpoint<<"Average Quarterly Sales:$"<<west.avSales<<endl;
    
    //East Divisions sales third
    cout<<"East"<<endl;
    //Collect Input
    cout<<"Enter first-quarter sales:"<<endl<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl<<"Enter fourth-quarter sales:"<<endl;
    cin>>east.q1>>east.q2>>east.q3>>east.q4;
    
    //Map Inputs to Outputs -> Process
    //Calculate Totals and Averages
    east.anSales=east.q1+east.q2+east.q3+east.q4;
    
    east.avSales=east.anSales/4.0f;
    
    //Display Inputs/Outputs;
    cout<<fixed<<setprecision(2)<<showpoint<<"Total Annual sales:$"<<east.anSales<<endl;
    
    cout<<fixed<<setprecision(2)<<showpoint<<"Average Quarterly Sales:$"<<east.avSales<<endl;
    
    //South Divisions sales fourth
    cout<<"South"<<endl;
    //Collect Input
    cout<<"Enter first-quarter sales:"<<endl<<"Enter second-quarter sales:"<<endl;
    cout<<"Enter third-quarter sales:"<<endl<<"Enter fourth-quarter sales:"<<endl;
    cin>>south.q1>>south.q2>>south.q3>>south.q4;
    
    //Map Inputs to Outputs -> Process
    //Calculate Totals and Averages
    south.anSales=south.q1+south.q2+south.q3+south.q4;
    
    south.avSales=south.anSales/4.0f;
    
    //Display Inputs/Outputs;
    cout<<fixed<<setprecision(2)<<showpoint<<"Total Annual sales:$"<<south.anSales<<endl;
    
    cout<<fixed<<setprecision(2)<<showpoint<<"Average Quarterly Sales:$"<<south.avSales;
      
    //Exit the Program - Cleanup
    return 0;
}