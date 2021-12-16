/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on October 17, 2021, 9:30 AM
 */

#include <cstdlib>  //Standard library
#include <iostream> // Input Output
#include <iomanip>  // Input/Output manipulation
#include <string>   // Getline
#include <fstream>  //Input output file stream
#include <array>    // Array library
#include <cctype>   // Upper and Lowercase manipulation

using namespace std;

struct SalesData {
    
    string divName;
    int quarter;
    float sales;
};

/*
 * 
 */
int main() {
    
    bool nBool = false;
    bool eBool = false;
    bool sBool = false;
    bool wBool = false;
    SalesData salesData;
    fstream file;
    string name;
    
    name = "sales.txt";
    
    
    file.open(name, ios::out);
    
    
    while(wBool == false) {
        
        if(nBool == false) {
            
            salesData.divName = "North";
            bool positive = false;
            cout << "Please enter the sales report for the North division" << endl;
            
            for(int i = 1;i < 5;i++) {
                
                salesData.quarter = i;
                salesData.sales = -1;
                
                while (salesData.sales < 0 | positive == false) {
                    
                    cout << "Quarter:" << i << ":-$";
                    cin >> salesData.sales;
                    
                    if(salesData.sales > 0) {
                        
                        file << "Division-" << salesData.divName << " |Quarter-" << salesData.quarter << " |Sales Amount-" << salesData.sales << "|" << endl;
                        positive = true;
                
                    }
                }

            }
            nBool = true;
            file << endl;
            cout << endl;
        }
        if(eBool == false) {
            
            salesData.divName = "East";
            bool positive;
            cout << "Please enter the sales report for the East division" << endl;
            
            for(int i = 1;i < 5;i++) {
                
                salesData.quarter = i;
                salesData.sales = -1;
                
                while (salesData.sales < 0 | positive == false) {
                    
                    cout << "Quarter:" << i << ":-$";
                    cin >> salesData.sales;
                    
                    if(salesData.sales > 0) {
                        
                        file << "Division-" << salesData.divName << "  |Quarter-" << salesData.quarter << " |Sales Amount-" << salesData.sales << "|" << endl;
                        positive = true;
                
                    }
                }

            }
            eBool = true;
            file << endl;
            cout << endl;
        }
        if(sBool == false) {
            
            salesData.divName = "South";
            salesData.sales = -1;
            bool positive;
            cout << "Please enter the sales report for the South division" << endl;
            
            for(int i = 1;i < 5;i++) {
                
                salesData.quarter = i;
                salesData.sales = -1;
                
                while (salesData.sales < 0 | positive == false) {
                    
                    cout << "Quarter:" << i << ":-$";
                    cin >> salesData.sales;
                    
                    if(salesData.sales > 0) {
                        
                        file << "Division-" << salesData.divName << " |Quarter-" << salesData.quarter << " |Sales Amount-" << salesData.sales << "|" << endl;
                        positive = true;
                
                    }
                }
                

            }
            sBool = true;
            file << endl;
            cout << endl;
        }
        if(wBool == false) {
            
            salesData.divName = "West";
            salesData.sales = -1;
            bool positive;
            cout << "Please enter the sales report for the West division" << endl;
            
            for(int i = 1;i < 5;i++) {
                
                salesData.quarter = i;
                salesData.sales = -1;
                
                while (salesData.sales < 0 | positive == false) {
                    
                    cout << "Quarter:" << i << ":-$";
                    cin >> salesData.sales;
                    
                    if(salesData.sales > 0) {
                        
                        file << "Division-" << salesData.divName << "  |Quarter-" << salesData.quarter << " |Sales Amount-" << salesData.sales << "|" << endl;
                        positive = true;
                
                    }
                }

            }
            wBool = true;
            file << endl;
        }

    }
    
    
    file.close();

    return 0;
}

