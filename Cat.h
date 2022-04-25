///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "config.h"
#include "Mammal.h"

class Cat : public Mammal {
public:
    static const std::string SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;

protected:
    std::string name;
    bool isFixed;

public:
    Cat* next;

public:
    explicit Cat( const std::string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
        if ( !isNameValid( newName )) {
            throw std::out_of_range( "Cats must have a name");
        }

        name = newName;
        isFixed = false;
    }

    Cat (   const   std::string&        newName,
            const   Color               newColor,
            const   bool                newIsFixed,
            const   Gender              newGender,
            const   Weight::t_weight    newWeight
            ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME )
    {
        if( !isNameValid( newName ) ) {
            throw std::out_of_range( "Cats must have a name");
        }
        name = newName;
        isFixed = newIsFixed;
    }

    ///////////Getters////////////
    std::string getName() const noexcept;
    bool isCatFixed() const noexcept;
    void fixCat() noexcept;

    /////////////Setters///////////
    void setName( const std::string& newName);


public:
    //////////////Validation//////////////////
    static bool isNameValid( const std::string& newName );

    void dump() const noexcept override;
    bool validate() const noexcept override;

    std::string speak() const noexcept override;
};



