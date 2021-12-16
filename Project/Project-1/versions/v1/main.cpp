

/* 
 * File:   main.cpp
 * Author: Austin
 *
 * Created on November 1, 2021, 6:30 PM
 */

#include <cstdlib>  // Standard library
#include <ctime>    //Time Library
#include <iostream> // Input Output
#include <iomanip>  // Input/Output manipulation
#include <string>   // Getline
#include <fstream>  // Input output file stream
#include <array>    // Array library
#include <vector>   // Vector Library
#include <cctype>   // Upper and Lowercase manipulation


using namespace std;

    const int SIZE = 52;//Deck size
    const char suits[4] = {'H','S','D','C'};//H-Heart S-Spade D-Diamond C-Club


//Each card in a players hand
struct cards {  
    
    char suit;
    string value;
};

//Holds all information about the player 
struct PlayerInfo {
    
    vector<cards> playersHand;
    int bet;
    bool bust = false;
    int total;
    
};

//Holds the values of the card deck
struct cardDeck {
    
    char suit;
    string value;
    bool hasDealt;
    
};

PlayerInfo* gameStart(int);
void recordBets(PlayerInfo*,int);


int main() {
   
    srand(static_cast<unsigned int>(time(0)));
    
    int playerCount = 0;//How many players at the table other than the dealer
    PlayerInfo *players;//Struct that holds players information
    
    
    
    //Start asking user for how many players are in the game
    while (playerCount <= 0 || playerCount > 11) { 
    cout << "Please enter how many players will be seated tonight(1-11):";
    cin >> playerCount;
    
        if (playerCount <= 0 || playerCount > 11) {
            cout << "Please enter a valid amount of players!!!" << endl;
        }
    
    }
    //End asking user for how many players are in the game
    players = gameStart(playerCount + 1);
    recordBets(players,playerCount + 1);

    delete []players;

    return 0;
}

//***********************************
// gameStart 
// Desc:
// Creates the array of playerInfo
// Also sends welcome message
//***********************************
PlayerInfo* gameStart(int count) {
    
    
    PlayerInfo *players = new PlayerInfo[count];
    
    
    
    cout << endl << "Hello players, welcome to Austin's underground casino" << endl;
    cout << "Lets play some Blackjack" << endl;
    return players;
     
}


//***********************************
// recordBets 
// Desc:
// Records player bets and writes
// to binary files
//***********************************
void recordBets(PlayerInfo* players,int count) {
    
    ofstream file;
    
    file.open("PlayerBets.bin", ios::app | ios::out | ios::binary);
     
    int bet = 0;
    
    for(int i = 1;i < count;i++) {
        
        cout << "What would you like to bet player #" << i << ":" << endl;
        cin >> bet;
        players[i].bet = bet;
        file.write(reinterpret_cast<char*>(&bet), sizeof(bet));
    } 
    
    file.close();
}







