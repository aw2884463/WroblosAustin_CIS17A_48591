

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;


int *getData(int &);               //Fill the array

int *sort(const int *,int);       //Sort smallest to largest

int *reverse(const int *,int);  //Sort in reverse order

void prntDat(const int *,int); //Print the array

int main() {
    
    int *getDataptr;
    int *sortptr;
    int *reverseptr;
    int size;
    
    
    getDataptr = getData(size);
    
    sortptr = sort(getDataptr,size);
    prntDat(sortptr,size);
    cout << endl;
    
    reverseptr = reverse(sortptr,size);
    prntDat(reverseptr,size);
   
    

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

int *sort(const int *ptr,int size) {
    
    int *arrayptr = new int [size];
    
    
    for(int i = 0;i < size;i++) {
        
        arrayptr[i] = ptr[i];
    }
    
    for(int j = 0; j < size - 1; j++) {
    for(int i = 0; i < size - j - 1;i++) {
        
        if(arrayptr[i + 1] < arrayptr[i]) {
            
            int temp = arrayptr[i + 1];
            arrayptr[i + 1] = arrayptr[i];
            arrayptr[i] = temp;
        }
    }
  }
  return arrayptr;      
}


int *reverse(const int *ptr,int size) {
    
        int *arrayptr = new int [size];
    
    
    for(int i = 0;i < size;i++) {
        
        arrayptr[i] = ptr[i];
    }
    
    for(int j = 0; j < size - 1; j++) {
    for(int i = 0; i < size - j - 1;i++) {
        
        if(arrayptr[i + 1] > arrayptr[i]) {
            
            int temp = arrayptr[i + 1];
            arrayptr[i + 1] = arrayptr[i];
            arrayptr[i] = temp;
        }
    }
  }
  return arrayptr; 
    
}


void prntDat(const int *ptr,int size) {
    
    for(int i = 0; i < size;i++) {
        
        cout << ptr[i] << " ";
         
    }  
}

