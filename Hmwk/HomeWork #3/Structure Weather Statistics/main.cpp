/* 
 * File:   
 * Author: Austin Wroblos
 * Created on 10/6/2021 10:56AM
 * Purpose: Quarterly Sales report
 */
 
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

struct WeatherStat {
    
    string month;
    float rainfall;
    int highTemp;
    int lowTemp;
    float average;
  
    
};

int highest(int [], int,int &);
int lowest(int [], int, int &);
float rainAverage(int [], int);
int tempAverage(int [], int [], int);

int main(){
    
    string month = "";
    float rainfall = 0;
    int highTemp = 0;
    int lowTemp = 0;
    int tempH = 0;
    int tempL = 0;
    int indxH = 0;
    int indxL = 0;
    const int SIZE = 12;
    string months[SIZE];
    int rain[SIZE];
    int lowTemps[SIZE];
    int highTemps[SIZE];
    WeatherStat weatherStat;
    
    for(int i = 0;i < SIZE;i++) {
    
        cin >> month;
        cin >> rainfall;
        cin >> lowTemp;
        cin >> highTemp;
    
        if(lowTemp > -100 && lowTemp < 140) {
            if(highTemp > -100 && highTemp < 140) {
            
                weatherStat.month = month;
                weatherStat.rainfall = rainfall;
                weatherStat.highTemp = highTemp;
                weatherStat.lowTemp = lowTemp;
            
                months[i] = weatherStat.month;
                rain[i] = weatherStat.rainfall;
                lowTemps[i] = weatherStat.lowTemp;
                highTemps[i] = weatherStat.highTemp;

            }
        }
   
    }
    tempH = highest(highTemps,SIZE,indxH);
    tempL = lowest(lowTemps,SIZE, indxL);
    weatherStat.average = rainAverage(rain,SIZE);
    
    
    cout << "Average Rainfall " << fixed << setprecision(1) << weatherStat.average << " inches/month" << endl;
    cout << "Lowest  Temperature "  << months[indxL] << "  " << lowTemps[indxL] << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature "  << months[indxH] << "  " << highTemps[indxH] << " Degrees Fahrenheit" << endl;
    
    weatherStat.average = tempAverage(lowTemps,highTemps,SIZE);
    cout << "Average Temperature for the year " << fixed << setprecision(0) << weatherStat.average << " Degrees Fahrenheit" << endl;
      
	//your code here
	return 0;
}



int highest(int array[],int SIZE,int &indxH) {
    
    WeatherStat weatherStat;
    
    weatherStat.highTemp = array[0];
    
    for(int i = 1; i < SIZE; i ++) {
        
        if(array[i] > weatherStat.highTemp) {
            
            weatherStat.highTemp = array[i];
            
            indxH = i;
        }
    }
    
    return weatherStat.highTemp;
}

int lowest(int array[],int SIZE,int &indxL) {
    
    WeatherStat weatherStat;
    
    weatherStat.lowTemp = array[0];
    
    for(int i = 1; i < SIZE; i ++) {
        
        if(array[i] < weatherStat.lowTemp) {
            
            weatherStat.lowTemp = array[i];
            
            indxL = i;
        }
    }
    
    return weatherStat.lowTemp;
}

float rainAverage(int array[],int SIZE) {
    
    float total = 0;
    WeatherStat weatherStat;
    
    for(int i = 0; i < SIZE;i++) {
        
        
        total += array[i];
    }
    weatherStat.average = total / SIZE;
    
    return weatherStat.average;
}

int tempAverage(int array[], int brray[], int SIZE) {
    
    int total = 0;
    WeatherStat weatherStat;
    
    for(int i = 0;i < SIZE; i++) {
        
        total += (array[i] + brray[i]);
    }
    
    weatherStat.average = total / (SIZE * 2) + 1;
    
    return weatherStat.average;
    
}

