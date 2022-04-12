///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "addCats.h"
#include "catDatabase.h"
//#include "config.h"

#include "config.h"

bool addCat (Cat* newCat) {
    newCat->validate();

    if(isCatInDatabase( newCat )) {
        fprintf(stderr, "%s: No duplicate cats, %s is already in the database\n", PROGRAM_NAME);
    }

    newCat->next = catDBHeadPtr;

    catDBHeadPtr = newCat;

    numberOfCats++;
    return true;
/*    if ( isNameValid(name) == false ) {
        return false;
    }
    if ( isWeightValid(weight) == false ){
        return false;
    }*/


/*    strcpy( cat[ numberOfCats ].name, name );

    cat[numberOfCats].gender    =  gender;
    cat[numberOfCats].breed     =  breed;
    cat[numberOfCats].isFixed   =  isFixed;
    cat[numberOfCats].weight    =  weight;

    cat[numberOfCats].collarColor1   =  collarColor1;
    cat[numberOfCats].collarColor2   =  collarColor2;
    cat[numberOfCats].license        =  license;*/



}