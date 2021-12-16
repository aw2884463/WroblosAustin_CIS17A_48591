/*
 *
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on August 30th, 9:40 AM
 * Purpose : This program shows the amount of days in a year and determines if
 *           the year entered is a leap year
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
    int userYear;
    string userMonth;
    string tempMonth;

    string months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November",
                         "December"};
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    //Output
    cout << "Please enter a month:";
    //Input
    cin >> userMonth;
    //Output
    cout << endl << "Please enter a year:";
    //Input
    cin >> userYear;


  for(int i = 0;i < 12; i++) { // Cycles through arrays

	    if(userMonth == months[i] && !== "February") { //February = false
                
                if(((userYear % 4 == 0) && (userYear % 100 != 0))|| (userYear % 400 == 0)){ //Leap year math
                    
                    cout << userMonth << " has :" << monthDays[i] << " days in it.";
                    cout << endl << "Also " << userYear << " is a leap year.";
                    
                    break;
                }
                else {
                    cout << userMonth << " has :" << monthDays[i] << " days in it.";
                    cout << endl << "Also " << userYear << " is not a leap year.";
                    
                    break;
                }
	    }
            else if(userMonth == "February") { //February = true
                
                if(((userYear % 4 == 0) && (userYear % 100 != 0))|| (userYear % 400 == 0)){ // Leap year Math
                    
                    //Output
                    cout << "February has :" << monthDays[1] + 1<< " days in it.";
                    cout << endl << "Also " << userYear << " is a leap year.";
                    
                    break;
                }
                else {
                    //Output
                    cout << "February has :" << monthDays[1] << " days in it.";
                    cout << endl << "Also " << userYear << " is not a leap year.";
                    
                    break;
                }               
            }
            else {
                //Output
                cout << "You entered an invalid month!" << endl;
                cout << "Please rerun the program!";
            }
  }

  return 0;

}