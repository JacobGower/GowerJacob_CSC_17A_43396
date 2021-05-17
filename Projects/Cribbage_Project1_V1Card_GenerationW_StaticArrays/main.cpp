/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on May 1st, 2021, 7:31 PM
 * Purpose:  This is a test to stub to try and develop a hand of cards using 
 *           Dynamic arrays
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function
//#include <string>    //String Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
//Get all of the Number Generation for a round done in one function

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    //Start with static array to work out kinks and test concept
    const int SIZE=26;
    int numbers[SIZE];
    const short CARDS=18;
    //Use a string since we can treat it like a char array for our purposes
    string card="SHCDA23456789TJQK";
    //char card [CARDS]={"SHCDA23456789TJQK"}; //A char array to hold all possible card combinations
    string hand1, hand2, strtCrd;
    char rndCard [SIZE]; //13 cards needed in a round
    int suit,face;
    bool numChck;
    
    //Initialize Variables
    //for (int i=0;i<15;i++){
        suit=face=0;
        //cout<<"Select card please: "<<endl;
        //cin>>suit;
        //cin>>face;

        //cout<<"Face = "<<face<<endl;


        for (int i=0,j=1;i<SIZE;i+=2,j+=2){
            do{
                numChck=0;
                suit=rand()%4;
                face=rand()%13;
                face+=4;
                numbers[i]=suit;
                numbers[j]=face;
                if (i>0){
                    for (int k=i-2,n=j-2;k>=0;k-=2,n-=2){
                        if (numbers[i]==numbers[k]&&numbers[j]==numbers[n]){
                            numChck=1;
                        }
                    }
                }
            }while (numChck==1);
            rndCard[i]=card[numbers[i]];
            rndCard[j]=card[numbers[j]];
            if(i<(SIZE-1)/2){
                hand1+=card[numbers[j]];
                hand1+=card[numbers[i]];
               
            }else if(i<SIZE-2){
                hand2+=card[numbers[j]];
                hand2+=card[numbers[i]];
            }else{
                strtCrd+=card[numbers[j]];
                strtCrd+=card[numbers[i]];        
            }

        }

        //Map Inputs to Outputs -> Process
        //cout<<"Suit = "<<suit<<endl;
        //cout<<"Face = "<<face<<endl;




        //Display Inputs/Outputs
        //cout<<"Is this your card? \n"<<cards[suit][face]<<endl;
        //cout<<"Is this your card? \n"<<cards[suit]<<cards[face]<<endl;
        
        cout<<"All Cards:\n";
        for (int i=0,j=1;i<SIZE;i+=2,j+=2){

            cout<<rndCard[j]<<rndCard[i]<<" ";
            if(i%12==0){
                cout<<endl;
            }

        }
        cout<<"Your Hand: ";//<<hand1<<endl;
        for (int i=0;i<hand1.size();i+=2){
            cout<<hand1[i]<<hand1[i+1]<<" ";
        }
        cout<<endl<<"Opponent Hand: ";//<<hand2<<endl;
        for (int i=0;i<hand1.size();i+=2){
            cout<<hand2[i]<<hand2[i+1]<<" ";
        }
        cout<<endl<<"Starter Card:";
        for (int i=0;i<strtCrd.size();i+=2){
            cout<<strtCrd[i]<<strtCrd[i+1]<<" ";
        }
    //}
    //Exit the Program - Cleanup 
    return 0;
}