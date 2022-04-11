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

#include "config.h"
#include "catDatabase.h"

class Cat {
protected:
    char                name[MAX_NAME];
    enum    Gender      gender;
    enum    Breed       breed;
    bool                isCatFixed;
    Weight              weight;

public:
    Cat*                next;

    Cat();

    Cat (   const   char    *newName,
            const   Gender  newGender,
            const   Breed   newBreed,
            const   Weight  weight
            );

    virtual ~Cat();

    ///////////Getters////////////
    const char *getName() const;
    Gender getGender() const;
    Breed getBreed() const;
    bool isFixed() const;
    Weight getWeight() const;
    void fixCat();

    /////////////Setters///////////
    void setName( const char *newName);
    void setWeight(Weight weight);

protected:
public:
    ///////////Setters//////////////
    void setGender(Gender gender);
    void setBreed(Breed breed);

    static bool isNameValid( const char* newName );
    static bool isWeightValid( const Weight newWeight );
    static bool isGenderValid( const Gender newGender );
    static bool isBreedValid( const Breed newBreed );

    bool print() const;
    bool validate() const;

private:
    void zeros();


};



