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
    Cat*                next;

    Cat();

    Cat (   const   char    *newName,
            const   Gender  newGender,
            const   Breed   newBreed,
            const   Weight  newWeight
            );

    virtual ~Cat();

    ///////////Getters////////////
    const char *getName() const noexcept;
    Gender getGender() const noexcept;
    Breed getBreed() const noexcept;
    bool isCatFixed() const noexcept;
    float getWeight() const noexcept;
    void fixCat() noexcept;

    /////////////Setters///////////
    void setName( const char *newName);
    void setWeight( Weight weight );

protected:
public:
    ///////////Setters//////////////
    void setGender(Gender gender);
    void setBreed(Breed breed);

public:
    //////////////Validation//////////////////
    static bool isNameValid( const char* newName );
    static bool isWeightValid( const Weight newWeight );
    static bool isGenderValid( const Gender newGender );
    static bool isBreedValid( const Breed newBreed );

    bool print() const noexcept;
    bool validate() const noexcept;
};



