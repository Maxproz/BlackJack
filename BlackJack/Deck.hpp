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
#include "RandomGenerators.hpp"

void printDeck(const std::array<Card, 52>& deck);
std::array<Card, 52> fillDeck();
void shuffleDeck(std::array<Card,52>& d);

#endif /* Deck_hpp */
