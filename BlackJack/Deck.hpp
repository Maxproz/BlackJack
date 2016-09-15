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
    const unsigned short _decksize = 51; // 0-51
    std::vector<Card> deck;
private:
    Deck()
    {
        for (int i = 0; i < _decksize; ++i)
        {
            Card card;
            deck.push_back(card);
        }
    }
};

void printDeck(const std::array<Card, 52>& deck);
std::array<Card, 52> fillDeck();
void shuffleDeck(std::array<Card,52>& d);

#endif /* Deck_hpp */
