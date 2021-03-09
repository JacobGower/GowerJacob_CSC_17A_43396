/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose:  To Predict the Size of a Population of Organisms over time
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int    begPop, //Beginning Population of Organisms
             days, //Number of days the population increases
           finPop; //Final Population of Organisms
    float dayPrct; //Average daily Population Increase as a Percent
            
    //Initialize Variables
    begPop=days=dayPrct=0;
    
    while (begPop<2) {
        cout<<"Input starting number of organisms (Minimum of 2):";
        cin>>begPop;
        cout<<endl;
        
        if (begPop<2) {
            cout<<"I think I need to tell you about the birds and the bees.\n";
        }
    }
    
    finPop=begPop;
    
    do {
        cout<<"Please input the average daily population ";
        cout<<"increase as a percentage:";
        cin>>dayPrct;
        cout<<endl;
        
        if (dayPrct<0) {
            cout<<"This calculates population growth, not reduction."<<endl;
        }
    }while (dayPrct<0);
    
    dayPrct/=100.0f;
    
    do {
        cout<<"Please input the Number of days that the ";
        cout<<"population increases: "<<endl;
        cin>>days;
        cout<<endl;
        
        if (days<1) {
            cout<<"These things take more time than that."<<endl;
        }
    }while (days<1);
    
    
    
    //Map Inputs to Outputs -> Process

    //Display Inputs/Outputs
    
    for (int i=1;i<=days;i++) {
       finPop+=finPop*dayPrct;
       
       cout<<"Population Day "<<i<<": "<<finPop<<endl;
    }
      
    //Exit the Program - Cleanup
    return 0;
}

