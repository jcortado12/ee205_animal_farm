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

//#ifndef EE205_LAB_10D_ANIMAL_FARM_2_CAT_H
//#define EE205_LAB_10D_ANIMAL_FARM_2_CAT_H
#include "catDatabase.h"

class Cat {
protected:
    char                name[MAX_NAME];
    enum    Gender      gender;
    enum    Breed       breed;
    bool                isFixed;
    Weight              weight;
};


//#endif //EE205_LAB_10D_ANIMAL_FARM_2_CAT_H
