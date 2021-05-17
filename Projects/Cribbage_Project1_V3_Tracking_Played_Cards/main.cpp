/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on May 1st, 2021, 7:31 PM
 * Purpose:  This is for the development of card input system by player
 *           It was supposed to also track input, but that should be in next V
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function
#include <cstring>    //String Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
//Randomly generate cards and return hands 
//Try to dynamically size a char array in a function like examples from class
char *fillHnd(string);
char *playHnd(char *);
void crdPlay(string&, char *);

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
    string hand1, hand2, inPlCrd, play;
    char rndCard [SIZE]; //13 cards needed in a round
    char *deal;
    char *trnHand;
    int suit,face,turn;
    bool numChck;
    turn=0;
    //Initialize Variables
    
    //turn counter to size hand array for turn
    //Just have to remember that hand size only decreases when card is played
    
    
    //for (turn=0;turn<6;turn++){
        suit=face=0;
        hand1="";
        hand2="";
        inPlCrd="";
        play="";
        
//CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
//CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
        for (int i=0,j=1;i<SIZE;i+=2,j+=2){
            do{
                numChck=1;
                suit=rand()%4;
                face=rand()%13;
                face+=4;
                numbers[i]=face;
                numbers[j]=suit;
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
                hand1+=card[numbers[i]];
                hand1+=card[numbers[j]];
               
            }else if(i<SIZE-2){
                hand2+=card[numbers[i]];
                hand2+=card[numbers[j]];
            }else{
                inPlCrd+=card[numbers[i]];
                inPlCrd+=card[numbers[j]];        
            }

        }

    //Initial Hand Generation.
        
        deal=fillHnd(hand1);
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
        for (int i=0;i<strlen(deal)-1;i+=2){
            cout<<deal[i]<<deal[i+1]<<" ";
        }
        
        
        trnHand=playHnd(deal);
        cout<<endl<<"Your Hand: ";
        for (int i=0;i<strlen(trnHand)-1;i+=2){
            cout<<trnHand[i]<<trnHand[i+1]<<" ";
        }
        cout<<endl;
        
        crdPlay(play,trnHand);
        
        trnHand=playHnd(trnHand);
        

        
        cout<<endl<<"Your Hand: ";
        for (int i=0;i<strlen(trnHand)-1;i+=2){
            cout<<trnHand[i]<<trnHand[i+1]<<" ";
        }
        /*cout<<endl<<"Opponent Hand: ";
        for (int i=0;i<hand2.size();i+=2){
            cout<<hand2[i]<<hand2[i+1]<<" ";
        }
        cout<<endl<<"Starter Card:";
        for (int i=0;i<inPlCrd.size();i+=2){
            cout<<inPlCrd[i]<<inPlCrd[i+1]<<" ";
        }
        cout<<endl;
    
    
        cout<<"String Length: "<<strlen(ary)<<endl;
        //cout<<"String Size: "<<sizeof(rndCard)<<endl;
        for (int i=0;i<sizeof(rndCard);i+=2){
            cout<<rndCard[i+1]<<rndCard[i]<<" ";
        }*/  
        cout<<endl;
    //Exit the Program - Cleanup 
    
    delete []trnHand;
    //}
    return 0;
}

char *fillHnd(string h){
    int size=h.size();
    //size=(size+1)-(2*t);
    //This won't work. Need to keep track of cards already played and pass in 
    //current hand, not just string for original hand.
    //Create a new function after initial hand creation in the round to handle
    //turn-to-turn hand changes.
    /*char *hand=new char[h.size()];
    //This feels redundant, but until I can piece together exactly what is happening
    //this stays in place
    for(int i=0;i<h.size();i++){
        *(hand+i)=h[i];
    }
    cout<<endl<<"Your Hand Before Play: ";
        for (int i=0;i<h.size();i+=2){
            cout<<hand[i]<<hand[i+1]<<" ";
        }
    */
    cout<<"h.size() = "<<size<<endl;
    char *array=new char[size];
    
    for(int i=0;i<size;i++){
        *(array+i)=h[i];
    }
    //cout<<h.size();
    return array;   
}
char *playHnd(char *a){
    char *hand=new char[(strlen(a)-2)];
    cout<<"strlen(a) = "<<strlen(a)<<endl;
    //cout<<"strlen(hand) = "<<sizeof(hand)<<endl;
    strncpy(hand,a,(strlen(a)-2));
    cout<<"strlen(hand) = "<<strlen(hand)<<endl;
    delete []a;
    return hand;
}
void crdPlay(string& p, char *a){
    bool isVld; //Bool to test if input for card is valid
    
    do {
        isVld=0;
        //Ask for Cards to add to the Crib for the Round
        //cout<<"Choose two cards to throw to the crib"<<endl;
        cin>>p;
        p[0]=toupper(p[0]); p[1]=toupper(p[1]);
        if (p.size()!=2){
            cout<<"That's not a card."<<endl;
        }
        for(int i=0, j=1;i<strlen(a);i+=2,j+=2){
        
            if (isVld==0&&p[0]==a[i]&&p[1]==a[j]){
                isVld=1;
            }
            
        }
        if (isVld==0){
            cout<<"Invalid card"<<endl;
        }
    }while (isVld==0||p.size()!=2); 
}