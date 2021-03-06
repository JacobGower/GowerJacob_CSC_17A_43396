/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 23, 2021, 3:30 PM
 * Purpose:  To Tell the Truth
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    bool x,y; //Boolean statements represented in the Table
    
    //Initialize Variables
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y"  //Logical operator header row
          " !(X&&Y) !X||!Y  !(X||Y) !X&&!Y"<<endl;
    
   
   //Iterate loop while there is input for x and y 
   while ((cin>>x)&&(cin>>y)) {
        //I don't like having to type in \0 in netbeans to end loop
        //Test for x and y input being 0 or 1
        if ((x==0||x==1)&&(y==0||y==1)) {
            //1==true   0==false
            cout<<(x?'T':'F')<<" ";          
            //Is y true?
            cout<<(y?'T':'F')<<"  ";         
            //Is x not true?
            cout<<(!x?'T':'F')<<"  ";        
            //Is y not true?
            cout<<(!y?'T':'F')<<"   ";
            //Are both x and y true?
            cout<<(x&&y?'T':'F')<<"    "; 
            //Is either x or y true?
            cout<<(x||y?'T':'F')<<"   ";
            //Is Exclusively x or Exclusively y true? 
            cout<<(x^y?'T':'F')<<"    ";
            //Is Exclusively (Exclusively x or Exclusively y), or Exclusively x true?
            cout<<((x^y)^x?'T':'F')<<"     ";
            //Is Exclusively (Exclusively x or Exclusively y), or Exclusively y true?
            cout<<((x^y)^y?'T':'F')<<"       ";
            //Is (x and y) not true?
            cout<<(!(x&&y)?'T':'F')<<"      ";
            //Is either x not true or is y not true?
            cout<<(!x||!y?'T':'F')<<"        ";
            //Is (either x or y) not true?
            cout<<(!(x||y)?'T':'F')<<"      ";
            //Is x not true and is y not true?
            cout<<(!x&&!y?'T':'F')<<"";
            cout<<endl;
        //If input for either x or y is not 1 or 0, reassign x='\0', ending the loop in NetBeans
        }else {
            x='\0';
        }
   }
   cout<<endl;
   
    //Exit the Program - Cleanup
    return 0;
}