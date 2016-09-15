//
//  Deck.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Deck.hpp"


void printDeck(const std::array<Card, 52>& deck)
{
    for (const auto& elem : deck)
    {
        std::cout << elem.rank << elem.suit << std::endl;
    }
}

std::array<Card, 52> fillDeck()
{
    std::array<Card, 52> deck;
    int card = 0;
    for (int suit = 0; suit < static_cast<int>(Suits::max_suits); ++suit)
    {
        for (int rank = 0; rank < static_cast<int>(Ranks::max_ranks); ++rank)
        {
            deck[card].suit = static_cast<Suits>(suit);
            deck[card].rank = static_cast<Ranks>(rank);
            ++card;
        }
    }
    return deck;
}

void shuffleDeck(std::array<Card,52>& d)
{
    for (int i = 0; i < d.size(); ++i)
    {
        std::swap (d[i], d[randomMersenne()]);
        d[i].shuffeled = true;
    }
}