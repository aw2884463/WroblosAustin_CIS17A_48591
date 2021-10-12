#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int *getData(int &);         //Return the array size and the array

void prntDat(int *,int);    //Print the integer array

float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data

void prntMed(float *, int);     //Print the median Array

int main(){
    
    int size;
    int *getDataPtr;
    float *medianPtr;
    
    
    getDataPtr = getData(size);
    prntDat(getDataPtr,size);
    
    medianPtr = median(getDataPtr,size);
    
    prntMed(medianPtr,size);
    
	//your code here
	return 0;
}


int *getData(int &size) {
    
    cin >> size;
    
    int *ptr = new int [size];
    
    
    for(int i = 0;i < size;i++) {
        
        cin >> ptr[i];
    }
    return ptr;
}

void prntDat(int *ptr,int size) {
    
    for(int i = 0; i < size; i++) {
        
        if(i < size - 1) {
        
        cout << ptr[i] << " ";
        }
        else {
            cout << ptr[i];
        }
    }
    cout << endl;
}

float *median(int *ptr,int size) {
    
    float *floatArray = new float [size + 2];
    float median =0;
    
    floatArray[0] = size + 2;
    
    if(size%2 == 0) {
        median = (ptr[(size-1)/2] + ptr[size/2])/2.0;
    }
    // if number of elements are odd
    else {
        median = ptr[size/2];
    }
    
    floatArray[1] = median;
    
    
    
    for(int i = 0; i < size + 2; i++) {
        
        floatArray[i + 2] = ptr[i];
        
            
    }
    

    

   return floatArray; 
}

void prntMed(float *ptr, int size) {
    
        cout << ptr[0] << " ";
        cout << fixed <<setprecision(2) << ptr[1] << " ";
    
    for(int i = 0; i < size + 2; i++) {
        
        if(i < size - 1) {
            
            if (ptr[i + 2] == 0) {
                
                cout << fixed << setprecision(0) << ptr[i + 2] << " "; 
            }
            else {
        cout << fixed << setprecision(2) << ptr[i + 2] << " ";
            }
        
        }
        else if ( i < size){
            
            if(ptr[i + 2] == 0) {
                
                cout << fixed << setprecision(0) << ptr[i + 2];
            }
            else {
            cout << fixed << setprecision(2) << ptr[i + 2];
            }
        }
        
    }
       
}

