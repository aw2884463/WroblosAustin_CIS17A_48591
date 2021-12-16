/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 13, 2021, 12:24 PM
 */

#include <cstdlib>  //Standard library
#include <iostream> // Input Output
#include <iomanip>  // Input/Output manipulation
#include <string>   // Getline
#include <fstream>  //Input output file stream
#include <array>    // Array library
#include <cctype>   // Upper and Lowercase manipulation


using namespace std;

/*
 * 
 */
int main() {
    
    string inName;
    string outName;
    fstream inFile;
    fstream outFile;
    int count = 255;
    string line;
    
    cout << "Please enter your input file name(end name with .txt)" << endl;
    cin >> inName;
    cout << "Please enter your output file name(end name with .txt)" << endl;
    cin >> outName;
    
    inFile.open(inName, ios::in);
    
    
    if(inFile.is_open()) {
        
        outFile.open(outName, ios::out);
        
            while(getline(inFile, line)) {
                
            if(outFile.is_open()) {

                    
                for(int i = 0; i < line.length();i++) {
                    
                    if(i == 0) {
                    outFile << (char) toupper(line[i]);
                    }
                    else if(i == line.length() - 1) {
                        
                    outFile.put(tolower(line[i]));

                    outFile << endl;
                    }
                    else {
                        
                    outFile.put(tolower(line[i]));

                    }
                }
            }
            else {
                cout << "Output file didn't open properly" << endl;
                return 0;
            }

        }

    }
    else {
        
        cout << "Input file didn't open properly" << endl;
    }
   
    
    
        outFile.close();
        inFile.close();
    return 0;
}

