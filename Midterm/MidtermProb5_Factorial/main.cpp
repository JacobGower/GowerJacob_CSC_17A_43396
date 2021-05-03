/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To Determine the Largest Factorial each Data type can Handle
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
void chctr();
void unChctr();
void shrt();
void unShrt();
void intgr();
void unIntgr();
void lngnt();
void unLngnt();
void lnlnt();
void unLnlnt();
void flot();
void dble();
void lngDble();
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    
    //Initialize Variables
     
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    chctr();
    unChctr();
    shrt();
    unShrt();
    intgr();
    unIntgr();
    lngnt();
    unLngnt();
    lnlnt();
    unLnlnt();
    flot();
    dble();
    lngDble();
      
    //Exit the Program - Cleanup
    return 0;
}
void chctr(){
    char n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<static_cast<int>(n2)<<endl;
        //cout<<"Current n value = "<<static_cast<int>(i)<<endl;
        //cout<<static_cast<int>(i)<<"! = "<<static_cast<int>(n1)<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the char data type can handle before overflow is:"<<endl;
    cout<<"n="<<static_cast<int>(i)<<endl;
    cout<<static_cast<int>(i)<<"! = "<<static_cast<int>(n1)<<endl;
    cout<<"ERROR: "<<static_cast<int>(i)+1<<"! != "<<static_cast<int>(n2);
    cout<<endl<<endl;
}
void unChctr(){
    unsigned char n1=1,n2=1,i=1;
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<static_cast<int>(n2)<<endl;
        //cout<<"Current n value = "<<static_cast<int>(i)<<endl;
        //cout<<static_cast<int>(i)<<"! = "<<static_cast<int>(n1)<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the unsigned char data type can handle before overflow is:"<<endl;
    cout<<"n="<<static_cast<int>(i)<<endl;
    cout<<static_cast<int>(i)<<"! = "<<static_cast<int>(n1)<<endl;
    cout<<"ERROR: "<<static_cast<int>(i)+1<<"! != "<<static_cast<int>(n2);
    cout<<endl<<endl;
}
void shrt(){
   short n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the short data type can handle before overflow is:"<<endl;
    cout<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}
void unShrt(){
    unsigned short n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the unsigned short data type can handle before overflow is:"<<endl;
    cout<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}
void intgr(){
    int n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the integer data type can handle before overflow is:"<<endl;
    cout<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl; 
}
void unIntgr(){
    unsigned int n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the unsigned integer data type can handle before overflow is:"<<endl;
    cout<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl; 
}
void lngnt(){
    long n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        ///cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the long integer data type can handle before overflow is:"<<endl;
    cout<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl; 
}
void unLngnt(){
    unsigned long n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the unsigned long integer data type can handle before overflow is:";
    cout<<endl<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl; 
}
void lnlnt(){
    long long n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the long long integer data type can handle before overflow is:";
    cout<<endl<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}
void unLnlnt(){
    unsigned long long n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<n2<<endl;
        //cout<<"Current n value = "<<i<<endl;
        //cout<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the unsigned long long integer data type can handle before";
    cout<<" overflow is:"<<endl<<"n="<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}
void flot(){
    float n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<fixed<<setprecision(2)<<n2<<endl;
        //cout<<"Current n value = "<<fixed<<i<<endl;
        //cout<<fixed<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the float data type can handle before";
    cout<<" overflow is:"<<endl<<"n="<<fixed<<setprecision(2)<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}
void dble(){
    double n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<fixed<<setprecision(2)<<n2<<endl;
        //cout<<"Current n value = "<<fixed<<i<<endl;
        //cout<<fixed<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the float data type can handle before";
    cout<<" overflow is:"<<endl<<"n="<<fixed<<setprecision(2)<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}
void lngDble(){
    long double n1=1,n2=1,i=1; 
    do{
        n1*=i;
        n2*=i+1;
        //cout<<"Current n+1 value = "<<fixed<<setprecision(2)<<n2<<endl;
        //cout<<"Current n value = "<<fixed<<i<<endl;
        //cout<<fixed<<i<<"! = "<<n1<<endl;
        i++;
    }while(n2/n1==i);
    if ((n2/n1!=i)){
        i--;
    }
    cout<<"For the equation n! the largest value of n that";
    cout<<" the long double data type can handle before";
    cout<<" overflow is:"<<endl<<"n="<<fixed<<setprecision(2)<<i<<endl;
    cout<<i<<"! = "<<n1<<endl;
    cout<<"ERROR: "<<i+1<<"! != "<<n2<<endl<<endl;
}