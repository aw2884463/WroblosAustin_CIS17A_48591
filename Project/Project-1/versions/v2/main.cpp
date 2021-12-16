

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
int checkBlackJack(PlayerInfo*,int);
cards pickCard(cardDeck*);
cardDeck* fillCardDeck();


int main() {
   
    srand(static_cast<unsigned int>(time(0)));
    
    int playerCount = 0;//How many players at the table other than the dealer
    PlayerInfo *players;//Struct that holds players information
    cardDeck *deck;//Struct that holds the deck information
    cards currentCard; //Struct holding the current card information
    int checkBJ; // Value to check which player got Blackjack
    bool blackJack = false;//Bool to check for BlackJack at all
    
    
    
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
    deck = fillCardDeck();
    currentCard = pickCard(deck);
    //Start dealing  all players their initial two cards
    for(int i = 0; i < playerCount + 1;i++) { 
       for(int j = 0;j < 2;j++) {
           
           currentCard = pickCard(deck);
           players[i].playersHand.push_back(currentCard);
        }    
    }
    //End dealing all players their initial two cards
    
    //Start checking players for natural blackjack
    checkBJ = checkBlackJack(players,playerCount + 1); 
    if (checkBJ == 99) {
        
        cout << "No black jack found on the board" << endl << endl;
    }
    else if (checkBJ == 0){
        
        cards firstCard,secondCard;
        firstCard = players[checkBJ].playersHand.at(0);
        secondCard = players[checkBJ].playersHand.at(1);
        
        cout << endl << "Dealer has BlackJack" << endl;
        cout << firstCard.value << "," << secondCard.value << endl;
        return 0;
    }
    else {
        
        cout << endl << "Congrats, player #" << checkBJ << " you got blackjack and have recieved $"<< players[checkBJ].bet  * 1.5 << endl;
        return 0;
    }
    //End checking players for natural blackjack

    
    delete []deck;
    delete []players;

    return 0;
}

//***********************************
// pickCard 
// Desc:
// Creates the array of playerInfo
// Also sends welcome message
//***********************************
cards pickCard(cardDeck* deck) {
    
    cards currentCard;
    bool validCard = false;   
    int i;

    while (validCard == false) {
        
        i = rand() % SIZE;
        if (deck[i].hasDealt != true) {

            currentCard.suit = deck[i].suit;
            currentCard.value = deck[i].value;
            deck[i].hasDealt = true; 
            validCard = true;
        }
    }
    return currentCard;
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
// fillCardDeck 
// Desc:
// Fills the card deck array
//***********************************
cardDeck* fillCardDeck() {
     
    cardDeck *deck = new cardDeck[SIZE];
    int j = 2;
    int h = 2;
    int l = 2;
    
    for(int i = 0;i < SIZE;i++) {
        deck[i].hasDealt = false;
        if (i < 13) {
            deck[i].suit = suits[0]; 
            if (i < 9) {
                deck[i].value = to_string(i + 2);
            }
            else if (i == 9) {
                deck[i].value = "A";
            }
            else if (i == 10) {
                deck[i].value = "J";
            }
            else if (i == 11) {
                deck[i].value = "Q";
            }
            else {
                deck[i].value = "K";
            }
        }else if(i >= 13 && i <= 25) {
            
            deck[i].suit = suits[1];
            if (i < 22) {
                deck[i].value = to_string(j);
            }
            else if (i == 22) {
                deck[i].value = "A";
            }
            else if (i == 23) {
                deck[i].value = "J";
            }
            else if (i == 24) {
                deck[i].value = "Q";
            }
            else {
                deck[i].value = "K";
            }
            j++;  
        }else if(i > 25 && i <= 38) {
            deck[i].suit = suits[2];
            if (i < 33) {
                deck[i].value = to_string(h);
            }
            else if (i == 35) {
                deck[i].value = "A";
            }
            else if (i == 36) {
                deck[i].value = "J";
            }
            else if (i == 37) {
                deck[i].value = "Q";
            }
            else {
                deck[i].value = "K";
            }
            h++;
        }else {
            deck[i].suit = suits[3];
            if (i < 47) {
                deck[i].value = to_string(l);
            }
            else if (i == 47) {
                deck[i].value = "A";
            }
            else if (i == 48) {
                deck[i].value = "J";
            }
            else if (i == 49) {
                deck[i].value = "Q";
            }
            else {
                deck[i].value = "K";
            }
            l++;    
        }       
    } 
    return deck;
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


//***********************************
// checkBlackJack 
// Desc:
// Checks if any of the players have
// gotten blackjack
//***********************************
int checkBlackJack(PlayerInfo* players,int count) {
    
    cards firstCard;
    cards secondCard;
    int playerIndex = 0;

    for(int i = 0;i < count;i++) {
        firstCard = players[i].playersHand.at(0);
        secondCard = players[i].playersHand.at(1);
            if (firstCard.value == "A" && secondCard.value == "10") {


                playerIndex = i;
                break;
            }
            else if (firstCard.value == "10" && secondCard.value == "A") {


                playerIndex = i;
                break;
            }
            else {
                playerIndex = 99;
            }
    }

    return playerIndex;
}




