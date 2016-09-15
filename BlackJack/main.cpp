//
//  main.cpp
//  BlackJack
//
//  Created by max dietz on 9/14/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include <iostream>
#include <array>
#include "Deck.hpp"
#include "Card.hpp"
#include "PlayBlackJack.hpp"
#include "RandomGenerators.hpp"

// blackjack gen (0,51)
boost::mt19937 gen;

int main()
{
    
    std::cout << "Hello, what game would you like to play? ";
    
    
    gen.seed(static_cast<unsigned int>(std::time(0)));
    std::array<Card, 52> deckkkk;
    deckkkk = fillDeck();
    
    shuffleDeck(deckkkk);
    printDeck(deckkkk);
    
    gameResult resulttt = gameResult::IN_PROGRESS;
    resulttt = playblackjack(deckkkk);
    
    printWinner(resulttt);
    
    return 0;
}












