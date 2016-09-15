//
//  UltTexasHoldem.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "UltTexasHoldem.hpp"
#include "Card.hpp"
#include <iostream>
#include <chrono>
#include <thread>

std::pair<int, int> getBlindsAndAntes(Player& p)
{
    displayPlayerChipCount(p);
    int blinds_antes;
    do
    {
        std::cin >> blinds_antes;
    } while (blinds_antes < 5 && (blinds_antes <= p.currentChips()/2));
    
    std::pair<int, int> blindsAntes;
    blindsAntes.first = blinds_antes;
    blindsAntes.second = blinds_antes;
    return blindsAntes;
}

void playUltimateTexasHoldem(Player& p)
{
    std::cout << "Enter an equal bet for anti/blinds that is at least 5 chips.";
    std::cout << "You have " << p.currentChips() << '\n';
    std::cout << "Remember, whatever you bet will subtract 2x from your chip-count.";
    std::cout << std::endl << "How much do you want to bet?" << std::endl;
    std::pair<int, int> blindsAntes = getBlindsAndAntes(p);
    
    /*
     
     need to figure out how I want to subtract players current ante and blind
     they can't take the money back anymore so it should probably be subtracted here.
     
     */
    
    Deck deck;
    deck.cards = fillDeckWithCards();
    shuffleDeck(deck);
    
    Card* cardPtr = &deck.cards[0];
    
    int playersTotal = 0;
    int dealersTotal = 0;
    
    // Two cards are dealt to the player.
    std::shared_ptr<Card> pFirstCard(cardPtr); // assign smart pointer to hold the first cards data.
    playersTotal += getCardValue(*cardPtr);
    printCard(*cardPtr++); // print card value and increment pointer.
    
    std::shared_ptr<Card> pSecondCard(cardPtr); // assign smart pointer to hold the second cards data.
    playersTotal += getCardValue(*cardPtr);
    printCard(*cardPtr++); // print card value and increment pointer.
    
    std::cout << std::endl << std::endl;
    std::cout << "Your hand is: " << pFirstCard->rank << pFirstCard->suit << " "
                                  << pSecondCard->rank << pSecondCard->suit << std::endl;
    
    // Two cards are dealt to the dealer.
    std::shared_ptr<Card> dFirstCard(cardPtr); // assign smart pointer to hold the first cards data.
    playersTotal += getCardValue(*cardPtr);
    printCard(*cardPtr++); // print card value and increment pointer.
    
    std::shared_ptr<Card> dSecondCard(cardPtr); // assign smart pointer to hold the second cards data.
    playersTotal += getCardValue(*cardPtr);
    printCard(*cardPtr++); // print card value and increment pointer.
    
    std::cout << std::endl << std::endl;
    std::cout << "The dealers hand is: " << dFirstCard->rank << dFirstCard->suit << " "
                                         << dSecondCard->rank << dSecondCard->suit << std::endl;
    
    std::cout << "You are able to bet 3x or 4x your ante at this point.\n";
    std::cout << "Would you like to bet?\n";
    /*
     
    implement player choice betting function here
    switch statement with case 3: for three times bet case 4: for four times bet, and 1 for check:
    you will need to pass in blindsAntes so you know much how to 3x and 4x to subtract from players chips.
     
    */
    
    /*
     
     // do player.bet(amount);
     Make sure everything from the last function has been cleaned up.
     
    */
    
    std::cout << "Time for the flop.\n";
    // Timer to reveal the cards one by one.. but not to slow, because that would be annoying.
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    std::shared_ptr<Card> flopCardOne(cardPtr); // assign smart pointer to hold the first flop card.
    printCard(*cardPtr++); // print card value and increment pointer.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    std::shared_ptr<Card> flopCardTwo(cardPtr); // assign smart pointer to hold the first flop card.
    printCard(*cardPtr++); // print card value and increment pointer.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    std::shared_ptr<Card> flopCardThree(cardPtr); // assign smart pointer to hold the first flop card.
    printCard(*cardPtr++); // print card value and increment pointer.
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    
    std::cout << "The flop is: "
                                << flopCardOne->rank    << flopCardOne->suit    << " "
                                << flopCardTwo->rank    << flopCardTwo->suit    << " "
                                << flopCardThree->rank  << flopCardThree->suit  << std::endl;
    
    
    
    bool playing_poker = true;
    
    while (true)
    {
        // placeholder so I can see if code sticks.
    }
}