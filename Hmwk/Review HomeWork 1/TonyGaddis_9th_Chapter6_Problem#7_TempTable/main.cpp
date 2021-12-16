/*
 *
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on Septmeber 1st, 10:50 AM
 * Purpose : Display a table of temperatures in Fahrenheit and Celsius
 *           by calling a function
 * 
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  // Input/Output Minipulator Library
#include <array> //Array library
#include <string> //String Library

using namespace std; // STD NAME-space where Library is compiled

//Function Prototype
float tempConvert(float);

//Code begins execution
int main() {
    
    for(int i = 0; i < 21; i++) {
        
        
        //Variables
        float displayCel;
        
        
        //Output
        displayCel = tempConvert(i);
        cout << "Case#"<< i + 1 << "--In Fahrenheit:" << i << endl;
        cout << "Case#" << i + 1<< "--In Celsius:";
        cout << fixed << setprecision(2) << displayCel << endl;
        cout << "___________________________" << endl;
        
    }
    

    return 0;
}

/*
 * Name:tempConvert
 * Purpose: This function converts fahrenheit to celsius
 */
float tempConvert(float fah) {
    
    float cel;
    
    cel = (fah - 32) * 5/9;
    
    return cel;
    
    
}




