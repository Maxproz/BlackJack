//
//  UltTexasHoldem.hpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef UltTexasHoldem_hpp
#define UltTexasHoldem_hpp
#include "Player.hpp"
#include <iostream>
#include "Deck.hpp"
#include <memory>


std::pair<int, int> getBlindsAndAntes(Player& p);
void playUltimateTexasHoldem(Player& p);


#endif /* UltTexasHoldem_hpp */
