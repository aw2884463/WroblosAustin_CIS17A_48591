/*
 *
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on August 30th, 9:40 AM
 * Purpose : This Program Celsius to Fahrenheit
 * 
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  // Input/Output Minipulator Library
#include <array> //Array library
#include <string> //String Library
#include <algorithm> //used for sorting string array

using namespace std; // STD NAME-space where Library is compiled

//Function Prototype
int binarySearch(const string, int, string);


//Code starts here
int main() {
    
    //variables
    const int NUM_NAMES = 20;
    int results;
    string input;
    string names[NUM_NAMES] = {"Collins, Bill","Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty",
                               "Rose, Geri", "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe",
                               "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    
    
    //Output
    cout << "Please enter a Name" << endl;
    //Input
    cin >> input;
    
                               

int size = sizeof(names)/sizeof(names[0]); //Get the array size

sort(names,names+size); //Sorting array

results = binarySearch(names, NUM_NAMES, input);

    
    return 0;
}



/*
 *
 * Name:binarySearch
 * Purpose: This function should search through the array for the input using 
 *          a binary search method
 */
int binarySearch(const string array[], int size, string value) {
    
    int first = 0,
            last = size - 1,
            middle,
            position = - 1;
    bool found = false;
    
    while (!found && first <= last) {
        
        middle = (first + last) /2;
        
        if(array[middle] == value) {
            
            found = true;
            position = middle;
        }
        else if (array[middle] > value) {
            last = middle - 1;
           
        }
        else {
            first = middle + 1;
        }
    }
    return position;
    
}


