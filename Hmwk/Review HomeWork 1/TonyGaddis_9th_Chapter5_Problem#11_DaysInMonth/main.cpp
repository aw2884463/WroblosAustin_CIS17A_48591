/*
 *
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on August 30th, 10:00 AM
 * Purpose : This function calculates the rate of growth in a population
 *           based on 3 factors 'starting','increase','days'. 
 * 
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  // Input/Output Minipulator Library
#include <array> //Array library
#include <string> //String Library

using namespace std; // STD NAME-space where Library is compiled

//Code starts here
int main() {
    
    //Variables
    float starting;
    float increase;
    float tempIncrease;
    int days;
    float amount;
    
    //output
    cout << "Please enter the starting amount of the population" << endl;
    cout << "Starting:";
    //input
    cin >> starting;
    //output
    cout << endl << "Please enter the amount to increase in the ";
    cout << "form of a percent" << endl << "Increase Rate:";
    //input
    cin >> increase;
    //output
    cout << endl << "Please enter the number of days you want the test to";
    cout << " go on for" << endl << "Trial Time:";
    //input
    cin >> days;
    
    cout << "It is day one and we have started with:" << starting << endl;
    
    amount = starting;
    tempIncrease = increase / 100;
    
    if(starting >= 2) { //Input Validation
        
        if(increase > 0) { //Input Validation
            
            if(days >= 1) { //Input Validation
                
                for(int i = 0;i < days;i++) { //Looping through the amount of days
        
                int counter;
                amount += amount * tempIncrease;
                 
                //Output
                cout << "It is day " << counter + 2 << " and the amount is:"; 
                cout << setprecision(2) << fixed << amount << endl; 
         
                counter++; 
        
                }  
            }
            else {
                cout << "Your trial time must be 1 day or longer"; //Input Validation Output
            }
        }
        else {
            cout << "Your increase percent must be greater than 0"; //Input Validation Output
        }
    }
    else {
        cout << "Your starting number must be 2 or higher"; //Input Validation Output
    }
    return 0;
}

