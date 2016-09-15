//
//  RandomGenerators.hpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef RandomGenerators_hpp
#define RandomGenerators_hpp

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>



// BLACKJACK
// random number function for shuffling blackjack deck
extern boost::mt19937 gen;
int randomMersenne();

// POKER

#endif /* RandomGenerators_hpp */
