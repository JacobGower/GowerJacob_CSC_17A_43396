/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on January 4, 2021, 11:16 AM
 * Purpose:  To Encrypt and Decrypt 4 digit integers
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
#include <sstream>
#include <cstring>
using namespace std;

//User Libraries
#include "Account.h"
#include "Pay.h"
#include "Array.h"
#include "Stats.h"
#include "Prime.h"
#include "Primes.h"

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes

void Menu();
unsigned short getN(unsigned short);

//111111111111111111111111111111111111111111111111111111111111111111111111111111
//111111111111111111111111111111111111111111111111111111111111111111111111111111

void problem1();
Account *getData(int, int); //Handles input for Account Information
void prntAct(Account *);    
void numVal(Account *);     //Makes sure input for account number is valid
void destroy(Account *);

//222222222222222222222222222222222222222222222222222222222222222222222222222222
//222222222222222222222222222222222222222222222222222222222222222222222222222222

void problem2();
Pay *getData(int); //Creates an array of structures
void prntChk(Pay *);
void cleanUp(Pay *); //Reallocate memory
string english(float);
float hrCalc(int,float);

//333333333333333333333333333333333333333333333333333333333333333333333333333333
//333333333333333333333333333333333333333333333333333333333333333333333333333333

void problem3();
//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in stru

//444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444

void problem4();
void encrypt(char [], const short); //Encrypts input to specifications
void decrypt(char [], const short); //Decrypts input to specifications

//555555555555555555555555555555555555555555555555555555555555555555555555555555
//555555555555555555555555555555555555555555555555555555555555555555555555555555

void problem5();
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

//666666666666666666666666666666666666666666666666666666666666666666666666666666
//666666666666666666666666666666666666666666666666666666666666666666666666666666

void problem6();

//777777777777777777777777777777777777777777777777777777777777777777777777777777
//777777777777777777777777777777777777777777777777777777777777777777777777777777

void problem7();
Primes *factor(int); //Input an integer, return all prime factors
void prntPrm(Primes *); //-> Output all prime factors
void cleanUp(Primes *); 

unsigned short def(unsigned short);


//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    unsigned short inN;
        
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    //This is what I thought the instructions were saying to do for the Stat
    //Problem. I should have asked, but at this point I'm just going to include.
    problem3();
    do{
         Menu();
         inN=getN(inN);
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    cout<<"Problem 3 runs before the menu.\n";break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   def(inN);}
        }while(inN<8&&inN>0);

    //Display Inputs/Outputs
   
    //Exit the Program - Cleanup
    return 0;
}
void Menu(){
    cout<<"Please select a number 1-7 to view a problem with it's solution:\n";
}
unsigned short getN(unsigned short inN){
    cin>>inN;
    return inN;
}

//111111111111111111111111111111111111111111111111111111111111111111111111111111
//111111111111111111111111111111111111111111111111111111111111111111111111111111

void problem1(){
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
    destroy(data);
}
Account *getData(int n, int m){
    //Declare and allocate the array
    Account *data=new Account;
    
    
    cin.ignore(100,'\n');
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
void destroy(Account *data){
    delete []data->checks;
    delete []data->dpsts;
    delete data;
}

//222222222222222222222222222222222222222222222222222222222222222222222222222222
//222222222222222222222222222222222222222222222222222222222222222222222222222222

void problem2(){
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

//333333333333333333333333333333333333333333333333333333333333333333333333333333
//333333333333333333333333333333333333333333333333333333333333333333333333333333

void problem3(){
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
}
int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    
    cout<<endl<<"Stat function that was completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    stats->modFreq=0;
    stats->avg=0;
    int nModes=0,
         count=0;
    
    //Let's mix and match pointer notation for giggles
    for(int i=0;i<array->size;i++){
        //When i==0 there is no previous element, so just increment
        if(i==0){
            count++;
        //Test if current element matches previous element
        }else if(*((*array).data+i)==*((*array).data+(i-1))){
            //If match is detected, increment counter
            count++;
        }else{
            //If no match is detected, reset counter
            count=1;
        }
        //Use counter to set frequency
        if(count>stats->modFreq){
            //If counter is larger than current max frequency
            //set frequency equal to counter
            stats->modFreq=count;
        }
        stats->avg+=*((*array).data+i);
    }
    (*stats).avg/=array->size;
    count=0;
    for(int i=0;i<array->size;i++){
        //Increment counter the same way
        if(i==0){
            count++;
        
        }else if(array->data[i]==(*array).data[i-1]){
            //If match is detected, increment counter
            count++;
        }else{
            //If no match is detected, reset counter
            count=1;
        }
        //If counter equals max frequency and is greater than one, then it is a mode.
        if(count==(*stats).modFreq&&count>1){
            //Increment number of modes
            nModes++;
        }
    }
    //Set the size that can be passed through the structure equal to the
    //number of modes
    (*stats).mode->size=nModes;
    
    if(nModes!=0)stats->mode->data=new int[nModes];
    count=0;
    for(int i=0,j=0;i<array->size;i++){
        //Find modes with the same method
        if(i==0){
            count++;
        }else if(*((*array).data+i)==array->data[i-1]){
            count++;
        }else{
            count=1;
        }
        //If count is greater than 1 and count is equal to max frequency, then it is a mode and goes into the array
        
        if(count==stats->modFreq&&count>1){
            //Use separate counter for mode Array since the positions in the different arrays will not necessarily correspond
            *(stats->mode->data+j)=array->data[i];
            //Increment the stats->mode->data position
            j++;
        }
    }
    //Initialize median value
    stats->median=0;
    //Test to see if array size is even
    if((*array).size%2==0){
        //If array has even number of values, add two middle values together
        //and divide by 2.0f
        //Static cast values as floats and append literal with f to make sure
        //that not integer division happens
        stats->median=(static_cast<float>(*((*array).data+(((array->size)/2)-1)))
                      +static_cast<float>(array->data[((array->size)/2)]))/2.0f;
    }else{
        //If array has odd number of values, then mode is just the value in the
        //middle position
        stats->median=array->data[((array->size)/2)];
    }
    return stats;
}

//444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444

void problem4(){
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

//555555555555555555555555555555555555555555555555555555555555555555555555555555
//555555555555555555555555555555555555555555555555555555555555555555555555555555

void problem5(){
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
    cout<<endl;
      
    //Exit the Program - Cleanup 
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

//666666666666666666666666666666666666666666666666666666666666666666666666666666
//666666666666666666666666666666666666666666666666666666666666666666666666666666

void problem6(){
    //Display Inputs/Outputs
    cout<<"Part a)"<<endl;
    cout<<"\tBase 10: 2.875 =\n";
    cout<<"\t\tBase 2:  10.111\n\t\tBase 8:  2.7\n\t\tBase 16: 2.E\n";
    cout<<"\t\tNASA Format Base 2:  01011100000000000000000000000010\n";
    cout<<"\t\tNASA Format Base 16: 5C000002\n";
    cout<<"\tBase 10: 0.1796875 =\n";
    cout<<"\t\tBase 2:  0.0010111\n\t\tBase 8:  0.134\n\t\tBase 16: 0.2E\n";
    cout<<"\t\tNASA Format Base 2:  01011100000000000000000011111110\n";
    cout<<"\t\tNASA Format Base 16: 5C0000FE\n";
    
    cout<<"Part b)"<<endl;
    cout<<"\tBase 10: -2.875 =\n";
    cout<<"\t\tNASA Format Base 2:  10100100000000000000000000000010\n";
    cout<<"\t\tNASA Format Base 16: A4000002\n";
    cout<<"\tBase 10: -0.1796875 =\n";
    cout<<"\t\tNASA Format Base 2:  10100100000000000000000011111110\n";
    cout<<"\t\tNASA Format Base 16: A40000FE\n";
    
    cout<<"Part c)"<<endl;
    cout<<"\tNASA Format Base 16: 59999901 = \n";
    cout<<"\t\tNASA Format Base 2:  01011001100110011001100100000001\n";
    cout<<"\t\tBase 10: 1.390625\n";
    cout<<"\tNASA Format Base 16: 59999902 = \n";
    cout<<"\t\tNASA Format Base 2:  01011001100110011001100100000010\n";
    cout<<"\t\tBase 10: 2.78125\n";
    cout<<"\tNASA Format Base 16: A66667FE = \n";
    cout<<"\t\tNASA Format Base 2:  10100110011001100110011111111110\n";
    cout<<"\t\tBase 10: -0.173828125\n";
    
    //Exit the Program - Cleanup  
}

//777777777777777777777777777777777777777777777777777777777777777777777777777777
//777777777777777777777777777777777777777777777777777777777777777777777777777777

void problem7(){
    //Declare Variables
    int num; //Number between 2 and 10000 input by user
    Primes *array; //Pointer to dynamic array structure
    
    
    num=0;
    //Initialize Variables
    cout<<"Enter a number to check for prime factors."<<endl;
    do{ 
        cin>>num;
        if(num<2||num>10000){
        cout<<"Invalid Input. Input must be between 2 and 10000.\n";    
        }
    }while (num<2||num>10000);
    
    //Fill the Array
    array=factor(num);
    
    //Map Inputs to Outputs -> Process
    

    //Display Inputs/Outputs
    //Print the Array
    prntPrm(array);
      
    //Exit the Program - Cleanup
    //Reallocate memory
    cleanUp(array);
    //delete array;
}
void cleanUp(Primes *array){
    //Just like Dr. Lehr showed us, work from the inner array outward
    delete []array->prime;
    delete array;
}

Primes *factor(int n){ //Input an integer, return all prime factors
    //Allocate memory for the structure
    Primes *array=new Primes;
    //Allocate memory for the array inside of the structure
    array->prime=new Prime[n];
    //Initialize number of Primes variable to 1, since it will have at least 1
    array->nPrimes=1;
    //Initialize 0 position to input, to allow it to pass between functions
    array->prime[0].prime=n;
    //Initialize 1 position to 0 have something to work with
    array->prime[1].prime=0;
    //Initialize 0 position to 0 to have it initialized to something
    array->prime[0].power=0;
    //Create temp variable to avoid changing input
    int temp=n, loops=0;
    
    //For loop going from 2 to the temp variable to try avoid excessive looping
    for(int i=2, j=1;i<=temp;i++){
        loops=i;
        //Test with mod operator to see if temp is divisible by iterator
        if(temp%i==0){
            //cout<<temp<<" / "<<i<<" = ";
            //If it is divisible, then divide and set new value for temp
            temp/=i;
            //cout<<temp<<endl;
            
            //If 1 position is not filled, then fill first position
            //Set position equal to iterator
            if(array->prime[1].prime==0){
                array->prime[1].prime=i;
            }
            
            //If Prime factor in current position is not equal to iterator
            if(array->prime[j].prime!=i){
                //Increment position
                j++;
                //Increment number of prime factors
                array->nPrimes+=1;
                //Set current position equal to iterator
                array->prime[j].prime=i;
                //Reset power value to 1
                array->prime[j].power=1;
            //If Prime Factor in current position is equal to the iterator
            }else{
                //Increment number of times current prime position factors into
                //temp value
                array->prime[j].power=array->prime[j].power+1;
            }
            //Decrement iterator to retest value again
            i=i-1;
        }
        
    }
    //cout<<"This program took "<<loops<<" loops to calculate primes\n";
    
    return array;
}
void prntPrm(Primes *a){ //-> Output all prime factors
    cout<<"Number of Prime Factors: "<<static_cast<int>(a->nPrimes)<<endl;
    cout<<a->prime[0].prime<<" = ";
    
    for(int i=1;i<=static_cast<int>(a->nPrimes);i++){
    
        cout<<a->prime[i].prime<<"^"<<static_cast<int>(a->prime[i].power);
        if(i<static_cast<int>(a->nPrimes)){
            cout<<" * ";
        }
    }
    cout<<endl;
}



unsigned short def(unsigned short inN){
    inN=10;
    return inN;
}