#include <iostream>

using namespace std;


int **getData(int &,int &);//Get the Matrix Data

void printDat(int **,int,int);//Print the Matrix

int **augment(int **,int,int);//Augment the original array

void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
    
    int **getDataPtr;
    int **augmentPtr;
    int row;
    int col;
    
    getDataPtr = getData(row,col);
    printDat(getDataPtr,row,col);
    augmentPtr = augment(getDataPtr, row, col);
    printDat(augmentPtr,row + 1,col + 1);
        
        
    
           destroy(getDataPtr,row);
           destroy(augmentPtr,row);
	//your code here
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

    
    return array;
}//Get the Matrix Data

void printDat(int **ptr,int row ,int col) {
    
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
}//Print the Matrix
    

int **augment(int **ptr,int row,int col) {
    
    int **tempPtr = new int *[row + 1];
    for(int i = 0;i < row + 1;i++) {
        tempPtr[i] = new int[col + 1]; 
    }

    for(int i = 0; i < (row + 1);i++) {
        for(int j = 0;j < (col + 1); j++) {

            tempPtr[i][j] = 0;
        
        }
    } 
        for(int i = 0; i < (row);i++) {
            for(int j = 0;j < (col); j++) {

            tempPtr[i + 1][j + 1] = ptr[i][j];
        
        }
    } 

    
    return tempPtr;   
}//Augment the original array

void destroy(int **ptr,int row) {
    
    for(int i = 0; i < row; i++) {
        
        delete[] ptr[i];   
    }
    
    delete[] ptr;
}//Destroy the Matrix, i.e., reallocate memory
