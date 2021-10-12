/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on September 26, 2021, 1:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.

void prntDat(int **,int ,int);//Print the 2-D Array

void destroy(int **,int);       //Deallocate memory

int sum(int **, int,int);    //Return the Sum


int main() {
    
    int row;
    int col;
    int **getDataptr;
    int **sumAryptr;
    int arraysum;

    
    getDataptr = getData(row, col);
    prntDat(getDataptr,row,col); 
    arraysum = sum(getDataptr,row,col); 
    cout << arraysum;
    
    destroy(getDataptr,row);
    
    
    
    return 0;
}


int **getData(int &row,int &col) {
    
    cin >> row;
    cin >> col;
    
    int **array = new int *[row];
    for(int i = 0; i < row;i++) {
        array[i] = new int[col];
    }
    
    for(int i = 0;i < row;i++) {
       for(int j = 0;j < col;j++) {
           
           cin >> array[i][j];
           
       } 
        
    }
        for(int i = 0;i < row;i++) {
       for(int j = 0;j < col;j++) {
           
           
       } 
        
    }
    
    return array;
}

int sum(int **ptr, int row,int col) {
    
    int prev = 0;
    int temp = 0;
    
        for(int i = 0 ;i < row ;i++) {
            
            for(int j = 0;j < col;j++) {

            temp = ptr[i][j] + prev;
            prev = temp;

        }
        
    }
        return temp;
}

void prntDat(int **ptr,int row,int col) {
    
    for(int i = 0; i < row;i++) {
        for(int j = 0;j < col; j++) {
            
            if(j < col - 1) {
            cout << ptr[i][j] << " ";
            }
            else {
                cout << ptr[i][j];
            }
        
        }
        cout << endl;
    } 
}

void destroy(int **ptr,int row) {
    
    for(int i = 0; i < row; i++) {
        delete[] ptr[i];   
    }
    
    delete[] ptr;
}