///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10b_typedef - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "addCats.h"
#include "catDatabase.h"

#include "config.h"

bool addCat (
        const char name[],
        const enum Gender gender,
        const enum Breed breed,
        const bool isFixed,
        const Weight weight,
        const enum Color collarColor1,
        const enum Color collarColor2,
        const unsigned long long license
)
{

    if ( isNameValid(name) == false ) {
        return false;
    }
    if ( isWeightValid(weight) == false ){
        return false;
    }


    strcpy( cat[ numberOfCats ].name, name );


    cat[numberOfCats].gender    =  gender;
    cat[numberOfCats].breed     =  breed;
    cat[numberOfCats].isFixed   =  isFixed;
    cat[numberOfCats].weight    =  weight;

    cat[numberOfCats].collarColor1   =  collarColor1;
    cat[numberOfCats].collarColor2   =  collarColor2;
    cat[numberOfCats].license        =  license;


    numberOfCats++;
    return true;
}