//
//  Deck.hpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp
#include <iostream>
#include "Card.hpp"
#include <array>
#include <vector>
#include "RandomGenerators.hpp"

class Deck
{
private:
    int _decksize = 51; // 0-51
public:
    std::vector<Card> cards;
};

void printDeck(const Deck& deck);
std::vector<Card> fillDeckWithCards();
void shuffleDeck(Deck& d);

#endif /* Deck_hpp */
