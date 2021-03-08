/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose:  To convert between U.S. dollars and Japanese Yen and Euros
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const float YEN_DLLR=108.94, //108.94 Japanese Yen to 1 U.S. Dollar
                EUR_DLLR=0.84;   //0.84 Euros to 1 U.S. Dollar
          float dollar,          //Dollar amount Input by User
                euAmnt,          //Equivalent amount of Euros
                yenAmnt;         //Equivalent amount of Japanese Yen
          
    //Initialize Variables
    do {
        cout<<"Please input a U.S. dollar amount to convert"<<endl;
        cin>>dollar;
        if (dollar<0) {
            cout<<"Please input a positive dollar amount"<<endl;
        }
        if (dollar==0) {
            cout<<"Really?"<<endl;
        }
    }while (dollar<0);
    
    //Map Inputs to Outputs -> Process
    yenAmnt=dollar*YEN_DLLR;
    
    euAmnt=dollar*EUR_DLLR;
    
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"$"<<dollar<<" is equivalent to:"<<endl;
    cout<<"¥"<<yenAmnt<<endl;
    cout<<"€"<<euAmnt<<endl;
      
    //Exit the Program - Cleanup
    return 0;
}

