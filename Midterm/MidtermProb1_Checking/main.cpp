/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To Utilize structures and dynamic memory to report a user's
 *           account balance and whether they have overdrawn
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries
#include "Account.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
Account *getData(int, int); //Handles input for Account Information
void prntAct(Account *);    
void numVal(Account *);     //Makes sure input for account number is valid
void cleanUp(Account *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    Account *data;
    int numDpst,
        numChck;
    //Initialize Variables
    
    cout<<"Welcome to The Bank of Mark™"<<endl;
    
    //Map Inputs to Outputs -> Process
    data=getData(numChck, numDpst);
   
    //Display Inputs/Outputs
     prntAct(data);
     
    //Exit the Program - Cleanup
    cleanUp(data);
    
    return 0;
}
Account *getData(int n, int m){
    //Declare and allocate the array
    Account *data=new Account;
    
    
    cout<<"Please Enter Account Holder's name: "<<endl;
    getline(cin, data->name);
    cout<<endl<<"Please enter the Address associated with this account: "<<endl;
    getline(cin, data->address);
    
    numVal(data);
        
    
    cout<<endl<<"Due to an internal error, we have lost your account balance.";
    cout<<endl<<"Please enter how much money you think you had when ";
    cout<<"this month started:\n$";
    cin>>data->ogBlnc;
    
    if(data->ogBlnc<0){
        cout<<"Wow. Really? You could lie and we would believe you."<<endl;
        cout<<endl<<"Good on you for being honest."<<endl;
    }
    
    data->newBlnc=data->ogBlnc;
    
    cout<<endl<<"Enter the total number of checks written this month: ";
    cin>>n;
    cout<<endl<<"Enter the total number of deposits made this month: ";
    cin>>m;
    
    
    data->checks=new float[n];
    data->dpsts=new float[m];
    data->chckSze=n;
    data->dpstSze=m;
    
    for(int i=0;i<data->chckSze;i++){
        cout<<endl<<"Please enter the dollar amount for check #"<<i+1<<": $";
        cin>>data->checks[i];
        data->newBlnc-=data->checks[i];
    }
    for(int i=0;i<data->dpstSze;i++){
        cout<<endl<<"Please enter the dollar amount for deposit #"<<i+1<<": $";
        cin>>data->dpsts[i];
        data->newBlnc+=data->dpsts[i];
    }
    
    data->newBlnc=(data->newBlnc<0?data->newBlnc-20:data->newBlnc);
        
    return data;
}
void prntAct(Account *data){
    
    
    cout<<endl<<"Account Holder:"<<setw(28)<<data->name<<endl;
    cout<<"Address:"<<setw(35)<<data->address<<endl;
    cout<<"Account Number:"<<setw(28)<<data->acctNum<<endl;
    
    cout<<"Starting Balance:"<<setw(18);
    cout<<fixed<<setprecision(2)<<showpoint<<"$"<<data->ogBlnc<<endl;
    
    
    if(data->newBlnc<0){
       
        cout<<"Current Balance:"<<setw(19);
        cout<<fixed<<setprecision(2)<<showpoint<<"$"<<data->newBlnc+20<<endl;
        
        cout<<endl<<"ALERT: YOU HAVE OVERDRAWN YOUR ACCOUNT."<<endl;
        cout<<"YOU HAVE BEEN CHARGED A 20$ CONVENIENCE FEE"<<endl<<endl;
    }
    
    cout<<"Current Balance:"<<setw(19);
    cout<<fixed<<setprecision(2)<<showpoint<<"$"<<data->newBlnc<<endl;
    
    cout<<endl<<"The Bank of Mark™ thanks you for your business."<<endl;
    
}
void numVal(Account *data){
    bool isVld; //Bool to test if input for account number is valid
    
    do {
        isVld=1;
        cout<<endl<<"Please enter the 5 digit account number: "<<endl;
        
        cin>>data->acctNum;
        
        if (data->acctNum.size()!=5){
            cout<<"You entered "<<data->acctNum.size()<<" digits."<<endl;
        }
        for(int i=0;i<data->acctNum.size();i++){
            
            if (static_cast<unsigned int>(data->acctNum[i])-48>9){
                cout<<data->acctNum[i]<<" Is an invalid input"<<endl;
                isVld=0;
            }
        }
    }while (isVld==0||data->acctNum.size()!=5); 
}
void cleanUp(Account *data){
    delete []data->checks;
    delete []data->dpsts;
    delete data;
}