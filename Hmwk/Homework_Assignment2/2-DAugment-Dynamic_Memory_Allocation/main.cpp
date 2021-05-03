/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 28, 2021, 6:16 PM
 * Purpose:  To Create a 2-D array 1 row and 1 column larger than the array to copy 
 *           with 0's in the 1st row and column but filled with the other rows and columns using the original array.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
int **getData(int &,int &);                 //Get the Matrix Data
void printDat(const int * const *,int,int); //Print the Matrix
int **augment(const int * const *,int,int); //Augment the original array
void destroy(int **,int);                   //Destroy the Matrix, i.e., reallocate memory

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int **twoDAry, //Dynamic 2-D Array to be filled and then augmented
         **augAry, //Augmented 2-D Dynamic Array
             rows, //Number of Rows (Vertical Length) of 2-D Array
             cols; //Number of Columns (Horizontal length)) of 2-D Array
    
    //Initialize Variables
    cin>>rows>>cols;
    //Map Inputs to Outputs -> Process
    twoDAry=getData(rows,cols);
    
    augAry=augment(twoDAry,rows,cols);
    
    //Display Inputs/Outputs
    printDat(twoDAry,rows-1,cols-1);
    
    cout<<endl;
    
    printDat(augAry,rows,cols);
      
    //Exit the Program - Cleanup
    destroy(twoDAry,rows-1);
    destroy(augAry,rows);
    
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
    rows++;
    cols++;
    return array;
}
int **augment(const int * const *array,int rows,int cols){
    //Allocate row pointers
    int **aug=new int*[rows];
    //Allocate each row with the same size columns
    for(int row=0;row<rows;row++){
        aug[row]=new int[cols];
    }
    for(int i=0;i<cols;i++){
        aug[0][i]=0;
    }
    for(int i=0;i<rows;i++){
        aug[i][0]=0;
    }
    
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++){
                aug[i][j]=array[i-1][j-1];
        }
    }
    
    return aug;
}
void printDat(const int* const *array,int y,int x){
    for(int row=0;row<y;row++){
        for(int col=0;col<x;col++){
            cout<<array[row][col];
            if(col<x-1){
                cout<<" ";
            }
        }
        if (row<y-1){
            cout<<endl;
        }
            
    }
}
void destroy(int **array,int rows){
    //Deallocate each row
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Deallocate the row pointers
    delete []array;
}