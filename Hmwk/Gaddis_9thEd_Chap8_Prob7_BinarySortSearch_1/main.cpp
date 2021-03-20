/* 
 * File:   main.cpp
 * Author: Jacob Gower
 * Created on March 7, 2021, 10:45 AM
 * Purpose: To Modify a binarySearch so that it searches an array of strings
 *          instead of an array of ints 
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>    //Format Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, Higher Dimension Arrays

//Function Prototypes
void stringSort(string [], int);
bool binarySearchString(const string [], string, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const int NUM_NAMES=20;
    string names[NUM_NAMES]={"Collins, Bill","Smith, Bart","Allen, Jim",
                             "Griffin, Jim","Stamey, Marty","Rose, Geri",
                             "Taylor, Terri","Johnson, Jill","Allison, Jeff",
                             "Looney, Joe","Wolfe, Bill","James, Jean",
                             "Weaver, Jim","Pore, Bob","Rutherford, Greg",
                             "Javens, Renee","Harrison, Rose", "Setzer, Cathy", 
                             "Pike, Gordon","Holland, Beth"},
           namSrch;
    //Initialize Variables
    
       //call sorting function on array names
    stringSort(names, NUM_NAMES);

    //declare variable to store user input
    //prompt user to enter it then read from keyboard
    string searchName;
    cout << "Enter the name to search:\n";
    //get the input name using getline function
    //which reads the string until Enter is pressed
    // by user
    getline(cin, searchName);

    //call function to binary search input name
    //and display message according to function output
    if(binarySearchString(names, searchName, NUM_NAMES))
        cout << searchName << " was found in list!\n";
    else
        cout << searchName << " was not found!\n";

    return 0;
}

void stringSort(string names[], int arraySize){
    //will sort in ASCENDING order

    //declare variables to start from beginning of array
    //and to store the temporary min name and index
    int startScan, minIndex;
    string minName;

    //begin looping on all elements until second to last
    for(startScan = 0; startScan < arraySize-1; startScan++){
        //initialize minValue and minIndex to first element
        minName = names[startScan];
        minIndex = startScan;
        //loop on all remaining elements of array
        for(int index = startScan+1; index < arraySize; index++){
            //check if current string element is less than current minValue
            if(names[index] < minName){
                //update minValue and minIndex to
                //respective values of current element
                minName = names[index];
                minIndex = index;
            }
        } //inner for loop ends here
        //put the current [startScan] element to its final position
        names[minIndex] = names[startScan];
        //put lowest value first
        names[startScan] = minName;
    }
}

bool binarySearchString(const string names[], string searchName, int arraySize){
    //perform binary search
    //declare variables to hold starting and final positions
    //of subsearch, and boolean to know if the name has
    //been found
    int first = 0, //initialize first index to first element
        last = arraySize-1, //initialize last index to last element
        middle;

    //continue loop until first and last indexes have not overlapped
    while(first <= last){
        //get middle element
        middle = (first + last) / 2;
        //check if middle element is equal to our value
        if(names[middle] == searchName){
            return true;
        }
        //if middle element is greater than our value
        //update search space to first half of array
        else if(names[middle] > searchName){
            last = middle - 1;
        }
        //if middle element is less than our value
        //update search space to second half of array
        else if(names[middle] < searchName){
            first = middle + 1;
        }
    }
    //if loop has finished and the number has not
    //been found, return false
    return false;
}