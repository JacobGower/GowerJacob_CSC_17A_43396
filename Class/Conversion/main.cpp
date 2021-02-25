/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  Playing with strings
 */

//System Libraries
#include <iostream>  //I/O Library
#include <sstream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int ix;
    string strx;
    stringstream ss;
    bool canCnvrt;
    
    
    //Initialize Variables
    canCnvrt=true;
    cout<<"Input a integer string"<<endl;
    cin>>strx;
    
    //Map Inputs to Outputs -> Process
    ss<<strx;
    for(int i=0;i<strx.length()&&canCnvrt;i++) {//Limitations with size
        if(strx[i]>='0'&&strx[i]<='9'){
            canCnvrt=true;
        }else{
            canCnvrt=false;
        }
    }
    
    //Display Inputs/Outputs
    if(canCnvrt&&strx.length()<8){
        ss>>ix;
        cout<<"The integer conversion "<<strx<<"="<<ix<<endl;
    }else{
        cout<<"No Conversion Possible"<<endl;
    }
      
    //Exit the Program - Cleanup
    return 0;
}

