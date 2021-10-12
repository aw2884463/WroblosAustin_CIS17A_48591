/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Austin Wroblos
 *
 * Created on October 6, 2021, 7:16 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Speaker {

    string name;
    int phone;
    string topic;
    float fee;
    
};


int main() {
    
    
    int x;
    string change;
    const int SIZE = 10;
    int j = 0;
    bool found = false;
    
    Speaker speaker[SIZE];
    
    for(int i = 0; i < SIZE;i++) {
        
        speaker[i].phone = 0;
        speaker[i].fee = 0;
        speaker[i].name = "";
        speaker[i].topic = "";
        
        if( i < 1) {
            
            cout << "Please enter the first speaker's information" << endl;
        }
        else {
            cout << "Please enter another speaker's information" << endl;
            
        }
        cout << "Name:";
        
        while(speaker[i].name == "") {
            if(j == 0) {
            cin.clear();
            getline(cin,speaker[i].name); 
            }
            else {
            cin.clear();
            cin.ignore();
            getline(cin,speaker[i].name);
                
            }
            if(speaker[i].name == "") {
                
                cout << "Invalid Name, Try Again!!!" << endl;
                cout << "Name:";
            }
            j++;
        }
        
        cout << endl << "Phone Number:";
        
        while(speaker[i].phone == 0) {
            cin >> speaker[i].phone;
            
            if(speaker[i].phone == 0) {
                
                cout << "Invalid Number, Try Again!!!" << endl;
                cout << "Phone Number:";
            }
            
        }
        cout << endl << "Topic:";
        
        while(speaker[i].topic == "") {
            
            cin.clear();
            cin.ignore();
            getline(cin,speaker[i].topic);
            
            if(speaker[i].topic == "") {
                
                cout << "Invalid Topic, Try Again!!!" << endl;
                cout << "Topic:";
            }
        }
        cout << endl << "Fee(Input 1 if FREE):";
        
        while(speaker[i].fee == 0) {
            
        cin >> speaker[i].fee;
        
            if(speaker[i].fee == 0) {
                
                cout << "Invalid Fee, Try Again!!!" << endl;
                cout << "Fee:";
            }
        }
    }
    
    cout << endl << "Would you like to change any information(Yes or No)" << endl;
    cin >> change;
    
    
    
    if(change == "Yes") {
        
        string tempName;
        cout << "Please enter the name of the speaker that you want to change info on" << endl;
        
        cin.clear();
        cin.ignore();
        getline(cin,tempName);
        int intChange;
        
        for(int i = 0;i < SIZE;i++) {
            
            if (tempName == speaker[i].name) {
                
                found = true;
                cout << "Name Found" << endl;
                cout << "What would you like to change" << endl;
                cout << "1)Name" << endl << "2)Phone" << endl << "3)Topic" << endl << "4)Fee" << endl;
                cin >> intChange;
                
                if(intChange == 1) {
                    
                    cout << "Please Enter New Name:" << endl;
                    cin.clear();
                    cin.ignore();
                    getline(cin,speaker[i].name);
                    
                    i = SIZE;
                }
                else if(intChange == 2) {
                    
                    cout << "Please Enter New Phone Number:" << endl;
                    cin >> speaker[i].phone;
                    
                    i = SIZE;
                }
                else if(intChange == 3) {
                    
                    cout << "Please Enter New Topic:" << endl;
                    cin.clear();
                    cin.ignore();
                    getline(cin,speaker[i].topic);
                    
                    i = SIZE;
                }
                else if(intChange == 4) {
                    
                    cout << "Please Enter New Fee(Input 1 if FREE):" << endl;
                    cin >> speaker[i].fee;
                    
                    i = SIZE;
                }
                else {
                    
                    cout << "Invalid Input";
                }
                        
            
            }

            
        }
            if(found == false) {
                
                cout << "Cant find that name sorry" << endl;
            }
  
    }
    
    else if(change == "No") {
        
        cout << "Alright No Changes Will be made" << endl;
    }
    
    found = false;
    cout << "Please enter what speakers info you want to print by name" << endl;
    cout << "Name:" << endl;
    
        string tempName;
        cin.clear();
        getline(cin,tempName);
    
    int i = 0;
    
    while(found == false) {
  
        int indx;
        
 
        if(tempName == speaker[i].name) {
            
            indx = i;
            found = true;
            cout << "That Speaker's Name is:" << speaker[indx].name << endl;
            cout << "That Speaker's Phone Number is:" << speaker[indx].phone << endl;
            cout << "That Speaker's Topic is:" << speaker[indx].topic << endl;
            cout << "That Speaker's Fee is:" << speaker[indx].fee << endl;
        }
        else {
            indx = NULL;
            i++;
        }

    }
    
    if(found == false) {
        
        cout << "Name was not found sorry";
    }
    

    return 0;
}


    

