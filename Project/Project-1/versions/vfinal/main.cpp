

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

PlayerInfo* gameStart(int); //
void recordBets(PlayerInfo*,int);
void playerTurn(PlayerInfo*,int,int);
int value2int(string ,int ,PlayerInfo*);
int checkBlackJack(PlayerInfo*,int, bool &);
cards pickCard(cardDeck*);
cardDeck* fillCardDeck();


int main() {
   
    srand(static_cast<unsigned int>(time(0)));
    
    int playerCount = 0;//How many players at the table other than the dealer
    PlayerInfo *players;//Struct that holds players information
    cardDeck *deck;//Struct that holds the deck information
    cards currentCard; //Struct holding the current card information
    int checkBJ; // Value to check which player got Blackjack
    int hitStand;//Variable to see if the player wants to hit or stand
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
    checkBJ = checkBlackJack(players,playerCount + 1,blackJack); 
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
    
    //Start adding initial card values
    for(int i = 0;i < playerCount + 1;i++) {
        
        playerTurn(players,players[i].playersHand.size(),i);
    }
    //End adding initial card values
    
    
    //Start the rest of the game process
        for(int i = playerCount + 1;i > -1;i--) { //Loop through all players plus dealer
            if(players[0].bust == false) { //Check if dealer has gone over 21
                if(i == 0) { //Check if players is dealer
                    if(players[i].total < 17 ) { //Check that dealer's hand is less than 17

                        while(players[i].total < 17 ) { //Dealer should keep drawing cards until he has 17 or over

                            currentCard = pickCard(deck); 
                            players[i].playersHand.push_back(currentCard);
                            playerTurn(players,players[i].playersHand.size(),i);
                        }
                    }
                }
                else {

                    while(players[i].total < 22 && hitStand != 2) { //Loop until player has bust or wants to stand

                        cout << "Would you like to hit " << "Player #" << i << " your total is "<< players[i].total << endl;
                        cout << "1) Hit \t 2) Stand \n";
                        cin >> hitStand;
                        if (hitStand == 1) { //Check if player wants to hit
                            currentCard = pickCard(deck);
                            players[i].playersHand.push_back(currentCard);
                            playerTurn(players,players[i].playersHand.size(),i);  
                        }
                    }
                    hitStand = 1; //Reset hitStand value for next player
                }
            }
        }
    //End of the game process 
    if(blackJack == false) { //Check if any player got blackjack(value is referenced in a function)
        
        int temp = 0;
        int winner;//Player with highest numeric deck value and not over 21
        for(int i = 0;i < playerCount + 1;i++) { //Loop through all players and dealer
            
            if(players[i].bust == false) { //Check if player has busted so they can't be considered a winner
                if (temp < players[i].total) { //Check if players hand value is higher then previous player

                    temp = players[i].total;
                    winner = i;//Set player with the best hand
                }
            }
        } 
        if(winner == 0) { //Check if winner is a dealer
            
            cout << "Dealer won with a total of " << players[winner].total << endl;
        }
        else { //If winner is a player
            
            cout << "Player #" << winner << " wins with a total of "<< players[winner].total << endl;
        }
    }
    
    delete []deck;//Free memory
    delete []players;//Free memory

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
    bool validCard = false;   //Used for the while loop to find a card that hasn’t been dealt
    int i;

    while (validCard == false) { //Loop until found valid card
        
        i = rand() % SIZE;
        if (deck[i].hasDealt != true) { //Check if rand card is valid

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
    
    
    PlayerInfo *players = new PlayerInfo[count]; //Allocate memory for dynamic player array

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
     
    cardDeck *deck = new cardDeck[SIZE]; //Allocate memory for dynamiclly allocated card deck
    int j = 2;
    int h = 2;
    int l = 2;
    
    for(int i = 0;i < SIZE;i++) { //Loop through the size of the array(52)
        deck[i].hasDealt = false; //Make all cards dealt value false
        if (i < 13) { //First suit of cards
            deck[i].suit = suits[0]; 
            if (i < 9) {
                deck[i].value = to_string(i + 2);
            }
            else if (i == 9) {
                deck[i].value = "A";//Face cards
            }
            else if (i == 10) {
                deck[i].value = "J";//Face cards
            }
            else if (i == 11) {
                deck[i].value = "Q";//Face cards
            }
            else {
                deck[i].value = "K";//Face cards
            }
        }else if(i >= 13 && i <= 25) { //Second suit of cards
            
            deck[i].suit = suits[1];
            if (i < 22) {
                deck[i].value = to_string(j);
            }
            else if (i == 22) {
                deck[i].value = "A";//Face cards
            }
            else if (i == 23) {
                deck[i].value = "J";//Face cards
            }
            else if (i == 24) {
                deck[i].value = "Q";//Face cards
            }
            else {
                deck[i].value = "K";//Face cards
            }
            j++;  
        }else if(i > 25 && i <= 38) { //Third suit of cards
            deck[i].suit = suits[2];
            if (i < 33) {
                deck[i].value = to_string(h);
            }
            else if (i == 35) {
                deck[i].value = "A";//Face cards
            }
            else if (i == 36) {
                deck[i].value = "J";//Face cards
            }
            else if (i == 37) {
                deck[i].value = "Q";//Face cards
            }
            else {
                deck[i].value = "K";//Face cards
            }
            h++;
        }else {                     //Fourth suit of cards
            deck[i].suit = suits[3];
            if (i < 47) {
                deck[i].value = to_string(l);
            }
            else if (i == 47) {
                deck[i].value = "A";//Face cards
            }
            else if (i == 48) {
                deck[i].value = "J";//Face cards
            }
            else if (i == 49) {
                deck[i].value = "Q";//Face cards
            }
            else {
                deck[i].value = "K";//Face cards
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
    
    ofstream file; //File variable name
    int bet = 0;
    
    file.open("PlayerBets.bin", ios::app | ios::out | ios::binary); //Open binary file
    
    for(int i = 1;i < count;i++) { //Loop through each player
        
        cout << "What would you like to bet player #" << i << ":" << endl;
        cin >> bet; // Get players bet
        players[i].bet = bet;
        file.write(reinterpret_cast<char*>(&players[i].bet), sizeof(bet)); //Data written to binary file
    } 
    
    file.close(); //Close binary file
    
}


//***********************************
// checkBlackJack 
// Desc:
// Checks if any of the players have
// gotten blackjack
//***********************************
int checkBlackJack(PlayerInfo* players,int count, bool &blackJack) {
    
    cards firstCard;//Players first card 
    cards secondCard;//Players second card
    int playerIndex = 0;

    for(int i = 0;i < count;i++) { //Loop through all players
        firstCard = players[i].playersHand.at(0);
        secondCard = players[i].playersHand.at(1);
            if (firstCard.value == "A" && secondCard.value == "10") { //Check for blackjack v1


                playerIndex = i;//return value
                blackJack = true;//Used later in program to stop last check
                break;
            }
            else if (firstCard.value == "10" && secondCard.value == "A") { //Check for blackjack v2


                playerIndex = i;//return value
                blackJack = true;//Used later in program to stop last check
                break;
            }
            else {
                playerIndex = 99;//return value
            }
    }

    return playerIndex; //return
}

//***********************************
// playerTurn 
// Desc:
// Checks if any of the players have
// gotten blackjack
//***********************************
void playerTurn(PlayerInfo* players, int size,int playerNumber) {
    
    int temp;
    players[playerNumber].total = 0;
    cards *tempHand = new cards[size]; //Dynamic array used to get values from the vector of cards in playersHand
    
        if (players[playerNumber].bust == false && players[0].bust == false) { //Check if player has but and dealer hasn't bust
            for(int j = 0;j < size;j++) { //Loop through size of playershand
                tempHand[j] = players[playerNumber].playersHand.at(j);  //Assign dynamic array values
                temp = value2int(tempHand[j].value,playerNumber,players); // Get numeric value from card
                players[playerNumber].total += temp; // Add numeric value to player total
                if(players[playerNumber].total > 21) { //Check if players total is over 21
                    
                    players[playerNumber].bust = true; //Set player to bust so they can't play anymore
                    if(playerNumber == 0) { //Checks if players going over is the dealer
                        cout << "Dealer went over 21 with "; //Outout dealer bust
                        for(int i = 0;i < size;i++) { //Loop to print out each card the player has

                            cout << "["<< tempHand[i].suit << "," << tempHand[i].value << "]";
                        }
                    cout << endl; 
                    cout << "All players win" << endl;
                    }  
                    else {
                        cout << "Player #" << playerNumber << " went over 21 with "; //Output saying player bust
                        for(int i = 0;i < size;i++) { //Loop to show all the cards in the players hand

                            cout << "["<< tempHand[i].suit << "," << tempHand[i].value << "]";
                        }
                    cout << endl;
                    }
                    delete[]tempHand; //Free memory
                    return;        
                }
            }
            if (playerNumber == 0) { // Check if player is dealer
                cout << "Dealer has "<< players[playerNumber].total << " with "; //Output to player the dealers hand numeric value
                for(int i = 0;i < size;i++) { //Loop to show all the cards in the players hand
                    
                    cout << "["<< tempHand[i].suit << "," << tempHand[i].value << "]"; 
                }
                cout << endl;
            }
            else {
                cout << "Player #" << playerNumber <<" has "<< players[playerNumber].total << " with ";//Output players hand numeric value
                for(int i = 0;i < size;i++) { //Loop to show all the cards in the players hand
                    
                    cout << "["<< tempHand[i].suit << "," << tempHand[i].value << "]";
                }
                cout << endl;
            }
        }
        else {
            
            cout << "Player #" << playerNumber << " has gone over 21, so they lost with "; //Output that player bust
                for(int i = 0;i < size;i++) { //Loop to show cards in players hand
                    
                    cout << "["<< tempHand[i].suit << "," << tempHand[i].value << "]";
                }
                cout << endl;
        }
    delete []tempHand; //Free memory
}

//***********************************
// value2int
// Desc:
// Gets the numeric value of the card
//***********************************
int value2int(string value,int playerNumber,PlayerInfo* players) {
    
    int intValue; //Numeric value of a card
    int choice = 0;
    cards mostRecent = players[playerNumber].playersHand.at(players[playerNumber].playersHand.size() - 1);
    
        if (value == "A") { //Card is an ace
            if(playerNumber == 0) { //If dealer value 1 or 11 is rand()
                choice = rand() % 2 + 1;
            }
            else {
            cout << "Player #" << playerNumber << " your most recent card was " << "["<< mostRecent.suit << "," << mostRecent.value << "]" << endl;
            cout << endl << "Would you want that Ace in your deck to count as 1 or 11" << endl;
            cout << "Enter 1) 1 for 1 and 2) for 11" << endl;
            cin >> choice;//Input if the card should be worth 1 or 11
            }
                if(choice == 1) {
                    intValue = 1;
                }
                if(choice == 2) {
                    intValue = 11;
                }
        }
        else if(value == "Q") { // Card is Queen
            intValue = 10;
        }
        else if(value == "J") { //Card is Jack
            intValue = 10;
        }
        else if(value == "K") { //Card is King
            intValue = 10;
        }
        else if(value == "2") { //Card is value
            intValue = 2;
        }
        else if(value == "3") { //Card is value
            intValue = 3;
        }
        else if(value == "4") { //Card is value
            intValue = 4;
        }
        else if(value == "5") { //Card is value
            intValue = 5;
        }
        else if(value == "6") { //Card is value
            intValue = 6;
        }
        else if(value == "7") { //Card is value
            intValue = 7;
        }
        else if(value == "8") { //Card is value
            intValue = 8;
        }
        else if(value == "9") { //Card is value
            intValue = 9;
        }
        else if(value == "10") { //Card is value
            intValue = 10;
        }
        else { // Return if somehow a foreign card is played
            cout << "Invalid Card" << endl;
            intValue = 99;
        }

    return intValue; //return card numeric value
}




