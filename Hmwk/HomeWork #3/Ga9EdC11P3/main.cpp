/* 
 * File:   
 * Author: Austin Wroblos
 * Created on 10/6/2021 5:43PM
 * Purpose: Quarterly Sales report
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Sales {
    
    float first;
    float second;
    float third;
    float fourth;
    float average;
    float total;
    
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Sales sales;
    
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout << "North" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> sales.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> sales.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> sales.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> sales.fourth;
    
    sales.total = sales.first + sales.second + sales.third + sales.fourth;
    sales.average = sales.total / 4;
    cout << fixed << setprecision(2) << "Total Annual sales:$" << sales.total << endl; 
    cout << "Average Quarterly Sales:$" << sales.average << endl;
    
    cout << "West" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> sales.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> sales.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> sales.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> sales.fourth;
    
    sales.total = sales.first + sales.second + sales.third + sales.fourth;
    sales.average = sales.total / 4;
    cout << "Total Annual sales:$" << sales.total << endl; 
    cout << "Average Quarterly Sales:$" << sales.average << endl;
    
    cout << "East" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> sales.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> sales.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> sales.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> sales.fourth;
    
    sales.total = sales.first + sales.second + sales.third + sales.fourth;
    sales.average = sales.total / 4;
    cout << "Total Annual sales:$" << sales.total << endl; 
    cout << "Average Quarterly Sales:$" << sales.average << endl;
    
    cout << "South" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> sales.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> sales.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> sales.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> sales.fourth;
    
    sales.total = sales.first + sales.second + sales.third + sales.fourth;
    sales.average = sales.total / 4;
    cout << "Total Annual sales:$" << sales.total << endl; 
    cout << "Average Quarterly Sales:$" << sales.average;
    
    
    //Display Outputs

    //Exit stage right!
    return 0;
}