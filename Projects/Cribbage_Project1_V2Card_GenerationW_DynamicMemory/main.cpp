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
//Randomly generate cards and return hands 
//Try to dynamically size a char array in a function like examples from class
char *fillHnd(string, int);
//char *playHnd(string, *char, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    //Start with static array to work out kinks and test concept
    const int SIZE=26;
    int numbers[SIZE];
    //const short CARDS=18;
    string card="SHCDA23456789TJQK";
    string hand1, hand2, strtCrd;
    char rndCard [SIZE]; //13 cards needed in a round
    char *ary;
    //char *trnHand;
    int suit,face,turn;
    bool numChck;
    
    //Initialize Variables
    
    //turn counter to size hand array for turn
    //Just have to remember that hand size only decreases when card is played
    turn=2;
    
    //for (int i=0;i<15;i++){
        suit=face=0;
        hand1="";
        hand2="";
        strtCrd="";
        
//CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
//CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
        for (int i=0,j=1;i<SIZE;i+=2,j+=2){
            do{
                numChck=1;
                suit=rand()%4;
                face=rand()%13;
                face+=4;
                numbers[i]=suit;
                numbers[j]=face;
                if (i>0){
                    for (int k=i-2,n=j-2;k>=0;k-=2,n-=2){
                        if (numbers[i]==numbers[k]&&numbers[j]==numbers[n]){
                            numChck=0;
                        }
                    }
                }
            }while (numChck==0);
            
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

    //Initial Hand Generation.
        ary=fillHnd(hand1,turn);
//CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
//CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
        //Map Inputs to Outputs -> Process
        
        //Display Inputs/Outputs
        
        //Ignore the full amount of cards until we figure out what to do with them
        /*cout<<"All Cards:\n";
        for (int i=0,j=1;i<SIZE;i+=2,j+=2){

            cout<<rndCard[j]<<rndCard[i]<<" ";
            if(j%12==11){
                cout<<endl;
            }

        }*/
        
        //trnHand=playHnd(hand1,ary,turn);
                
        cout<<endl<<"Your Hand: ";
        for (int i=0;i<hand1.size();i+=2){
            cout<<ary[i]<<ary[i+1]<<" ";
        }
        cout<<endl<<"Opponent Hand: ";
        for (int i=0;i<hand2.size();i+=2){
            cout<<hand2[i]<<hand2[i+1]<<" ";
        }
        cout<<endl<<"Starter Card:";
        for (int i=0;i<strtCrd.size();i+=2){
            cout<<strtCrd[i]<<strtCrd[i+1]<<" ";
        }
        cout<<endl;
    //}
    
    //Exit the Program - Cleanup 
    delete []ary;
    return 0;
}

char *fillHnd(string h, int t){
    //This won't work. Need to keep track of cards already played and pass in 
    //current hand, not just string for original hand.
    //Create a new function after initial hand creation in the round to handle
    //turn-to-turn hand changes.
    char *hand=new char[h.size()];
    //This feels redundant, but until I can piece together exactly what is happening
    //this stays in place
    char *array=new char[h.size()-(2*t)];
    for(int i=0;i<h.size();i++){
        *(hand+i)=h[i];
    }
    cout<<endl<<"Your Hand Before Play: ";
        for (int i=0;i<h.size();i+=2){
            cout<<hand[i]<<hand[i+1]<<" ";
        }
    
    for(int i=0;i<h.size()-(2*t);i++){
        *(array+i)=hand[i];
    }
    
    //cout<<h.size();
    delete []hand;
    //t++;
    return array;   
}