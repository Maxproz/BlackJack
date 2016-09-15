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
    // seed my random number generators.
    gen.seed(static_cast<unsigned int>(std::time(0)));
    
    
    bool playing_games = true;
    while (playing_games)
    {
        // Present the player with games to play.
        std::cout << "Hello, what game would you like to play? ";
        std::cout << "\n1: BlackJack: ";
        std::cout << "\n2: Ultimate Texas Holdem: ";
        std::cout << "\n3: Placeholder: \n";
        
        // store choice in an int, loop to prevent bad input.
        int choose_game;
        do
        {
            std::cin >> choose_game;
        } while (choose_game < 0 && choose_game > 3);
        
        // Make infinite loop that we need to break by changing the bool.
        // switch off of it for easy value extraction.
        switch (choose_game)
        {
            case 1:
            {
                // Preping for a game of blackjack.
                // TODO: Probably can clean this out when I mess with classes again.
                std::array<Card, 52> deck;
                deck = fillDeck();
                shuffleDeck(deck);
                gameResult result = gameResult::IN_PROGRESS;
                result = playblackjack(deck);
                printWinner(result);
                break;
            }
            case 2:
            {
                
            }
            case 3:
            {
                
            }
        }
        std::cout << "Do you want to play another game? Press ('y', or 'n'): \n";
        char play_again_;
        std::cin >> play_again_;
        // loser case this crap to prevent trolls.
        switch (tolower(play_again_))
        {
            case 'y': break;
            case 'n':
                playing_games = false;
                break;
            default:
                error("Bad input for the play again loop. ");
        }
    }
    // playing_games was set to false and player will exit the playing games loop here.
    // present a leaving message.
    std::cout << "Thank you for playing today! " << std::endl;
    return 0;
}











