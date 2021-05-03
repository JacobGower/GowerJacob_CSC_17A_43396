/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To Encrypt and Decrypt 4 digit integers
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
void encrypt(char [], const short); //
void decrypt(char [], const short); //

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const short SIZE=4;
    char n[SIZE];
    string test;
    char choice;
    bool isVal; //Bool to test if input is valid
    
    //Initialize Variables
    
   do{
        cout<<"Would you like to Encrypt or Decrypt a 4 digit integer?"<<endl;
        cout<<"Please enter 'E' for Encryption or 'D' for Decryption: ";
        cin>>choice;
        choice=toupper(choice);
        if(choice!='E'&&choice!='D'){
            cout<<endl<<"Invalid Selection. Please select 'E' or 'D'"<<endl;
        }
   }while (choice!='E'&&choice!='D');
    
    cout<<"Please input a 4 digit integer with digits between 0 and 7."<<endl;
    
    
    
    do {
        isVal=1;
        
        cin>>test;
        if (test.size()!=SIZE){
            cout<<"You entered "<<test.size()<<" digits."<<endl;
            cout<<"Please enter 4 digits"<<endl;
        }
            for(int i=0;i<test.size();i++){
                n[i]=test[i];
                if (static_cast<unsigned int>(n[i])-48>7){
                    cout<<n[i]<<" Is an invalid input, please input 4 digits ";
                    cout<<"between 0 and 7."<<endl;
                    isVal=0;
                    
                }
            }
    }while (isVal==0||test.size()!=SIZE);
    
    for(int j=0;j<SIZE;j++){
        cout<<n[j];
    }
    cout<<endl<<endl;
    
    if (choice=='E'){
        encrypt(n,SIZE);
    }
    if (choice=='D'){
        decrypt(n,SIZE);
    }
    
    
    
    //Map Inputs to Outputs -> Process

    //Display Inputs/Outputs
    for(int j=0;j<SIZE;j++){
        cout<<static_cast<int>(n[j])-48;
    }
    cout<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}

void encrypt(char n[], const short SIZE){
    char temp[SIZE];
    
    for (int i=0;i<SIZE;i++){
        n[i]=((static_cast<unsigned int>(n[i])-43)%8)+48;        
    }
    
    for (int j=0,k=2;j<SIZE/2;j++,k++){
        temp[j]=n[k];
        temp[k]=n[j];
    
    }
    
    for(int i=0;i<SIZE;i++){
        n[i]=temp[i];
    }
    
}
void decrypt(char n[], const short SIZE){
    char temp[SIZE];
    
    for (int i=0;i<SIZE;i++){
        n[i]=(n[i]-5<48?n[i]+3:n[i]-5);
    }
    
    for (int j=0,k=2;j<SIZE/2;j++,k++){
        temp[j]=n[k];
        temp[k]=n[j];
    
    }
    
    for(int i=0;i<SIZE;i++){
        n[i]=temp[i];
    }
    
}