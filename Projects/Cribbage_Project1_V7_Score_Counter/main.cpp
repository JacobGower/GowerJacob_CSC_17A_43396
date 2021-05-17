/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on May 1st, 2021, 7:31 PM
 * Purpose:  To develop a Turn Tracking System and Actually start designing
 *           gameplay for A Cribbage game
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
char *playHnd(char *,string&);
string fillStr(char *,char *,string&);
void crdPlay(string&, char *, char *);
int scrTrck(string);
void exit(char *,char *); //Exit function with arrays passed in to delete them
void error(); //Error Message 

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int SIZE=26;
    int numbers[SIZE];
    string cardGen="SHCDA23456789TJQK";
    //Need to have separate string objects to separate functions
    string hand, cmpHnd, rndPlay, trnPlay, played, crib;
    //char rndCard [SIZE]; //13 cards needed in a round
    char *deal;
    char *trnHand;
    char *trnComp;
    int suit,face,turn,rounds;
    bool numChck,goFrst;
    turn=rounds=0;
    //Initialize Variables
    do{
        suit=face=0;
        hand="";
        cmpHnd="";
        rndPlay="";
        trnPlay="";
        played="";
        crib="";
        rounds++;
    //CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
    //CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
            for (int i=0,j=1;i<SIZE;i+=2,j+=2){
                do{
                    numChck=1;      //Set default for the number check to true
                    suit=rand()%4;  //Mod by 4 to handle the suit possibilities
                    face=rand()%13; //Mod by 13 to handle card values
                    face+=4;        //Add 4 to face value to skip suit values
                    numbers[i]=face;//Assign face value to i position in int array
                    numbers[j]=suit;//Assign suit value to j position in int array
                    if (i>0){ //Only test for matches after first loop to avoid errors
                        for (int k=i-2,n=j-2;k>=0;k-=2,n-=2){
                            //Test to see if face and suit combo matches other values
                            if (numbers[i]==numbers[k]&&numbers[j]==numbers[n]){
                                numChck=0; //If match is found, set to 0
                            }
                        }
                    }
                }while (numChck==0);//Write over last value if match is found
                if(i<(SIZE-1)/2){
                    hand+=cardGen[numbers[i]];
                    hand+=cardGen[numbers[j]];
                }else if(i<SIZE-6){
                    cmpHnd+=cardGen[numbers[i]];
                    cmpHnd+=cardGen[numbers[j]];
                }else if(i<SIZE-2){
                    crib+=cardGen[numbers[i]];
                    crib+=cardGen[numbers[j]];
                }else{//The last card gets assigned to the starter card
                    rndPlay+=cardGen[numbers[i]];
                    rndPlay+=cardGen[numbers[j]];        
                }
            }  
    //CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
    //CARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARDGENERATIONCARD
            //Map Inputs to Outputs -> Process
            //Stick hand string into a char array for use in trnHand Function.
            deal=fillHnd(hand); 
            trnComp=fillHnd(cmpHnd);
            //Display Inputs/Outputs
            //Create initial hand array to use in future calls of playHnd function
            trnHand=playHnd(deal,trnPlay);

            cout<<endl<<"Your Hand: ";
            for (int i=0;i<strlen(trnHand)-1;i+=2){
                cout<<trnHand[i]<<trnHand[i+1]<<" ";
            }
            cout<<endl<<"Pick a card to put into your crib:\n";
            crib+=fillStr(trnHand,trnComp,trnPlay);
            trnHand=playHnd(trnHand,trnPlay);
            cout<<endl<<"Your Hand: ";
            for (int i=0;i<strlen(trnHand)-1;i+=2){
                cout<<trnHand[i]<<trnHand[i+1]<<" ";
            }
            cout<<endl<<"Pick a card to put into your crib:\n";
            crib+=fillStr(trnHand,trnComp,trnPlay);
            trnHand=playHnd(trnHand,trnPlay);
            //cout<<"The Crib: "<<crib<<endl;
            //cout the hand for view
            cout<<endl<<"Your Hand: ";
            for (int i=0;i<strlen(trnHand)-1;i+=2){
                cout<<trnHand[i]<<trnHand[i+1]<<" ";
            }
            cout<<endl;
            goFrst=rounds%2;
            switch (goFrst){
                case true: {
                    cout<<"You Go First:"<<endl;
                    cout<<"Starter card: "<<rndPlay<<endl;
                    while (rndPlay.size()<18){
                        if (strlen(trnHand)>1){
                            cout<<"Please input a card"<<endl<<endl;
                            rndPlay+=fillStr(trnHand,trnComp,trnPlay);
                            trnHand=playHnd(trnHand,trnPlay);
                            if (strlen(trnHand)>1){
                                cout<<endl<<"Your Hand: ";
                                for (int i=0;i<strlen(trnHand)-1;i+=2){
                                    cout<<trnHand[i]<<trnHand[i+1]<<" ";
                                }
                            }
                        cout<<endl<<"Cards Played: ";
                        for (int i=0;i<rndPlay.size();i+=2){
                            cout<<rndPlay[i]<<rndPlay[i+1]<<" ";
                        }
                        cout<<endl;

                        }if (strlen(trnComp)>1){
                            trnPlay+=trnComp[0];
                            trnPlay+=trnComp[1];
                            rndPlay+=trnPlay;
                            trnComp=playHnd(trnComp,trnPlay);
                        }
                        cout<<"Cards Played: ";
                        for (int i=0;i<rndPlay.size();i+=2){
                            cout<<rndPlay[i]<<rndPlay[i+1]<<" ";
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                    break;
                }case false:{
                    cout<<"Computer Goes First"<<endl;
                    cout<<"Starter card: "<<rndPlay<<endl;
                    while (rndPlay.size()<18){
                        if (strlen(trnComp)>1){
                            trnPlay+=trnComp[0];
                            trnPlay+=trnComp[1];
                            rndPlay+=trnPlay;
                            trnComp=playHnd(trnComp,trnPlay);
                        }
                        cout<<"Cards Played: ";
                        for (int i=0;i<rndPlay.size();i+=2){
                            cout<<rndPlay[i]<<rndPlay[i+1]<<" ";
                        }
                        if (strlen(trnHand)>1){
                            rndPlay+=fillStr(trnHand,trnComp,trnPlay);
                            trnHand=playHnd(trnHand,trnPlay);
                            if (strlen(trnHand)>1){
                                cout<<endl<<"Your Hand: ";
                                for (int i=0;i<strlen(trnHand)-1;i+=2){
                                    cout<<trnHand[i]<<trnHand[i+1]<<" ";
                                }
                            }
                        cout<<endl<<"Cards Played: ";
                        for (int i=0;i<rndPlay.size();i+=2){
                            cout<<rndPlay[i]<<rndPlay[i+1]<<" ";
                        }
                        cout<<endl;

                        }
                        cout<<endl;
                    }
                    cout<<endl;
                   break; 
                }
            }
        //Exit the Program - Cleanup 
        //Delete the array
        delete []trnHand;
        delete []trnComp;
    }while (rounds<2);
    return 0;
}
char *fillHnd(string h){
    //size the array using the string size
    char *array=new char[h.size()];
    //Use strncpy function to copy the string into the char array
    strncpy(array,h.c_str(),h.size());
    return array;   
}
char *playHnd(char *a, string& p){
    //New array sized 2 smaller because each card takes 2 spaces
    char *hand=new char[(strlen(a)-2)];
    //Use loop to run through and check values against input to exclude
    for (int i=0,j=0;i<strlen(a);i+=2){
        if (p[0]!=a[i]||p[1]!=a[i+1]){
            hand[j]=a[i];
            hand[j+1]=a[i+1];
            j+=2;
        }
    }
    p="";       //Clear the string for future input
    delete []a; //Clear array memory of passed in array
    return hand;//Return the new array
}
string fillStr(char *a, char *b, string& p){
    crdPlay(p,a,b);
    cout<<endl;
    return p;
}
void crdPlay(string& p, char *a, char *b){
    bool isVld; //Bool to test if input for card is valid
    do {
        isVld=0;
        cin>>p;
        //Cast string values to upper
        p[0]=toupper(p[0]);
        p[1]=toupper(p[1]);
        //Include exit condition
        if (p=="\\") {exit(a,b);}
        //For loop to run through array and check against values in hand array
        for(int i=0, j=1;i<strlen(a);i+=2,j+=2){
            //If Input matches a value in the array, change isVld to true
            if (isVld==0&&p[0]==a[i]&&p[1]==a[j]){
                isVld=1;
            }   
        }
        //If input values are invalid or the wrong size, call error function
        if (isVld==0||p.size()!=2){
            error();
        }
    //Repeat input until valid input is entered
    }while (isVld==0||p.size()!=2); 
}
int scrTrck(string){
    
}
//Let's use the void function from our starting point to exit
//Include the dynamically sized array so we can free up the memory if we 
//exit the game.
void exit(char *a, char *b){
    char quit;
    //confirm input
    cout<<"Are you sure you want to quit? Y/N"<<endl;
    cin>>quit;
    quit=toupper(quit);
    //Exit program
    if (quit=='Y') {
        cout<<"I get it, you've got more important things to do"<<endl;
        delete []a;
        delete []b;
        exit(0);
    }
    //or send back into game where they left off
    else {
        cout<<"Alright then, take your turn already."<<endl;
    }
}
//Just stick all of the appropriate error messages in one function to clean up
void error(){
    int msg=rand()%11; //Randomly Generate a number for a message
    
    switch (msg){
        case 0:{
            cout<<"You Have to put a card in!"<<endl;
            break;
        }case 1:{
            cout<<"You must be some kind of magician or something."<<endl;
            break;
        }case 2:{
            cout<<"Is that even a real card?"<<endl;
            break;
        }case 3:{
            cout<<"Come on! Play fair."<<endl;
            break;
        }case 4:{
            cout<<"Hey! Quit hiding cards up your sleeve!"<<endl;
            break;
        }case 5:{
            cout<<"This is getting old."<<endl;
            break;
        }case 6:{
            cout<<"Work with me, here."<<endl;
            break;
        }case 7:{
            cout<<"Nobody likes a cheater."<<endl;
            break;
        }case 8:{
            cout<<"Where are you getting these cards from?"<<endl;
            break;
        }case 9:{
            cout<<"You must think I was born yesterday."<<endl;
            break;
        }case 10:{
            cout<<"This is getting old."<<endl;
            break;
        }
    }
}