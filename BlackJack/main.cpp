//
//  main.cpp
//  BlackJack
//
//  Created by max dietz on 9/14/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include <iostream>
#include <array>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>


boost::mt19937 gen;

using namespace std;

//constexpr int PUSH = -100;
//const int STAND = 1000;
//const int HIT   = 2000;

inline void error(const string& s)
{
    throw runtime_error(s);
}

enum class gameResult
{
    IN_PROGRESS,
    WIN,
    LOSE,
    PUSH
};

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

std::ostream& operator<<(ostream& os, const Ranks& r)
{
    switch (r)
    {
        case Ranks::Two:    os << "2";  break;
        case Ranks::Three:  os << "3";  break;
        case Ranks::Four:   os << "4";  break;
        case Ranks::Five:   os << "5";  break;
        case Ranks::Six:    os << "6";  break;
        case Ranks::Seven:  os << "7";  break;
        case Ranks::Eight:  os << "8";  break;
        case Ranks::Nine:   os << "9";  break;
        case Ranks::Ten:    os << "10"; break;
        case Ranks::Jack:   os << "J";  break;
        case Ranks::Queen:  os << "Q";  break;
        case Ranks::King:   os << "K";  break;
        case Ranks::Ace:    os << "A";  break;
        default:
            error("Unable to process Rank of card");
    }
    return os;
}

std::ostream& operator<<(ostream& os, const Suits& s)
{
    switch (s)
    {
        case Suits::spades:     os << "S"; break;
        case Suits::clubs:      os << "C"; break;
        case Suits::diamonds:   os << "D"; break;
        case Suits::hearts:     os << "H"; break;
        default:
            error("Unable to process Suit of card");
    }
    return os;
}

void printCard(const Card& card)
{
    std::cout << card.rank << card.suit << std::endl;
}

void printDeck(const std::array<Card, 52>& deck)
{
    for (const auto& elem : deck)
    {
        std::cout << elem.rank << elem.suit << std::endl;
    }
}

std::array<Card, 52> filldeck()
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

// Don't really want to swap actual card interal values
void swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

// random number function
int randomMersenne()
{
    boost::uniform_int<> dist(0, 51);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen, dist);
    
    return die();
}


// A deck is typedef std::array<Card,52>
void shuffleDeck(std::array<Card,52>& d)
{
    for (int i = 0; i < d.size(); ++i)
    {
        swap (d[i], d[randomMersenne()]);
        d[i].shuffeled = true;
    }
}

int getCardValue(const Card& card)
{
    switch (card.rank)
    {
        case Ranks::Two:        return 2; break;
        case Ranks::Three:      return 3; break;
        case Ranks::Four:       return 4; break;
        case Ranks::Five:       return 5; break;
        case Ranks::Six:        return 6; break;
        case Ranks::Seven:      return 7; break;
        case Ranks::Eight:      return 8; break;
        case Ranks::Nine:       return 9; break;
            
        case Ranks::Ten:
        case Ranks::Jack:
        case Ranks::Queen:
        case Ranks::King:
            return 10; break;
        case Ranks::Ace:        return 11; break;
    }
    error("Not able to get card Rank");
    return -1;
}

char hitOrStand()
{
    // players stuff
    std::cout << "Hit or Stand? (type h, or s, then press enter):\n";
    char choice;
    do
    {
        cin >> choice;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 'h' && choice != 's');
    
    return choice;
}

void printWinner(const gameResult& result)
{
    switch (result)
    {
        case gameResult::WIN:   std::cout << "PLAYER WINS!"       << std::endl; break;
        case gameResult::LOSE:  std::cout << "DEALER WINS!"       << std::endl; break;
        case gameResult::PUSH:  std::cout << "PUSH - SAME SCORE"  << std::endl; break;
        default: error("invalid game result");          break;
    }
}

void printDealersScore(const int& dealersScore)
{
    std::cout << "Dealers Score: " << dealersScore << std::endl;
}

void printPlayersScore(const int& playersScore)
{
    std::cout << "Players Score: " << playersScore << std::endl;
}

gameResult playblackjack(std::array<Card,52> deck)
{
    if (deck.at(0).shuffeled == false)
        shuffleDeck(deck);
    
    Card* cardptr = &deck.at(0);
    
    int players_total_so_far = 0;
    int dealers_total_so_far = 0;
    
    // Give the dealer one card
    dealers_total_so_far += getCardValue(*cardptr++);
    
    // Give the player two cards.
    players_total_so_far += getCardValue(*cardptr++);
    players_total_so_far += getCardValue(*cardptr++);
    
    // Player goes First, Hit or Stand?
    bool playersTurn = true;
    while (playersTurn == true)
    {
        printPlayersScore(players_total_so_far);
        
        char choice = hitOrStand();
        
        // If stand turn over, if hit card++ and add value of that card to total score
        if (choice == 's')
        {
            std::cout << "Player Stands " << std::endl;
            playersTurn = false;
        }
        
        else if (choice == 'h')
        {
            std::cout << "Player Hits: " << std::endl;
            players_total_so_far += getCardValue(*cardptr++);
            if (players_total_so_far > 21)
            {
                // if total_score > 21 bust, lose right away
                return gameResult::LOSE;
            }
        }
    }
    // ace == 11 for now
    // dealer goes after player
    // dealer draws until they reach a score of 17 or more, at which point they stand.
    bool dealersTurn = true;
    while (dealersTurn == true)
    {
        printDealersScore(dealers_total_so_far);
        
        if (dealers_total_so_far < 17)
        {
            std::cout << "Dealer Hits: " << std::endl;
            dealers_total_so_far += getCardValue(*cardptr++);
        }
        else if (dealers_total_so_far > 21)
        {
            return gameResult::WIN;
        }
        else
            
            dealersTurn = false;
    }
    
    // backup checking for 17-21 cases.
    if (players_total_so_far == dealers_total_so_far)
        return gameResult::PUSH;
    else if (players_total_so_far > dealers_total_so_far)
        return gameResult::WIN;
    else
        return gameResult::LOSE;
}

// Keeping a pointer to the next in the deck to be dealt out is nice.
// Whenever we need to deal a card, we get the value of the current card, and then
// advance the pointer to the next card. This can be done in one operation.
// getCardValue(*cardptr++);

// This returns the current card's value
// (which can then be added to the player or dealers total)
// and then advances cardptr to the next card

// should have used, typedef std::array<Card,52> Deck;
int main()
{
    gen.seed(static_cast<unsigned int>(std::time(0)));
    
    std::array<Card, 52> deck;
    deck = filldeck();
    
    shuffleDeck(deck);
    printDeck(deck);
    
    gameResult result = gameResult::IN_PROGRESS;
    result = playblackjack(deck);
    
    printWinner(result);
    
    return 0;
}












