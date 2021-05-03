/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on April 4, 2021, 10:13 PM
 * Purpose:  To simulate a drink vending machine utilizing a structure
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries
#include "Machine.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const int SIZE=5;
    Machine drinks[SIZE]={{"Cola",75,20},{"Root Beer",75,20},{"Lemon-Lime",75,20},{"Grape Soda",80,20},{"Cream Soda",80,20}};
    Machine choice;
    int profit;
    
    //Initialize Variables
    profit=0;
    
    while (choice.name!="Quit"){
        for(int i=0;i<SIZE;i++){
            cout<<drinks[i].name<<setw(13-drinks[i].name.size())<<drinks[i].cost<<setw(4)<<drinks[i].num<<endl;
        }
        cout<<"Quit"<<endl;
        
            getline(cin,choice.name);
            cin>>choice.cost;
                
            cin.ignore();
            
            
            //Map Inputs to Outputs -> Process
            for(int i=0;i<SIZE;i++){
                if(choice.name==drinks[i].name){
                    if(choice.cost>=drinks[i].cost){
                        choice.cost-=drinks[i].cost;
                        drinks[i].num-=1;
                        profit+=drinks[i].cost;
                    }else{
                        cout<<"Credit = "<<choice.cost<<endl;
                    }
                }
            }

        if(choice.name!="Quit"){
            cout<<choice.cost<<endl;
        }
        
        
    }
    
    //Display Inputs/Outputs
    cout<<profit<<endl;
      
    //Exit the Program - Cleanup
    return 0;
}