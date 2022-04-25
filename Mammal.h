///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "Color.h"
//#include "Weight.h"
#include "Animal.h"

class Mammal : public Animal {

public:
    static const std::string MAMMAL_NAME;

protected:
    Color color = Color::UNKNOWN_COLOR;

public:
    Mammal( const Weight::t_weight newMaxWeight ,const std::string& newSpecies ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};

    Mammal( const Color            newColor
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies
    ) : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ) {
        setColor( newColor );
    };


    Color getColor() const noexcept { return color; }
    void setColor( const Color newColor ) noexcept { color = newColor; }


    void dump() const noexcept override;
};



