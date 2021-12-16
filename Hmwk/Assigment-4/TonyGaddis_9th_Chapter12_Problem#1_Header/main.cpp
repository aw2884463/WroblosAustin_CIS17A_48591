

#include <cstdlib>  //Standard library
#include <iostream> // Input Output
#include <iomanip>  // Input/Output manipulation
#include <string>   // Getline
#include <fstream>  //Input output file stream
#include <array>    // Array library
#include <cctype>
#include <valarray>   // Upper and Lowercase manipulation


using namespace std;


int main() {
    
    string name = "testing.txt";
    fstream file;
    string line = "";
    string temp = "";
    int lines = 0;
    
    
    file.open(name, ios::in); 
    
    if(file.is_open()) {
        
        while(getline(file,line)) {
            
            lines++;
        }
    }
    file.close();
     
    file.open(name, ios::in); 
    if(lines < 10) {
       
        for(int i = 0; i < lines;i++) {
            
        getline(file,line);
        cout << line << endl;
        
        }
        cout << "Whole file has been printed" << endl;
    }
    else {
        
        for(int i = 0;i < 10;i++) {
            getline(file,line);
            cout << line << endl;
            
        }
        cout << "Header(or first 10 lines) Printed Out";
    }
    file.close();
    return 0;
}

