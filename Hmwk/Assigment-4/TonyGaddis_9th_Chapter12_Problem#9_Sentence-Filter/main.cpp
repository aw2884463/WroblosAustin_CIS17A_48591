
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 17, 2021, 12:01 PM
 */

#include <cstdlib>  //Standard library
#include <iostream> // Input Output
#include <iomanip>  // Input/Output manipulation
#include <string>   // Getline
#include <fstream>  //Input output file stream
#include <array>    // Array library
#include <cctype>   // Upper and Lowercase manipulation

using namespace std;

const int SIZE = 26;

void writeToFile(string);
void cypher(string);

int main(int argc, char** argv) {
    
    string line;
    string inName;
    
    cout << "Please enter the input file name:";
    getline(cin,inName);
    cout << endl << "Thank you!!!" << endl;
    
    writeToFile(inName);
    cypher(inName);

    return 0;
}

void writeToFile(string inName) {
    
    fstream file;
    string temp = "";
    
    file.open(inName, ios::out); 
    
    if(file.is_open()) {
        

            cout << "Please enter a word or sentence(enter stop to finish)" << endl;

                getline(cin,temp);
                file << temp << endl;   
        
    }
    else {
        cout << "File did not open properly!!!";
    }
    
    file.close();
}


void cypher(string inName) {
    
    fstream file;
    fstream outFile;
    string temp;
    string done;
    int place;
    string output = "output.txt";
    
    const char letters[SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                                'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    const char mixedLetters[SIZE] = {'O','Z','C','M','E','T','G','V','I','X','Y','N','D',
                                'L','A','P','Q','R','S','F','U','H','W','J','K','B'};
    
    file.open(inName, ios::in);
  
    if(file.is_open()) {
      
        outFile.open(output, ios::out);
        
        getline(file,temp); 
                

            for(int i =0;i < temp.length() + 1;i++) {
                

                for(int j = 0;j < SIZE;j++) {
                    if(temp[i] == letters[j]) {

                        cout << temp[i] << "-temp "<< i << "-i "<< letters[j] << "-letter " << j << "-j"<< endl;
                        done[i] = mixedLetters[j];
                        outFile << done[i];

                        
                    }
                    else if(temp[i] == tolower(letters[j])) {
                        
                        cout << temp[i] << "-temp "<< i << "-i "<< letters[j] << "-letter " << j << "-j"<< endl;
                        done[i] = tolower(mixedLetters[j]);
                        outFile << done[i];
                    }
                }
            }

    }
    else {
        cout << "File did not open properly-Roundone" << endl;
    }
    outFile.close();
    file.close();
}


