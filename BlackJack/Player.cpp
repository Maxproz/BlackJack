//
//  Player.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

void moneyForChips(Player& player, int amount)
{
    std::cout << "Player is requesting chips.";
    player.setMoney(player.currentMoney()-amount);
    player.setChips(player.currentChips()+amount);
}

void displayPlayerChipCount(const Player& p)
{
    std::cout << "You have " << p.currentChips() << " chips.\n";
}

void displayPlayerMoneyCount(const Player& p)
{
    std::cout << "You have " << p.currentMoney() << " dollars.\n";
}