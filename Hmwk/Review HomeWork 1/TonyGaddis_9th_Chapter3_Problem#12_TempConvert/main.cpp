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

using namespace std; // STD NAME-space where Library is compiled

int main() {
    
    float F;
    float C;
    
    cout << "Please enter a temperature in Celsius\n";
    cout << "Celsius:";
    cin >> C;
    F = C * 9/5 + 32;
    cout << "The temperature in Fahrenheit is: " << F;
    
    return 0;
}