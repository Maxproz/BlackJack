//
//  RandomGenerators.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "RandomGenerators.hpp"

// BLACKJACK
int randomMersenne()
{
    boost::uniform_int<> dist(0, 51);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > getcard(gen, dist);
    
    return getcard();
}

