//
//  MPErrors.cpp
//  BlackJack
//
//  Created by max dietz on 9/15/16.
//  Copyright © 2016 PGD. All rights reserved.
//


#include "MPErrors.hpp"
#include <stdexcept>

void error(const std::string& s)
{
    throw std::runtime_error(s);
}