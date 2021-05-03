/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To utilize an array of structures that will determine the gross
 *           pay for any number of employees input and output a check
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
#include <sstream>
#include <cstring>

using namespace std;

//User Libraries
#include "Pay.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
Pay *getData(int); //Creates an array of structures
void prntChk(Pay *);
void cleanUp(Pay *); //Reallocate memory
string english(float);
float hrCalc(int,float);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int size;
    Pay *check;
    
    //Initialize Variables
    cout<<"How many employees are on your payroll?"<<endl;
    cin>>size;

    check=getData(size);
    //Map Inputs to Outputs -> Process

    //Display Inputs/Outputs
    prntChk(check);
    //Exit the Program - Cleanup
    cleanUp(check);
    return 0;
}
Pay *getData(int n){
    bool isVal=1;
    Pay *check=new Pay[n];
    check->numWrkr=0;
    
    for(int i=0, j=1;i<n&&isVal==1;i++,j++){
        
        cout<<"Input Employee name: "<<endl;
        cin.ignore(100,'\n');
        getline(cin,check[i].name);
        cout<<"Input Hours Worked this Week: "<<endl;
        cin>>check[i].hrsWrkd;
        if(check[i].hrsWrkd>=0){
            if(check[i].hrsWrkd>112&&check[i].hrsWrkd<161){
            cout<<"These hours are valid, but we legally need to inform OSHA";
            cout<<" about this."<<endl;
            }
            cout<<"Input Hourly Pay Rate: \n$";
            cin>>check[i].payRte;
            if(check[i].payRte<0||check[i].payRte>100){
                cout<<"Invalid Pay Rate."<<endl;
                if (check[i].payRte>100){
                    cout<<"Over $100 an hour!? What kind of job pays that?\n\n";
                }else if(check[i].payRte<0){
                    cout<<"Is this employee literally paying you to";
                    cout<<"work for them?\n The benefits must be amazing!\n\n";
                }
                isVal=0;
            }else{
                check[i].ttlPay=hrCalc(check[i].hrsWrkd,check[i].payRte);
                check->numWrkr=j;
                check[i].engl=english(check[i].ttlPay);
            }
        }else if(check[i].hrsWrkd<0||check[i].hrsWrkd>160){
            cout<<"Impossible number of hours."<<endl;
            isVal=0;
        }
    }
    
   return check;
}
float hrCalc(int a, float b){
    float ttl=0;
    float ovrTme=0;
    
    //Break Overtime up into Double Time and Triple Time
    ovrTme=(a>40&&a<50)?((a-40)*(b*2)):
           (a>=50)?(((b*2)*10)+((a-50)*(b*3))):0;
    //Calculate Total Pay
    //Distinguish Between Straight Time Hours and Overtime 
    ttl=(a<=40)?a*b:b*40+ovrTme;

    return ttl;
}
void prntChk(Pay *check){
    for(int i=0;i<check->numWrkr;i++){
        if (check[i].ttlPay<=1.00){
            cout<<"This check was more expensive than your labor.\n\n";
        }
        cout<<"2-Bit Programming"<<endl;
        cout<<"312 Desktop Avenue"<<endl;
        
        cout<<"Pay to the Order of: "<<check[i].name<<setw(34-check[i].name.size());
        cout<<fixed<<setprecision(2)<<showpoint<<"$"<<check[i].ttlPay<<endl;
        cout<<"Amount: "<<check[i].engl<<endl<<endl;
    }
}
string english(float a){
    string   fnl,
           thsnd,
           hndrd,
             ten,
             one,
         strDcml;
    stringstream ss;
    unsigned int n=static_cast<int>(a),
        n1000=n/1000,
        n100=n%1000/100,
        n10=n%100/10,
        n1=n%10,
        dcml=static_cast<unsigned int>(a*100)%100;

    //Output the check value
    thsnd=(n1000==39?"Thirty Nine Thousand ":
           n1000==38?"Thirty Eight Thousand ":
           n1000==37?"Thirty Seven Thousand ":
           n1000==36?"Thirty Six Thousand ":
           n1000==35?"Thirty Five Thousand ":
           n1000==34?"Thirty Four Thousand ":
           n1000==33?"Thirty Three Thousand ":
           n1000==32?"Thirty Two Thousand ":
           n1000==31?"Thirty One Thousand ":
           n1000==30?"Thirty Thousand ":
           n1000==29?"Twenty Nine Thousand ": 
           n1000==28?"Twenty Eight Thousand ":
           n1000==27?"Twenty Seven Thousand ":
           n1000==26?"Twenty Six Thousand ": 
           n1000==25?"Twenty Five Thousand ":
           n1000==24?"Twenty Four Thousand ":
           n1000==23?"Twenty Three Thousand ": 
           n1000==22?"Twenty Two Thousand ":
           n1000==21?"Twenty One Thousand ":
           n1000==20?"Twenty Thousand ": 
           n1000==19?"Nineteen Thousand ":
           n1000==18?"Eighteen Thousand ":
           n1000==17?"Seventeen Thousand ":
           n1000==16?"Sixteen Thousand ":
           n1000==15?"Fifteen Thousand ":
           n1000==14?"Fourteen Thousand ":
           n1000==13?"Thirteen Thousand ":
           n1000==12?"Twelve Thousand ":
           n1000==11?"Eleven Thousand ":
           n1000==10?"Ten Thousand ":
           n1000==9?"Nine Thousand ":
           n1000==8?"Eight Thousand ":
           n1000==7?"Seven Thousand ":
           n1000==6?"Six Thousand ":
           n1000==5?"Five Thousand ":
           n1000==3?"Four Thousand ":
           n1000==3?"Three Thousand ":
           n1000==2?"Two Thousand ":
           n1000==1?"One Thousand ":"");

    hndrd=(n100==9?"Nine Hundred ":
           n100==8?"Eight Hundred ":
           n100==7?"Seven Hundred ":
           n100==6?"Six Hundred ":
           n100==5?"Five Hundred ":
           n100==4?"Four Hundred ":
           n100==3?"Three Hundred ":
           n100==2?"Two Hundred ":
           n100==1?"One Hundred ":"");

    //Test for Tens Place for "Teens", Twelve, and Eleven     
    if (n10==1){
        ten=(n1==9?"Nineteen ":
             n1==8?"Eighteen ":
             n1==7?"Seventeen ":
             n1==6?"Sixteen ":
             n1==5?"Fifteen ":
             n1==4?"Fourteen ":
             n1==3?"Thirteen ":
             n1==2?"Twelve ":
             n1==1?"Eleven ":"Ten ");
    //Separate Everything Else           
    }else{
        ten=(n10==9?"Ninety ":
             n10==8?"Eighty ":
             n10==7?"Seventy ":
             n10==6?"Sixty ":
             n10==5?"Fifty ":
             n10==4?"Forty ":
             n10==3?"Thirty ":
             n10==2?"Twenty ":"");
        one=(n1==9?"Nine ":
             n1==8?"Eight ":
             n1==7?"Seven ":
             n1==6?"Six ":
             n1==5?"Five ":
             n1==4?"Four ":
             n1==3?"Three ":
             n1==2?"Two ":
             n1==1?"One ":"");

    }
    if(dcml!=0){
        ss<<dcml;
        ss>>strDcml;
    }else{
        strDcml="no";
    }
   
    fnl=thsnd+hndrd+ten+one+"and "+strDcml+"/100 Dollars";
    
    return fnl;
}
void cleanUp(Pay *check){
    delete []check;
}