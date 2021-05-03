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
void getData(string);
void encrypt(string);
void decrypt(string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    //const short SIZE=4;
    string n;
    char choice;
    
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
    
    
    getData(n);
    
    //Map Inputs to Outputs -> Process
    if (choice=='E'){
        encrypt(n);
    }
    if (choice=='D'){
        decrypt(n);
    }

    //Display Inputs/Outputs
    cout<<n;
      
    //Exit the Program - Cleanup
    return 0;
}

void getData(string n){
    bool isVld; //Bool to test if input is valid
    
    do {
        isVld=1;
        cin>>n;
        //cout<<n.size()<<endl;
        
        if (n.size()!=4){
            cout<<"Incorrect Number of digits."<<endl;
        }
        
        for(int i=0;i<4;i++){

            if (static_cast<unsigned int>(n[i])-48>7){
                cout<<n[i]<<" Is an invalid input, please input 4 digits ";
                cout<<"between 0 and 7."<<endl;
                isVld=0;
            }
        }
    }while (isVld==0); 
}
void encrypt(string n){
    char temp[n.size()];
    
    cout<<"Encryption: "<<endl;
    
    for (int i=0;i<n.size();i++){
        n[i]=((static_cast<unsigned int>(n[i])-43)%8)+48;        
    }
    cout<<n;
    for (int j=0,k=2;j<n.size()/2;j++,k++){
        temp[j]=n[k];
        temp[k]=n[j];
        cout<<temp[j];
        cout<<n[k];
    }
    cout<<temp;
    cout<<n;
    for(int i=0;i<n.size();i++){
        n[i]=temp[i];
    }
    
}
void decrypt(string n){
    string temp;
    
    cout<<"Decryption: "<<endl;
    
    for (int i=0;i<n.size();i++){
        n[i]=(n[i]-5<48?n[i]+3:n[i]-5);
    }
    
    for (int j=0,k=2;j<n.size()/2;j++,k++){
        temp[j]=n[k];
        temp[k]=n[j];
    
    }
    
    for(int i=0;i<n.size();i++){
        n[i]=temp[i];
    }
    
}