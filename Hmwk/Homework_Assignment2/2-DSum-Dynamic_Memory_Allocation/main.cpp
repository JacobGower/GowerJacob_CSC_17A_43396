/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 28, 2021, 6:16 PM
 * Purpose:  To Total the elements in a 2-D Array.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int **getData(int &,int &);               //Return the 2-D array and its size.
int sum(const int * const *, int,int);    //Return the Sum
void prntDat(const int* const *,int,int); //Print the 2-D Array
void destroy(int **,int,int);             //Deallocate memory

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int **twoDAry, //Dynamic 2-D Array to be filled then summed up
            total, //Total of dynamic 2-D Array
             rows, //Number of Rows (Vertical Length) of 2-D Array
             cols; //Number of Columns (Horizontal length)) of 2-D Array
    
    //Initialize Variables
    total=0;
    
    cin>>rows>>cols;
    
    
    //Map Inputs to Outputs -> Process
    twoDAry=getData(rows,cols);
    
    total=sum(twoDAry,rows,cols);
    //Display Inputs/Outputs
    prntDat(twoDAry,rows,cols);
    cout<<total;
     
    //Exit the Program - Cleanup
    destroy(twoDAry,rows,cols);
    
    return 0;
}
int **getData(int &rows,int &cols){    //Return the 2-D array and its size.
    //Allocate row pointers
    int **array=new int*[rows];
    //Allocate each row with the same size columns
    for(int row=0;row<rows;row++){
        array[row]=new int[cols];
    }
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cin>>array[row][col];
        }
    }
    return array;
}
int sum(const int * const *array, int rows,int cols){
    int ttl=0;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            ttl+=array[row][col];
        }
    }
    return ttl;
}
void prntDat(const int* const *array,int rows,int cols){
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array[row][col];
            if(col<cols-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void destroy(int **array,int rows,int cols){
    //Deallocate each row
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Deallocate the row pointers
    delete []array;
}