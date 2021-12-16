#include <iostream>
#include <string>
using namespace std;



struct Drink{
    
    string name;
    unsigned short cost, numDrnk;
};


int main(){
    //your code here
    int pick;
    int total=0;
    bool run=true;
    const int DRINKS=5;
    
    Drink drink[DRINKS]={{"Cola",75,20}, {"Rootbeer",75,20}, {"Lemon-Lime",75,20}, {"Grape Soda",80,20}, {"Cream Soda",80,20}};
    
    while(run == true) {

        string choice;
        int amount;
            
        cout << "Cola       " << drink[0].cost << "  " << drink[0].numDrnk << endl;
        cout << "Root Beer  " << drink[1].cost << "  " << drink[1].numDrnk << endl;
        cout << "Lemon-Lime " << drink[2].cost << "  " << drink[2].numDrnk << endl;
        cout << "Grape Soda " << drink[3].cost << "  " << drink[3].numDrnk << endl;
        cout << "Cream Soda " << drink[4].cost << "  " << drink[4].numDrnk << endl;
        cout << "Quit" << endl;
        
        
        getline(cin,choice);
        cin>>amount;
        
        
        if(choice=="Quit") {
            
            run=false;
            cout<<total<<endl;
        }
        
        if(amount>100 || amount<0) {
            
            cout<<"ERROR: Amount entered must be less than a dollar and positive.";
        }
        
        
        if(choice=="Cola"){
            pick=0;
        }
        else if(choice=="Root Beer") {
            
            pick=1;
        }
        else if(choice=="Lemon-Lime") {
            
            pick=2;
        }
        else if(choice=="Grape Soda") {
            
            pick=3;
        }
        else if(choice=="Cream Soda") {
            
            pick=4;
        }
        
        
        if(amount<drink[pick].cost) {
            cout<<"Not enough money entered.";
        }
        
        else if(choice!="Quit"&&amount>=drink[pick].cost) {
            cout<<amount-drink[pick].cost<<endl;
            total+=drink[pick].cost;
            drink[pick].numDrnk-=1;
        }
        cin.ignore();
    }
    
    return 0;
}