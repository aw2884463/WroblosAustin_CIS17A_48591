/*
 *
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on August 30th, 9:40 AM
 * Purpose : This Program converts USD to YEN and EUROS
 * 
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  // Input/Output Minipulator Library
#include <array> //Array library
#include <string> //String Library

using namespace std; // STD NAME-space where Library is compiled

int main() {
    
    //Variables
    float YEN_PER_DOLLAR = 109.99;
    float yenConverted;
    float EUROS_PER_DOLLAR = 0.85;
    float euroConverted;
    float dollarAmount;
     
    //Output
    cout << "Please enter an amount in USD for conversion\n";
    cout << "Amount:";
    //Inout
    cin >> dollarAmount;
    
    euroConverted = dollarAmount * EUROS_PER_DOLLAR;
    yenConverted = dollarAmount * YEN_PER_DOLLAR;
    
    //Output
    cout << "In Yen that would be:";
    cout << setprecision(2) << fixed << yenConverted << endl;
    cout << "In Euros that would be:";
    cout << setprecision(2) << fixed << euroConverted;
       
    return 0;
}

