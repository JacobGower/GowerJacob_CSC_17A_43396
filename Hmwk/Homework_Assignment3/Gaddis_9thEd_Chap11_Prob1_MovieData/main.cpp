/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on April 4, 2021, 10:13 PM
 * Purpose:  To store movie data utilizing a structure
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include "Movie.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
void display(Movie &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Movie info;
    int    num;
    
    //Initialize Variables
    num=0;
    
    info.year=0;
    info.mins=0;
    
    cin>>num;
    
    //Map Inputs to Outputs -> Process
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl<<endl;
    
    for(int i=0;i<num;i++){
        cin.ignore();
        getline(cin,info.title);
        getline(cin,info.directr);
        cin>>info.year;
        cin>>info.mins;
        display(info);
        if(i<(num-1)){
            cout<<endl;
        }
    }

    //Display Inputs/Outputs
   
      
    //Exit the Program - Cleanup
    return 0;
}
void display(Movie &info){
    cout<<"Title:     "<<info.title<<endl;
    cout<<"Director:  "<<info.directr<<endl;
    cout<<"Year:      "<<info.year<<endl;
    cout<<"Length:    "<<info.mins<<endl;
}