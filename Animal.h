///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
//#include "Gender.h"


class Animal {

public:
    static const std::string KINGDOM_NAME;

private:
    std::string species;
    std::string classification;
    //Gender gender = Gender::UNKNOWN_GENDER;
    //Weight weight;

};

