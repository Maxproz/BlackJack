//
//  Card.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Card.hpp"



std::ostream& operator<<(std::ostream& os, const Ranks& r)
{
    using namespace std;
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

std::ostream& operator<<(std::ostream& os, const Suits& s)
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

void swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}


