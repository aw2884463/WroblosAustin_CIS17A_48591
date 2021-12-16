#include <iostream>

using namespace std;


int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array

int main(){
    
    int *getDataptr;
    int *augmentptr;
    int size;
    
        
        getDataptr = getData(size);
        prntAry(getDataptr, size);
        cout << endl;
        
        augmentptr = augment(getDataptr, size);
        prntAry(augmentptr, size + 1);
	//your code here
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

int *augment(const int *ptr,int size) {
    
    
    
    int *tempptr = new int [size + 1];
    
    tempptr[0] = 0;
    
    for(int i = 0;i < size + 1;i++) {
        tempptr[i+1] = ptr[i];
    }
    
    return tempptr;
}//Augment and copy the original array

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

