/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on April 4, 2021, 10:13 PM
 * Purpose:  To store budget data utilizing a structure
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries
#include "MoBdgt.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
void getData(MoBdgt &);
void undrOvr(float ,float );
void display(MoBdgt &,MoBdgt &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    MoBdgt  goals;
    MoBdgt actual;
    
    //Initialize Variables
    goals={500,150,65,50,
           250,30,100,150,
           75,50,1420};
           
    getData(actual);
    
    //Display Inputs/Outputs
    display(actual,goals);
      
    //Exit the Program - Cleanup
    return 0;
}
void getData(MoBdgt &actual){
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>actual.housing;
    actual.total+=actual.housing;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>actual.utility;
    actual.total+=actual.utility;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>actual.hsExpns;
    actual.total+=actual.hsExpns;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>actual.transpo;
    actual.total+=actual.transpo;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>actual.food;
    actual.total+=actual.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>actual.medical;
    actual.total+=actual.medical;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>actual.insrnce;
    actual.total+=actual.insrnce;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>actual.entrtan;
    actual.total+=actual.entrtan;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>actual.clothes;
    actual.total+=actual.clothes;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>actual.misc;
    actual.total+=actual.misc;
}
void undrOvr(float a,float b){
    
    if (a<b){
        cout<<"Under"<<endl;
    }else if(a>b){
        cout<<"Over"<<endl;
    }else{
        cout<<"Even"<<endl;
    }
}
void display(MoBdgt &actual,MoBdgt &goals){
    cout<<"Housing ";
    undrOvr(actual.housing,goals.housing);
    
    cout<<"Utilities ";
    undrOvr(actual.utility,goals.utility);
    
    cout<<"Household Expenses ";
    undrOvr(actual.hsExpns,goals.hsExpns);
    
    cout<<"Transportation ";
    undrOvr(actual.transpo,goals.transpo);
    
    cout<<"Food ";
    undrOvr(actual.food,goals.food);
    
    cout<<"Medical ";
    undrOvr(actual.medical,goals.medical);
    
    cout<<"Insurance ";
    undrOvr(actual.insrnce,goals.insrnce);
    
    cout<<"Entertainment ";
    undrOvr(actual.entrtan,goals.entrtan);
    
    cout<<"Clothing ";
    undrOvr(actual.clothes,goals.clothes);
    
    cout<<"Miscellaneous ";
    undrOvr(actual.misc,goals.misc);
    
    if(goals.total-actual.total<0){
      cout<<fixed<<setprecision(2)<<showpoint<<"You were $"<<(goals.total-actual.total)*(-1)<<" over budget";
    }else if(goals.total-actual.total>0){
        cout<<fixed<<setprecision(2)<<showpoint<<"You were $"<<(goals.total-actual.total)<<" under budget";
    }else{
        cout<<"You broke even this month.";
    }
}