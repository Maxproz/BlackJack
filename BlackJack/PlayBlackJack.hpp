//
//  PlayBlackJack.hpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef PlayBlackJack_hpp
#define PlayBlackJack_hpp
#include <array>
#include "Card.hpp"
#include <iostream>
#include "MPErrors.hpp"
#include "Deck.hpp"

// not being used, maybe put in later
//constexpr int PUSH = -100;
//const int STAND = 1000;
//const int HIT   = 2000;

// Keeping a pointer to the next in the deck to be dealt out is nice.
// Whenever we need to deal a card, we get the value of the current card, and then
// advance the pointer to the next card. This can be done in one operation.
// getCardValue(*cardptr++);

// This returns the current card's value
// (which can then be added to the player or dealers total)
// and then advances cardptr to the next card

enum class gameResult
{
    IN_PROGRESS,
    WIN,
    LOSE,
    PUSH
};

char hitOrStand();
void printWinner(const gameResult& result);

void printDealersScore(const int& dealersScore);
void printPlayersScore(const int& playersScore);
gameResult playblackjack(std::array<Card,52> deck);

// should have used, typedef std::array<Card,52> Deck;


#endif /* PlayBlackJack_hpp */
