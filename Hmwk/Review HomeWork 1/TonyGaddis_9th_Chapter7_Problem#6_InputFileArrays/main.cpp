/*
 *(Not completed)
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on August 30th, 9:40 AM
 * Purpose : This Program should take input from a file and then use the data 
 *           to put data about weather into a multidimensional array. Then 
 *           take data from the array and output which month had the most rainy
 *           days.
 * 
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  // Input/Output Minipulator Library
#include <array> //Array library
#include <string> //String Library
#include <fstream> // File input/output library

using namespace std; // STD NAME-space where Library is compiled


//Code starts here
int main() {
    
    //Variables
    string file = "RainOrShine.txt";
    
    //Open File
    ifstream inFile;
    inFile.open(file);
    
    string data = "";
    string temp = "";
    int row = 3;
    int col = 30;
    string weatherArray[row][col] = {0};
    
    if(inFile.is_open()) {
        
        
        int a = 0;
        int b = 0;
        
        while(getline(inFile,data)) {
            
            if(data != "") {
                
                b = 0;
                data = data + ',';
                
                for(int i = 0; i < data.length(); i++) {
                    
                    if(data[i] != ',') {
                        
                        temp += data[i];
                    }
                    else{
                        
                        weatherArray[a][b] = temp;
                        temp = "";
                        b++;
                    }
                    
                }               
            }
            a++;
        }
    }
    else { // File open validation
        cout << "The file was not opened properly";
    }
       
    return 0;
}

