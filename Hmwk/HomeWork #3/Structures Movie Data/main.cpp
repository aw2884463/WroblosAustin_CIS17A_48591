/* 
 * File:   
 * Author: Austin Wroblos
 * Created on 10/6/2021 10:00AM
 * Purpose: Quarterly Sales report
 */

#include <iostream>
#include <string>

using namespace std;

struct MovieData {
    
    string title;
    string director;
    int year;
    int length;
};

int main(){
	//your code here
	int movieCount;
	string title;
	string director;
	int year;
	int length;
	MovieData movieData;
	
	
    cout << "This program reviews structures" << endl;
	cout <<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
	cin >> movieCount;
	
	
	for(int i = 0;i < movieCount; i++) {
	    
	getline(cin, title);
	getline(cin, title);
	getline(cin, director);
	cin >> year;
	cin >> length;
	
    movieData.title = title;
	movieData.director = director;
	movieData.year = year;
	movieData.length = length;
	
	
	
	cout << endl;
	cout << "Title:     " << movieData.title << endl;
	cout << "Director:  " << movieData.director << endl;
	cout << "Year:      " << movieData.year << endl;
	cout << "Length:    " << movieData.length << endl;
	}
	return 0;
}