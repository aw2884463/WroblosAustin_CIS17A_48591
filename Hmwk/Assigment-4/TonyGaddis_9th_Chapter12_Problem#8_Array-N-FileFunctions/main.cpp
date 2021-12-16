/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 13, 2021, 4:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <valarray>
#include <ctime>

using namespace std;

void arrayToFile(string ,int*, int&);
void fileToArray(string,int*,int);


int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    
    int* array;
    int size;
    string name;
    
    cout << "Please enter the file name" << endl;
    cin >> name;
    cout << "Thank you!" << endl;
    cout << "Please enter the array size now" << endl;
    cin >> size;
    cout << "Thank You!" << endl << endl;
    

    
    
    
    arrayToFile(name,array,size);
    fileToArray(name,array,size);
    
    

    return 0;
}

void arrayToFile(string name,int* array, int &size) {
    
    fstream tempFile;
    
        array = new int [size];
        for(int i = 0;i < size;i++) {
            
            array[i] = rand()%9+1;
        }
    
    tempFile.open(name, ios::out | ios::binary);
    
    if(tempFile.is_open()) { 
        
        
        tempFile.write(reinterpret_cast<char*>(array), size * 4);
                
    }    
    else {
        
        cout << "File did not open properly!!!";
    }
    delete []array;
    tempFile.close();
}


void fileToArray(string name,int*array,int size) {
    
    fstream tempFile;
    
    tempFile.open(name, ios::in | ios::binary);
    
    if (tempFile.is_open()) {
        
        array = new int[size];
        
        tempFile.read(reinterpret_cast<char*>(array),size * 4);
        
        for(int i = 0; i < size;i++) {
            
            cout << array[i] << " ";
        }
        cout << "-Final Array" << endl;
        
    }
    tempFile.close();
    delete []array;
}


    
    
    
