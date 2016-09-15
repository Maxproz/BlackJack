//
//  Deck.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Deck.hpp"

void printDeck(const Deck& deck)
{
    for (const auto& elem : deck.cards)
    {
        std::cout << elem.rank << elem.suit << std::endl;
    }
}

std::vector<Card> fillDeckWithCards()
{
    Deck deck;
    deck.cards.reserve(52);
    for (int i = 0; i < 51; ++i)
    {
        Card card;
        deck.cards.push_back(card);
    }
    int card = 0;
    for (int suit = 0; suit < static_cast<int>(Suits::max_suits); ++suit)
    {
        for (int rank = 0; rank < static_cast<int>(Ranks::max_ranks); ++rank)
        {
            deck.cards[card].suit = static_cast<Suits>(suit);
            deck.cards[card].rank = static_cast<Ranks>(rank);
            ++card;
        }
    }
    return deck.cards;
}

void shuffleDeck(Deck& d)
{
    for (int i = 0; i < d.cards.size(); ++i)
    {
        std::swap (d.cards[i], d.cards[randomMersenne()]);
        d.cards[i].shuffeled = true;
    }
}