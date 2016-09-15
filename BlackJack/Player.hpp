//
//  Player.hpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

class Player
{
private:
    // Lets say the player starts with 1000$ for now, maybe change later
    int _money {1000};
    int _chips;
public:
    Player() : _money{1000}, _chips{0} {}
    // creating a player by giving chips
    Player(int money_deposit) : _chips{money_deposit}
    {
        _money -= money_deposit;
    }
    
    int currentMoney() const { return _money; };
    int currentChips () const { return _chips; };
    
    inline void bet(int chip_amount) { _chips -= chip_amount; }
    
    void setMoney(const int money) { _money = money; }
    void setChips(const int chips) { _chips = chips; }
};

void moneyForChips(Player& player, int amount);
void displayPlayerChipCount(const Player& p);
void displayPlayerMoneyCount(const Player& p);


#endif /* Player_hpp */
