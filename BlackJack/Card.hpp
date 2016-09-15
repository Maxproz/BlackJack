//
//  Card.hpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include "MPErrors.hpp"

enum class Ranks
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
    max_ranks
};

enum class Suits
{
    clubs,
    diamonds,
    hearts,
    spades,
    max_suits
};

struct Card
{
    Ranks rank;
    Suits suit;
    bool shuffeled = false;
};

std::ostream& operator<<(std::ostream& os, const Ranks& r);
std::ostream& operator<<(std::ostream& os, const Suits& s);
void printCard(const Card& card);
int getCardValue(const Card& card);
void swapCard(Card &a, Card &b);
void printCard(const std::unique_ptr<Card> cp);

#endif /* Card_hpp */
