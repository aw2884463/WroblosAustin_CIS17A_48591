/* 
 * File: main.cpp
 * Author: Austin Wroblos
 * Created on October 4th, 2021, 10:30PM
 * Purpose:  Weather statistics 
 */
 
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int SIZE = 81;

struct Weather{
    float totrain;
    float tempH;
    float tempL;
    float avgtemp;
};

enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER ,OCTOBER, NOVEMBER, DECEMBER};

                
int main(){
    //Set Random Number seed

    //Declare Variable Data Types and Constants

    const int MONTHS=12;
    float totrain=0;
    float  temp=0;
    string lowname, hiname;
    unsigned short tempH=0;

    //Initialize Variables
    Weather month[MONTHS];

    //Process or map Inputs to Outputs
    for(int i=JANUARY; i<=JUNE;i++){
        cout<<"Enter the total rainfall for the month:"<<endl;
        cin>>month[i].totrain;
        cout<<"Enter the high temp:"<<endl;
        cin>>month[i].tempH;
        cout<<"Enter the low temp:"<<endl;
        cin>>month[i].tempL;
    }


    for(int i=JANUARY; i<=JUNE;i++){
        totrain+=month[i].totrain;
    }
    
    for(int i=JANUARY; i<=JUNE;i++){
        if(month[i].tempH>tempH){
            tempH=month[i].tempH;
        }
    }

    int tempL=month[JANUARY].tempL;
    for(int i=JANUARY; i<=JUNE;i++){
        if(month[i].tempL<tempL){
            tempL=month[i].tempL;
        }
    }


    for(int i=JANUARY; i<=JUNE;i++){
        temp=temp+((month[i].tempL+month[i].tempH)/2);
    }

    //Display Outputs
    cout<<fixed<<setprecision(2);
    cout<<"Average monthly rainfall:"<<totrain/6<<endl;
    cout<<"High Temp:"<<tempH<<endl;
    cout<<"Low Temp:"<<tempL<<endl;
    cout<<fixed<<setprecision(1);
    cout<<"Average Temp:"<<temp/6;

    //Exit
    return 0;
}


