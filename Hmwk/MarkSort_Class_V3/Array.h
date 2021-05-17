/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 6th, 2021, 6:14 PM
 * Purpose:  Array Class on Specification
 */

#ifndef ARRAY_H
#define ARRAY_H
//All ADTs should be sequestered into .h files
class Array{
    private:
        unsigned short size;//size of the array
        int *data;          //Dynamic pointer to the data in the array
        //Utility function to fill the array. Accesses the data directly
        void filAray(int); //Utility function for the constructor to create an array
                           //Utility function is not used outside of class, 
                           //so make it private
                           //Program cannot access private data members. 
                           //Must create modifier functions
                           //to access data
    public:
        
        Array(int n){     //Constructor -> initializes the Array
            filAray(n);   //Call on the fill array utility function
        }
        ~Array(){       //Destructor cleanup for memory/close files
            delete []data;
        }
        void prntAry(int perLine); //Output the array
        void markSrt(); //Sort the array
        void setData(int,int);  //Modify Data
        int getData(int);       //Retrieve Data
        int getSize(){
            return size;
        }
};


#endif /* ARRAY_H */

