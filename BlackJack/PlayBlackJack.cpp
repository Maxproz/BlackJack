//
//  PlayBlackJack.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "PlayBlackJack.hpp"


char hitOrStand()
{
    // players stuff
    std::cout << "Hit or Stand? (type h, or s, then press enter):\n";
    char choice;
    do
    {
        std::cin >> choice;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 'h' && choice != 's');
    
    return choice;
}

void printWinner(const gameResult& result)
{
    switch (result)
    {
        case gameResult::WIN:   std::cout << "PLAYER WINS!"       << std::endl; break;
        case gameResult::LOSE:  std::cout << "DEALER WINS!"       << std::endl; break;
        case gameResult::PUSH:  std::cout << "PUSH - SAME SCORE"  << std::endl; break;
        default: error("invalid game result");          break;
    }
}

void printDealersScore(const int& dealersScore)
{
    std::cout << "Dealers Score: " << dealersScore << std::endl;
}

void printPlayersScore(const int& playersScore)
{
    std::cout << "Players Score: " << playersScore << std::endl;
}

gameResult playblackjack(std::array<Card,52> deck)
{
    if (deck.at(0).shuffeled == false)
        shuffleDeck(deck);
    
    Card* cardptr = &deck.at(0);
    
    int players_total_so_far = 0;
    int dealers_total_so_far = 0;
    
    // Give the dealer one card
    dealers_total_so_far += getCardValue(*cardptr++);
    
    // Give the player two cards.
    players_total_so_far += getCardValue(*cardptr++);
    players_total_so_far += getCardValue(*cardptr++);
    
    // Player goes First, Hit or Stand?
    bool playersTurn = true;
    while (playersTurn == true)
    {
        printPlayersScore(players_total_so_far);
        
        char choice = hitOrStand();
        
        // If stand turn over, if hit card++ and add value of that card to total score
        if (choice == 's')
        {
            std::cout << "Player Stands " << std::endl;
            playersTurn = false;
        }
        
        else if (choice == 'h')
        {
            std::cout << "Player Hits: " << std::endl;
            players_total_so_far += getCardValue(*cardptr++);
            if (players_total_so_far > 21)
            {
                // if total_score > 21 bust, lose right away
                return gameResult::LOSE;
            }
        }
    }
    // ace == 11 for now
    // dealer goes after player
    // dealer draws until they reach a score of 17 or more, at which point they stand.
    bool dealersTurn = true;
    while (dealersTurn == true)
    {
        printDealersScore(dealers_total_so_far);
        
        if (dealers_total_so_far < 17)
        {
            std::cout << "Dealer Hits: " << std::endl;
            dealers_total_so_far += getCardValue(*cardptr++);
        }
        else if (dealers_total_so_far > 21)
        {
            return gameResult::WIN;
        }
        else
            
            dealersTurn = false;
    }
    
    // backup checking for 17-21 cases.
    if (players_total_so_far == dealers_total_so_far)
        return gameResult::PUSH;
    else if (players_total_so_far > dealers_total_so_far)
        return gameResult::WIN;
    else
        return gameResult::LOSE;
}
