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

#ifndef EE205_LAB_10D_ANIMAL_FARM_3_MAMMAL_H
#define EE205_LAB_10D_ANIMAL_FARM_3_MAMMAL_H

#include <string>
#include "Color.h"
#include "Weight.h"

class Mammal {

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



