/* 
 * File:   
 * Author: Austin Wroblos
 * Created on 10/6/2021 4:15PM
 * Purpose: Quarterly Sales report
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Expenses {
  
  float housing;
  float util;
  float hhexp;
  float transport;
  float food;
  float med;
  float insure;
  float enter;
  float cloth;
  float misc;
  
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

void inputs(Expenses &);
float budgets(float budget, float &lastBudget, Expenses expenses);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Expenses expenses;
    float housingB = 500.00;
    float utilB = 150.00;
    float hhexpB = 65.00;
    float transportB = 50.00;
    float foodB = 250.00;
    float medB = 30.00;
    float insureB = 100.00;
    float enterB = 150.00;
    float clothB = 75.00;
    float miscB = 50.00;
    float lastBudget = 0;
    float budget = 0;
    //Initialize Variables
 

    //Process or map Inputs to Outputs
         inputs(expenses);
    
         budget = budgets(budget,lastBudget,expenses);
              

    
    
        //Display Outputs
    if(expenses.housing == housingB) {
        
        cout << "Housing Even" << endl;
    }
    else if(expenses.housing >= housingB) {
        
        cout << "Housing Over" << endl;
    }
    else {
        cout << "Housing Under" << endl;
        
    }
 
    if(expenses.util == utilB) {
        
        cout << "Utilities Even" << endl;
    }
    else if(expenses.util >= utilB) {
        
        cout << "Utilities Over" << endl;
    }
    else {
        cout << "Utilities Under" << endl;
        
    }
    
    if(expenses.hhexp == hhexpB) {
        
        cout << "Household Expenses Even" << endl;
    }
    else if(expenses.hhexp >= hhexpB) {
        
        cout << "Household Expenses Over" << endl;
    }
    else {
        cout << "Household Expenses Under" << endl;
        
    }
    
    if(expenses.transport == transportB) {
        
        cout << "Transportation Even" << endl;
    }
    else if(expenses.transport >= transportB) {
        
        cout << "Transportation Over" << endl;
    }
    else {
        cout << "Transportation Under" << endl;
        
    }
    
    if(expenses.food == foodB) {
        
        cout << "Food Even" << endl;
    }
    else if(expenses.food >= foodB) {
        
        cout << "Food Over" << endl;
    }
    else {
        cout << "Food Under" << endl;
        
    }
    
    if(expenses.med == medB) {
        
        cout << "Medical Even" << endl;
    }
    else if(expenses.med >= medB) {
        
        cout << "Medical Over" << endl;
    }
    else {
        cout << "Medical Under" << endl;
        
    }
    
    if(expenses.insure == insureB) {
        
        cout << "Insurance Even" << endl;
    }
    else if(expenses.insure >= insureB) {
        
        cout << "Insurance Over" << endl;
    }
    else {
        cout << "Insurance Under" << endl;
        
    }
    
    if(expenses.enter == enterB) {
        
        cout << "Entertainment Even" << endl;
    }
    else if(expenses.enter >= enterB) {
        
        cout << "Entertainment Over" << endl;
    }
    else {
        cout << "Entertainment Under" << endl;
        
    }
    
    if(expenses.cloth == clothB) {
        
        cout << "Clothing Even" << endl;
    }
    else if(expenses.cloth >= clothB) {
        
        cout << "Clothing Over" << endl;
    }
    else {
        cout << "Clothing Under" << endl;
        
    }
    
    if(expenses.misc == miscB) {
        
        cout << "Miscellaneous Even" << endl;
    }
    else if(expenses.misc >= miscB) {
        
        cout << "Miscellaneous Over" << endl;
    }
    else {
        cout << "Miscellaneous Under" << endl;
        
    }
    
    if(lastBudget >= budget) {
        
        cout << "You were $" << fixed << setprecision(2) << lastBudget - budget << " over budget";
    }
    else {
        
        cout << "You were $" << fixed << setprecision(2) << budget - lastBudget  << " under budget";
    }

    //Exit stage right!
    return 0;
}



void inputs(Expenses &expenses) {
    
    
    cout << "Enter housing cost for the month:$"<< endl;
    cin >> expenses.housing;
    cout << "Enter utilities cost for the month:$"<< endl;
    cin >> expenses.util;
    cout << "Enter household expenses cost for the month:$"<< endl;
    cin >> expenses.hhexp;
    cout << "Enter transportation cost for the month:$"<< endl;
    cin >> expenses.transport;
    cout << "Enter food cost for the month:$"<< endl;
    cin >> expenses.food;
    cout << "Enter medical cost for the month:$"<< endl;
    cin >> expenses.med;
    cout << "Enter insurance cost for the month:$"<< endl;
    cin >> expenses.insure;
    cout << "Enter entertainment cost for the month:$"<< endl;
    cin >> expenses.enter;
    cout << "Enter clothing cost for the month:$"<< endl;
    cin >> expenses.cloth;
    cout << "Enter miscellaneous cost for the month:$"<< endl;
    cin >> expenses.misc;
    
}


float budgets(float budget, float &lastBudget, Expenses expenses) {
    
    float housingB = 500.00;
    float utilB = 150.00;
    float hhexpB = 65.00;
    float transportB = 50.00;
    float foodB = 250.00;
    float medB = 30.00;
    float insureB = 100.00;
    float enterB = 150.00;
    float clothB = 75.00;
    float miscB = 50.00;
    
        budget = (housingB + utilB + hhexpB + transportB + foodB + medB + insureB + enterB + clothB + miscB);
    lastBudget = (expenses.housing + expenses.util + expenses.hhexp + expenses.transport + expenses.food
              + expenses.med + expenses.insure + expenses.enter + expenses.cloth + expenses.misc);
              
              
    return budget;
}