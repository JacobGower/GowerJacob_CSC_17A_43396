/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on May 1st, 2021, 7:31 PM
 * Purpose:  To Play a Game of Cribbage against a computer and streamline 
 *           old programming with newly introduced concepts
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
#include <cstdlib>   //Random Function
#include <fstream>   //File Library
#include <string>    //String Library
#include <ctime>     //Time Library
#include <vector>    //vectors<>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
//Get all of the Number Generation for a round done in one function
void numGen(vector<int> &,char); //Number Generation
void exit(); //Function to end the program at any time
void hndDspl (string,string,string,string,string,string,string,string);
int mgcNums (int &,string,int [],int [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream in,out; //Input and Output for fstream 
    const int  PL_HAND=4,  //Cards in Player's Hand during Play Phase
               CP_HAND=4,  //Cards in Computer's Hand During Play Phase
                 SUITS=5,
                  FACE=14, //Face Value of Each Card
               MAX_SCR=41, //~1/3 Max Score in a Game of Cribbage
                  SIZE=80; //Larger than the player will hopefully need
    int    plyrScr[SIZE], //Score of the Player
            cmpScr[SIZE],  //Score of the Computer
                    rounds,   //Counter for the Round
                    rndScr,  //Round Score
                    scrTrck; //Tracker to use for the parallel Arrays
     vector<int> randNum(0);//Vector for random number values
    float           avgScr;  //Average Score per round throughout Game
    char            cardNum, //Number of Cards in a Deck 
              cardFce[FACE]={"A23456789TJQK"},//Array to hold face values
              cardSt[SUITS]={"SHCD"};//Array to hold suit values
              //2DArray for all card values
              //cards[SUITS][FACE]={{"SHCD"},{"A23456789TJQK"}};
              
    string scoreFl, //File to Write Scores to
           crdDeck, //File to Pull Information From
           suit,    //Suit to Be Assigned as String
           number,  //Number to be Assigned as String
           card1,card2,card3,card4,card5,card6, //Player's Cards
           cmpCrd1,cmpCrd2,cmpCrd3,cmpCrd4,     //Computer Cards for Play Phase 
           cStart,       //Starter Card
           crib1,crib2,  //Cards Contributed to the Crib 
           slct1,slct2,  //Cards Selected by Player to Put in Crib
           play1,play2,play3,play4; //Cards Played By Player in Play Phase
    bool   uGoFrst;      //Determine who goes first in order of Play
    
    
    //Initialize Variables
    avgScr=rounds=scrTrck=0;
    cardNum=52; //52 Possible Cards to Draw (A,2-10,J,Q,K, then suits)
    //Initialize Score Arrays
    for (int i=0;i<SIZE;i++) {cmpScr[i]=plyrScr[i]=0;}
    
    cout<<"Welcome to Cribbage**! (**Terms May Apply)"<<endl;
    cout<<"Remember! The Important numbers are 15 and 31."<<endl;
    cout<<"Ace = 1"<<endl<<"Face Cards = 10"<<endl;
    cout<<"During the Play Phase, play off of your opponents cards";
    cout<<" to get 15 or 31."<<endl;
    cout<<"The Crib is a Chance for extra points for you and your opponent!\n";
    cout<<"So Choose Wisely!\n"<<endl;
    cout<<"*Crib Scoring Not Implemented*"<<endl;
    cout<<"*15 and 31 Rules Not Implemented*"<<endl;
    cout<<setw(13)<<"1 Pair ="<<setw(8)<<"2  Points"<<endl;
    cout<<"3 of a Kind ="<<setw(8)<<"6  Points"<<endl;
    cout<<"4 of a Kind ="<<setw(7)<<"12 Points"<<endl<<endl;
    cout<<"**Not an accurate implementation of Cribbage."<<endl;
    cout<<"This is Approximately 1/3 a Game of Cribbage."<<endl;
    cout<<"Score to win has been Adjusted Accordingly."<<endl;
    cout<<"Pairs, 3 of a Kind, and 4 of a Kind";
    cout<<" the only ways to score for now."<<endl<<endl;
    cout<<"Enter \"\\\" at any time to exit the game."<<endl;
    
    //Play a Round
    //Determine whether or not the Game Continues
    while (plyrScr[scrTrck]<MAX_SCR&&cmpScr[scrTrck]<MAX_SCR) {
        numGen(randNum, cardNum);
        //Initialize File Parameters for Card Generation
        crdDeck="card.dat";
        in.open(crdDeck.c_str(),ios::in);
        //Increment Round
        rounds=rounds+1;    
        //"Shuffle" the Cards
        numGen(randNum, cardNum);
            //Card 1    
            //Assign Value Utilizing Switch Case reading from Array
            switch (randNum[0]) {
                                     //Spades
                case 0: card1="AS";break;  case 1: card1="2S"; break;
                case 2: card1="3S";break;  case 3: card1="4S"; break;
                case 4: card1="5S";break;  case 5: card1="6S"; break;
                case 6: card1="7S";break;  case 7: card1="8S"; break;
                case 8: card1="9S";break;  case 9: card1="TS"; break;
                case 10:card1="JS";break;  case 11:card1="QS"; break;
                case 12:card1="KS";break; 
                                     //Hearts
                case 13:card1="AH";break;  case 14:card1="2H"; break;
                case 15:card1="3H";break;  case 16:card1="4H"; break;
                case 17:card1="5H";break;  case 18:card1="6H"; break;
                case 19:card1="7H";break;  case 20:card1="8H"; break;
                case 21:card1="9H";break;  case 22:card1="TH"; break;
                case 23:card1="JH";break;  case 24:card1="QH"; break;
                case 25:card1="KH";break;
                                     //ClubS
                case 26:card1="AC";break;  case 27:card1="2C"; break;
                case 28:card1="3C";break;  case 29:card1="4C"; break;
                case 30:card1="5C";break;  case 31:card1="6C"; break;
                case 32:card1="7C";break;  case 33:card1="8C"; break;
                case 34:card1="9C";break;  case 35:card1="TC"; break;
                case 36:card1="JC";break;  case 37:card1="QC"; break;
                case 38:card1="KC";break;
                                     //Diamonds
                case 39:card1="AD";break;  case 40:card1="2D"; break;
                case 41:card1="3D";break;  case 42:card1="4D"; break;
                case 43:card1="5D";break;  case 44:card1="6D"; break;
                case 45:card1="7D";break;  case 46:card1="8D"; break;
                case 47:card1="9D";break;  case 48:card1="TD"; break;
                case 49:card1="JD";break;  case 50:card1="QD"; break;
                case 51:card1="KD";break;
            }

            //Cards 2, 3, 4, 5, and 6
            //Assign Values Utilizing character arrays and String Addition
            for (int j=1;j<6;j++) {
                number=cardFce[randNum[j]%13];
                suit=cardSt[randNum[j]/13];
                //Add Strings to Create Card Value
                if (j==1) {card2=number+suit;}
                if (j==2) {card3=number+suit;}
                if (j==3) {card4=number+suit;}
                if (j==4) {card5=number+suit;}
                if (j==5) {card6=number+suit;}
            }
                    
            //Cards 7 Through 13 for the Rest of the Round
            //Utilize fstream to Assign Value
            string cardIn;
            for (int card=1;card<=cardNum;card++) {
                //Read in Value from file to cardIn
                in>>cardIn;
                //Add 1 to random number to account for not using an array
                if ((randNum[6]+1)==card)  cStart=cardIn;  //Starter Card for the Round
                if ((randNum[7]+1)==card)  cmpCrd1=cardIn; //First Card for Computer
                if ((randNum[8]+1)==card)  cmpCrd2=cardIn; //Second Card for Computer
                if ((randNum[9]+1)==card) cmpCrd3=cardIn; //Third Card for Computer
                if ((randNum[10]+1)==card) cmpCrd4=cardIn; //Fourth Card for Computer
                if ((randNum[11]+1)==card) crib1=cardIn;   //First Card for the Computer Crib
                if ((randNum[12]+1)==card) crib2=cardIn;   //Second Card for the Computer Crib
        }

        do {
            do{
                //Display Hand
                cout<<setw(22)<<"You've been dealt:"<<endl;
                cout<<setw(4)<<card1;
                cout<<setw(4)<<card2;
                cout<<setw(4)<<card3;
                cout<<setw(4)<<card4;
                cout<<setw(4)<<card5;
                cout<<setw(4)<<card6<<endl<<endl;

                //Ask for Cards to add to the Crib for the Round
                cout<<"Choose two cards to throw to the crib"<<endl;
                //Hold the Players Hand for Teaching Purposes
                cout<<"Enter the number or letter, then the suit for your cards";
                cout<<" then press ENTER"<<endl<<"Example entry: AH 4S"<<endl;
                cin>>setw(2)>>slct1;
                cout<<endl;
                if (slct1=="\\") {exit();}
                //Make Input consistent with Recorded Card Values
                //Break Up String Entries and Cast to Upper Case
                slct1[0]=toupper(slct1[0]); slct1[1]=toupper(slct1[1]);
                //Test to see if Input is Valid
                //Custom Message for Invalid Input
                if (slct1!=card1&&slct1!=card2&&slct1!=card3&&
                    slct1!=card4&&slct1!=card5&&slct1!=card6){
                    cout<<"You Have to put a card in!"<<endl<<endl;
                }
            //If Input is Invalid, Restart Loop    
            }while(slct1!=card1&&slct1!=card2&&slct1!=card3&&
                   slct1!=card4&&slct1!=card5&&slct1!=card6);

            cin>>setw(2)>>slct2;
            cout<<endl;
            if (slct1=="\\") {exit();}
            //Make Input consistent with Recorded Card Values
            //Break Up String Entries and Cast to Upper Case
            slct2[0]=toupper(slct2[0]); slct2[1]=toupper(slct2[1]);

            //Test to see if Input is Valid
            //Custom Message for Invalid Input  
            if (slct2!=card1&&slct2!=card2&&slct2!=card3&&
                slct2!=card4&&slct2!=card5&&slct2!=card6||slct2==slct1){
                cout<<"Hey! Quit hiding cards up your sleeve!"<<endl<<endl;
            }
        //If Input is Invalid, Restart Loop
        }while(slct2!=card1&&slct2!=card2&&slct2!=card3&&
               slct2!=card4&&slct2!=card5&&slct2!=card6||slct2==slct1);

        //Display Selections to the Crib
        cout<<"Your crib:";
        cout<<setw(4)<<slct1;
        cout<<setw(4)<<slct2<<endl<<endl;

        //Display Hand without Crib Selection and Officially Begin Round
        hndDspl(card1,card2,card3,card4,card5,card6,slct1,slct2);



        cout<<setw(16)<<"Starter Card:"<<endl;
        cout<<setw(9)<<cStart<<endl;
        
        //Modulus round Number by 2 to Indicate if True or False
        //round%2 will equal either 0 or 1
        uGoFrst=rounds%2;
        rndScr=0;
        
        //Pass Boolean Value into Switch Case
        switch (uGoFrst) {
            //If uGoFirst=1 (or anything but 0), that is equivalent to "true"
            case true: {
                cout<<"You Go First:"<<endl;
                for (unsigned short myTurn=1;myTurn<=PL_HAND;myTurn++){
                    cout<<"Your Turn"<<endl;
                    cout<<"Play a Card from your Hand:"<<endl;
                    switch (myTurn) {
                        case 1: {
                            //Each Case Starts With A Loop for Input Validation
                            do{//Get Input for Round
                                cin>>setw(2)>>play1;
                                if (play1=="\\") {exit();}
                                play1[0]=toupper(play1[0]); 
                                play1[1]=toupper(play1[1]);
                                //Display Input after Converting to uppercase
                                cout<<play1<<endl;
                                //Message For Invalid Input
                                if (play1!=card1&&play1!=card2
                                    &&play1!=card3&&play1!=card4&&play1!=card5
                                    &&play1!=card6||play1==slct1||play1==slct2){
                                    cout<<"Come on! Play fair."<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play1!=card1&&play1!=card2
                                    &&play1!=card3&&play1!=card4&&play1!=card5
                                    &&play1!=card6||play1==slct1||play1==slct2);
                            //Award Points for Play
                            //Give 2 Points Pair
                            if (play1[0]==cStart[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }case 2: {
                            do {//Get Input for Round
                                cin>>setw(2)>>play2;
                                if (play2=="\\") {exit();}
                                play2[0]=toupper(play2[0]); 
                                play2[1]=toupper(play2[1]);
                                //Display Input after Converting to uppercase
                                cout<<play2<<endl;
                                //Message for Invalid Input
                                if (play2!=card1&&play2!=card2&&play2!=card3
                                    &&play2!=card4&&play2!=card5&&play2!=card6
                                    ||play2==slct1||play2==slct2||play2==play1){
                                    cout<<"Is that even a real card?"<<endl;
                                }
                            //Check if Card is in Hand or has Already been Played    
                            }while (play2!=card1&&play2!=card2&&play2!=card3
                                    &&play2!=card4&&play2!=card5&&play2!=card6
                                    ||play2==slct1||play2==slct2||play2==play1);
                            //Award Points for Play
                            //Give 12 Points for 4 of a Kind
                            if (play2[0]==cmpCrd1[0]
                                &&cmpCrd1[0]==play1[0]
                                &&play1[0]==cStart[0]){
                                plyrScr[scrTrck]+=12;
                                cout<<"12 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 6 Points for 3 of a Kind
                            else if (play2[0]==cmpCrd1[0]
                                     &&cmpCrd1[0]==play1[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play2[0]==cmpCrd1[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }case 3: {
                            do {//Get Input for Round
                                cin>>setw(2)>>play3;
                                if (play3=="\\") {exit();}
                                play3[0]=toupper(play3[0]); 
                                play3[1]=toupper(play3[1]);
                                //Display Input after Converting to uppercase
                                cout<<play3<<endl;
                                //Message for Invalid Input
                                if (play3!=card1&&play3!=card2&&play3!=card3
                                    &&play3!=card4&&play3!=card5&&play3!=card6
                                    ||play3==slct1||play3==slct2||play3==play2
                                    ||play3==play1) {
                                    cout<<"You must be some kind of ";
                                    cout<<"magician or something."<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play3!=card1&&play3!=card2&&play3!=card3
                                    &&play3!=card4&&play3!=card5&&play3!=card6
                                    ||play3==slct1||play3==slct2||play3==play2
                                    ||play3==play1);
                            //Award Points for Play
                            //Give 12 Points for 4 of a Kind
                            if (play3[0]==cmpCrd2[0]
                                &&cmpCrd2[0]==play2[0]
                                &&play2[0]==cmpCrd1[0]){
                                plyrScr[scrTrck]+=12;
                                cout<<"12 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 6 Points for 3 of a Kind
                            else if (play3[0]==cmpCrd2[0]
                                     &&cmpCrd2[0]==play2[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play3[0]==cmpCrd2[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }case 4: {
                            do {//Get Input for Round
                                cin>>setw(2)>>play4;
                                play4[0]=toupper(play4[0]); 
                                play4[1]=toupper(play4[1]);
                                //Display Input after Converting to uppercase
                                cout<<play4<<endl;
                                if (play4=="\\") {exit();}
                                //Message for Invalid Input
                                if (play4!=card1&&play4!=card2&&play4!=card3
                                    &&play4!=card4&&play4!=card5&&play4!=card6
                                    ||play4==slct1||play4==slct2||play4==play3
                                    ||play4==play2||play4==play1) {
                                    cout<<"This is getting old."<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play4!=card1&&play4!=card2&&play4!=card3
                                    &&play4!=card4&&play4!=card5&&play4!=card6
                                    ||play4==slct1||play4==slct2||play4==play3
                                    ||play4==play2||play4==play1);
                            //Award Points for Play
                            //Give 12 Points for 4 of a Kind
                            if (play4[0]==cmpCrd3[0]
                                &&cmpCrd3[0]==play3[0]
                                &&play3[0]==cmpCrd2[0]){
                                plyrScr[scrTrck]+=12;
                                cout<<"12 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 6 Points for 3 of a Kind
                            else if (play4[0]==cmpCrd3[0]
                                     &&cmpCrd3[0]==play3[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play4[0]==cmpCrd3[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }
                    }
                    //Nothing to Check here, just Output the Cards generated
                    //So the player can Play against them
                    //This Game is against pure Chance
                    cout<<"Computer's Turn"<<endl;
                    switch (myTurn) {
                        case 1: {
                            cout<<cmpCrd1<<endl;
                            //Give 6 Points for 3 of a Kind
                            if (cmpCrd1[0]==play1[0]
                                &&play1[0]==cStart[0]){
                                cmpScr[scrTrck]+=6;
                                cout<<"6 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (cmpCrd1[0]==play1[0]) {
                                cmpScr[scrTrck]+=2;
                                cout<<"2 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }
                            break;
                        }case 2: {
                            cout<<cmpCrd2<<endl;
                            //Give 12 Points for 4 of a Kind
                            if (cmpCrd2[0]==play2[0]
                               &&play2[0]==cmpCrd1[0]
                               &&cmpCrd1[0]==play1[0]){
                               cmpScr[scrTrck]+=12;
                               cout<<"12 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            //Give 6 Points for 3 of a Kind
                            }else if (cmpCrd2[0]==play2[0]
                                      &&play2[0]==cmpCrd1[0]){
                                cmpScr[scrTrck]+=6;
                                cout<<"6 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (cmpCrd2[0]==play2[0]) {
                                cmpScr[scrTrck]+=2;
                                cout<<"2 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }
                            break;
                        }case 3: {
                            cout<<cmpCrd3<<endl;
                            //Give 12 Points for 4 of a Kind
                            if (cmpCrd3[0]==play3[0]
                               &&play3[0]==cmpCrd2[0]
                               &&cmpCrd2[0]==play2[0]){
                               cmpScr[scrTrck]+=12;
                               cout<<"12 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            //Give 6 Points for 3 of a Kind
                            }else if (cmpCrd3[0]==play3[0]
                                      &&play3[0]==cmpCrd2[0]){
                                cmpScr[scrTrck]+=6;
                                cout<<"6 Points! The computer now has ";
                                cout<<plyrScr[scrTrck]<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (cmpCrd3[0]==play3[0]) {
                                cmpScr[scrTrck]+=2;
                                cout<<"2 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }
                            break;
                        }case 4: {
                            cout<<cmpCrd4<<endl;
                            //Give 12 Points for 4 of a Kind
                            if (cmpCrd4[0]==play4[0]
                               &&play4[0]==cmpCrd3[0]
                               &&cmpCrd3[0]==play3[0]){
                                cmpScr[scrTrck]+=12;
                                cout<<"12 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            //Give 6 Points for 3 of a Kind
                            }else if (cmpCrd4[0]==play4[0]
                                      &&play4[0]==cmpCrd3[0]){
                                cmpScr[scrTrck]+=6;
                                cout<<"6 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (cmpCrd4[0]==play4[0]) {
                                cmpScr[scrTrck]+=2;
                                cout<<"2 Points! The computer now has ";
                                cout<<cmpScr[scrTrck]<<" Points"<<endl;
                            }
                            break;
                        }
                    }

                }
                //Break from True Case Switch Statement
                break;
            //If uGoFirst=0, that is equivalent to "false"
            }case false: {
                    //Nothing to Check here, just Output the Cards generated
                    //So the player can Play against them
                    //This Game is against pure Chance
                    cout<<"Computer Goes First"<<endl;
                    for (unsigned short yrTurn=CP_HAND;yrTurn>=1;yrTurn--){
                        cout<<"Computer's Turn:"<<endl;
                      //The Switch Case Counts Down Because of the Decrementing
                        switch (yrTurn) {
                            case 4:  {
                                cout<<cmpCrd1<<endl;
                                if (cmpCrd1[0]==cStart[0]) {
                                    cmpScr[scrTrck]+=2;
                                    cout<<"2 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }
                                break;
                            }case 3: {
                                cout<<cmpCrd2<<endl;
                                //Give 12 Points for 4 of a Kind
                                if (cmpCrd2[0]==play1[0]
                                    &&play1[0]==cmpCrd1[0]
                                    &&cmpCrd1[0]==cStart[0]){
                                    cmpScr[scrTrck]+=12;
                                    cout<<"12 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                //Give 6 Points for 3 of a Kind
                                }else if (cmpCrd2[0]==play1[0]
                                          &&play1[0]==cmpCrd1[0]){
                                    cmpScr[scrTrck]+=6;
                                    cout<<"6 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }//Give 2 Points for a Pair
                                else if (cmpCrd2[0]==play1[0]) {
                                    cmpScr[scrTrck]+=2;
                                    cout<<"2 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }
                                break;
                            }case 2: {
                                cout<<cmpCrd3<<endl;
                                //Give 12 Points for 4 of a Kind
                                if (cmpCrd3[0]==play2[0]
                                    &&play2[0]==cmpCrd2[0]
                                    &&cmpCrd2[0]==play1[0]){
                                    cmpScr[scrTrck]+=12;
                                    cout<<"12 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                //Give 6 Points for 3 of a Kind
                                }else if (cmpCrd3[0]==play2[0]
                                          &&play2[0]==cmpCrd2[0]){
                                    cmpScr[scrTrck]+=6;
                                    cout<<"6 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }//Give 2 Points for a Pair
                                else if (cmpCrd3[0]==play2[0]) {
                                    cmpScr[scrTrck]+=2;
                                    cout<<"2 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }
                                break;
                            }case 1: {
                                cout<<cmpCrd4<<endl;
                                //Give 12 Points for 4 of a Kind
                                if (cmpCrd4[0]==play3[0]
                                    &&play3[0]==cmpCrd3[0]
                                    &&cmpCrd3[0]==play2[0]){
                                    cmpScr[scrTrck]+=12;
                                    cout<<"12 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                //Give 6 Points for 3 of a Kind
                                }else if (cmpCrd4[0]==play3[0]
                                          &&play3[0]==cmpCrd3[0]){
                                    cmpScr[scrTrck]+=6;
                                    cout<<"6 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }//Give 2 Points for a Pair
                                else if (cmpCrd4[0]==play3[0]) {
                                    cmpScr[scrTrck]+=2;
                                    cout<<"2 Points! The computer now has ";
                                    cout<<cmpScr[scrTrck]<<" Points"<<endl;
                                }
                                break;
                            }
                        }
                    cout<<"Your Turn:"<<endl;
                    cout<<"Play a Card from your Hand:"<<endl;
                    switch (yrTurn) {
                        case 4: {
                            do {//Get Input for Round
                                cin>>setw(2)>>play1;
                                if (play1=="\\") {exit();}
                                play1[0]=toupper(play1[0]); 
                                play1[1]=toupper(play1[1]);
                                //Display Input after Converting to uppercase
                                cout<<play1<<endl;
                                //Message for Invalid Input
                                if (play1!=card1&&play1!=card2
                                    &&play1!=card3&&play1!=card4&&play1!=card5
                                    &&play1!=card6||play1==slct1||play1==slct2){
                                    cout<<"You must think I was born ";
                                    cout<<"yesterday. "<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play1!=card1&&play1!=card2
                                    &&play1!=card3&&play1!=card4&&play1!=card5
                                    &&play1!=card6||play1==slct1||play1==slct2);
                            //Award Points for Play
                            //Give 6 Points for 3 of a Kind
                            if (play1[0]==cmpCrd1[0]
                                &&cmpCrd1[0]==cStart[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play1[0]==cmpCrd1[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }case 3: {
                            do {//Get Input for Round
                                cin>>setw(2)>>play2;
                                if (play2=="\\") {exit();}
                                play2[0]=toupper(play2[0]); 
                                play2[1]=toupper(play2[1]);
                                //Display Input after Converting to uppercase
                                cout<<play2<<endl;
                                //Message for Invalid Input
                                if(play2!=card1&&play2!=card2&&play2!=card3
                                   &&play2!=card4&&play2!=card5&&play2!=card6
                                   ||play2==slct1||play2==slct2||play2==play1){
                                    cout<<"Where are you getting these";
                                    cout<<" cards from?"<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play2!=card1&&play2!=card2&&play2!=card3
                                    &&play2!=card4&&play2!=card5&&play2!=card6
                                    ||play2==slct1||play2==slct2||play2==play1);
                            //Award Points for Play
                            //Give 12 Points for 4 of a Kind
                            if (play2[0]==cmpCrd2[0]
                                &&cmpCrd2[0]==play1[0]
                                &&play1[0]==cmpCrd1[0]){
                                plyrScr[scrTrck]+=12;
                                cout<<"12 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 6 Points for 3 of a Kind
                            else if (play2[0]==cmpCrd2[0]
                                     &&cmpCrd2[0]==play1[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play2[0]==cmpCrd2[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }case 2: {
                            do {//Get Input for Round
                                cin>>setw(2)>>play3;
                                if (play3=="\\") {exit();}
                                play3[0]=toupper(play3[0]); 
                                play3[1]=toupper(play3[1]);
                                //Display Input after Converting to uppercase
                                cout<<play3<<endl;
                                //Message for Invalid Input
                                if (play3!=card1&&play3!=card2&&play3!=card3
                                    &&play3!=card4&&play3!=card5&&play3!=card6
                                    ||play3==slct1||play3==slct2||play3==play2
                                    ||play3==play1){
                                    cout<<"Nobody likes a cheater."<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play3!=card1&&play3!=card2&&play3!=card3
                                    &&play3!=card4&&play3!=card5&&play3!=card6
                                    ||play3==slct1||play3==slct2||play3==play2
                                    ||play3==play1);
                            //Award Points for Play
                            //Give 12 Points for 4 of a Kind
                            if (play3[0]==cmpCrd3[0]
                                &&cmpCrd3[0]==play2[0]
                                &&play2[0]==cmpCrd1[0]){
                                plyrScr[scrTrck]+=12;
                                cout<<"12 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 6 Points for 3 of a Kind
                            else if (play3[0]==cmpCrd3[0]
                                     &&cmpCrd3[0]==play2[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play3[0]==cmpCrd3[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }case 1: {
                            do {//Get Input for Round
                                //Input for Play
                                cin>>setw(2)>>play4;
                                if (play4=="\\") {exit();}
                                play4[0]=toupper(play4[0]); 
                                play4[1]=toupper(play4[1]);
                                //Display Input after Converting to uppercase
                                cout<<play4<<endl;
                                //Message for Invalid Input
                                if (play4!=card1&&play4!=card2&&play4!=card3
                                    &&play4!=card4&&play4!=card5&&play4!=card6
                                    ||play4==slct1||play4==slct2||play4==play3
                                    ||play4==play2||play4==play1){
                                    cout<<"Work with me, here."<<endl;
                                }
                            //Check if Card is in Hand or Already been Played
                            }while (play4!=card1&&play4!=card2&&play4!=card3
                                    &&play4!=card4&&play4!=card5&&play4!=card6
                                    ||play4==slct1||play4==slct2||play4==play3
                                    ||play4==play2||play4==play1);
                            //Award Points for Play
                            //Give 12 Points for 4 of a Kind
                            if (play4[0]==cmpCrd4[0]
                                &&cmpCrd4[0]==play3[0]
                                &&play3[0]==cmpCrd3[0]){
                                plyrScr[scrTrck]+=12;
                                cout<<"12 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 6 Points for 3 of a Kind
                            else if (play4[0]==cmpCrd4[0]
                                     &&cmpCrd4[0]==play3[0]){
                                plyrScr[scrTrck]+=6;
                                cout<<"6 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }//Give 2 Points for a Pair
                            else if (play4[0]==cmpCrd4[0]) {
                                plyrScr[scrTrck]+=2;
                                cout<<"2 Points! You now have "<<plyrScr[scrTrck];
                                cout<<" Points"<<endl;
                            }
                            break;
                        }
                    }
                }
            //Break from False Case Switch Statement        
            break;
            }
               
        }  
    //End of Round: Determine whether or not the Game Continues
    in.close();
    //Increment Score Tracker
    scrTrck++;
    }
    scrTrck--;
    //if the Player Wins
    if (plyrScr[scrTrck]>cmpScr[scrTrck]) {
        cout<<"Congratulations! You Won!"<<endl;
    }//If the Computer Wins
    else if (cmpScr[scrTrck]>plyrScr[scrTrck]) {
        cout<<"Hey, better luck next time, right?"<<endl;
    }//If there is a tie
    else {
        cout<<"What are the odds of that?    Rematch?"<<endl;
    }
    
    avgScr=static_cast<float>(plyrScr[scrTrck])/static_cast<float>(rounds);
    avgScr=round(avgScr);
    cout<<"You Scored About "<<avgScr<<" Points per Round!"<<endl;
    avgScr=static_cast<float>(plyrScr[scrTrck])/static_cast<float>(rounds);
    cout<<"Or "<<fixed<<setprecision(2)<<avgScr<<" if you like decimals."<<endl;
    
    //Initialize File Parameters for Card Generation
    scoreFl="Score.dat";
    out.open(scoreFl.c_str(),ios::out);
    //Write Scores to File for Storage
    out<<"Your Last Score"<<endl<<plyrScr<<endl;
    
    
    out.close();        
    //Exit the Program - Cleanup 
    return 0;
}
void numGen(vector<int> &randNum, char cardNum) {
    int i=0;
    randNum.clear();//Clear the Vector between Rounds
    do{ 
        int j=0;
        //Generate Random Number
        randNum.push_back(rand()%cardNum);
        //Make Sure Number is not a Duplicates  
        while (j<i) {
            //Conditional statement for if numbers match
            if (randNum[i]==randNum[j]) {
                randNum.pop_back();//clear most recent number added
                i-=1; //Decrement i to fully reverse to last position
            }
            j++;
        }
         i++;
    }while (randNum.size()<13);//only 13 cards in a round
}
//exit function to end the program
//Keep this in place.
void exit() {
    char quit;
    //confirm input
    cout<<"Are you sure you want to quit? Y/N"<<endl;
    cin>>quit;
    quit=toupper(quit);
    //Exit program
    if (quit=='Y') {
        cout<<"I get it, you've got more important things to do"<<endl;
        exit(0);}
    //or send back into game where they left off
    else {
        cout<<"Alright then, take your turn already."<<endl;
    }
}
void hndDspl (string card1,string card2,string card3,string card4,string card5,
              string card6,string slct1,string slct2) {
    //If Cards One and Two are Thrown into the Crib
        if ((slct1==card1&&slct2==card2)||(slct1==card2&&slct2==card1)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card3<<setw(4)<<card4;
                cout<<setw(4)<<card5<<setw(4)<<card6<<endl<<endl;
        //If Cards One and Three are Thrown into the Crib
        }if ((slct1==card1&&slct2==card3)||(slct1==card3&&slct2==card1)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card2<<setw(4)<<card4;
                cout<<setw(4)<<card5<<setw(4)<<card6<<endl<<endl;
        //If Cards One and Four are Thrown into the Crib
        }if ((slct1==card1&&slct2==card4)||(slct1==card4&&slct2==card1)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card2<<setw(4)<<card3;
                cout<<setw(4)<<card5<<setw(4)<<card6<<endl<<endl;
        //If Cards One and Five are Thrown into the Crib
        }if ((slct1==card1&&slct2==card5)||(slct1==card5&&slct2==card1)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card2<<setw(4)<<card3;
                cout<<setw(4)<<card4<<setw(4)<<card6<<endl<<endl;
        //If Cards One and Six are Thrown into the Crib
        }if ((slct1==card1&&slct2==card6)||(slct1==card6&&slct2==card1)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card2<<setw(4)<<card3;
                cout<<setw(4)<<card4<<setw(4)<<card5<<endl<<endl;
        //If Cards Two and Three are Thrown into the Crib
        }if ((slct1==card2&&slct2==card3)||(slct1==card3&&slct2==card2)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card4;
                cout<<setw(4)<<card5<<setw(4)<<card6<<endl<<endl;
        //If Cards Two and Four are Thrown into the Crib
        }if ((slct1==card2&&slct2==card4)||(slct1==card4&&slct2==card2)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card3;
                cout<<setw(4)<<card5<<setw(4)<<card6<<endl<<endl;
        //If Cards Two and Five are Thrown into the Crib
        }if ((slct1==card2&&slct2==card5)||(slct2==card5&&slct1==card2)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card3;
                cout<<setw(4)<<card4<<setw(4)<<card6<<endl<<endl;
        //If Cards Two and Six are Thrown into the Crib
        }if ((slct1==card2&&slct2==card6)||(slct1==card6&&slct2==card2)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card3;
                cout<<setw(4)<<card4<<setw(4)<<card5<<endl<<endl;
        //If Cards Three and Four are Thrown into the Crib
        }if ((slct1==card3&&slct2==card4)||(slct1==card4&&slct2==card3)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card2;
                cout<<setw(4)<<card5<<setw(4)<<card6<<endl<<endl;
        //If Cards Three and Five are Thrown into the Crib
        }if ((slct1==card3&&slct2==card5)||(slct1==card5&&slct2==card3)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card2;
                cout<<setw(4)<<card4<<setw(4)<<card6<<endl<<endl;
        //If Cards Three and Six are Thrown into the Crib
        }if ((slct1==card3&&slct2==card6)||(slct1==card6&&slct2==card3)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card2;
                cout<<setw(4)<<card4<<setw(4)<<card5<<endl<<endl;
        //If Cards Four and Five are Thrown into the Crib        
        }if ((slct1==card4&&slct2==card5)||(slct1==card5&&slct2==card4)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card2;
                cout<<setw(4)<<card3<<setw(4)<<card6<<endl<<endl;
        //If Cards Four and Six are Thrown into the Crib                
        }if ((slct1==card4&&slct2==card6)||(slct1==card6&&slct2==card4)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card2;
                cout<<setw(4)<<card3<<setw(4)<<card5<<endl<<endl;
        //If Cards Five and Six are Thrown into the Crib                    
        }if ((slct1==card5&&slct2==card6)||(slct1==card6&&slct2==card5)) {
                cout<<setw(14)<<"Your Hand:"<<endl;
                cout<<setw(4)<<card1<<setw(4)<<card2;
                cout<<setw(4)<<card3<<setw(4)<<card4<<endl<<endl;
        }
}
int mgcNum (int &rndScr,string play, int [], int arr[],int scrTrck) {
    return 0;
}