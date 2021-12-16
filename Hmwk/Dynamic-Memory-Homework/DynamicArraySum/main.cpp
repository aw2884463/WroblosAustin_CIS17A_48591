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

int *getData(int &);            //Return the array size and the array from the inputs

int *sumAry(const int *,int);   //Return the array with successive sums

void prntAry(const int *,int);  //Print the array


int main() {
    
    int size;
    int *getDataptr;
    int *sumAryptr;

    
    getDataptr = getData(size);
    prntAry(getDataptr,size);
    cout << endl; 
    
    sumAryptr = sumAry(getDataptr,size);
    prntAry(sumAryptr,size);
    
    
    
    return 0;
}


int *getData(int &size) {
    
    cin >> size;
    
    int *array = new int [size];
     
    for(int i = 0 ;i < size ;i++) {
        int data;
        
        cin >> data;
        array[i] = data;
  
    }   
    return array;
}

int *sumAry(const int *ptr,int size) {
    
    int *sumptr = new int [size];
    int prev = 0;
    
    for(int i = 0 ;i < size ;i++) {
        
        int temp = ptr[i] + prev;
        prev = temp;
  
        if(i < 1) {
            sumptr[i] = ptr[i];
        }
        else{
            sumptr[i] = temp;
        }
    //sumptr[0] = ptr[0];
    }
        return sumptr;
}

void prntAry(const int *ptr,int size) {
    
    for(int i = 0; i < size;i++) {
      
      if(i < size - 1)  {
        cout << ptr[i] << " ";
      }
      else{
          cout << ptr[i];
      }
         
    }

}

