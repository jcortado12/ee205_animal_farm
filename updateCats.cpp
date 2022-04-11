///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "catDatabase.h"
#include "updateCats.h"

#include "config.h"

bool updateCatName ( const int index, const char newName[] ) {

/*    if ( isIndexValid(index) == false) {
        return false;
    }

    if ( isNameValid(newName) == false) {
        return false;
    }*/


    strcpy( cat[index].name, newName );

    printf("\nCat name has been changed to %s. \n", newName);
    return true;
}


bool fixCat( const int index ) {

/*    if ( isIndexValid(index) == false ) {
        return false;
    }*/


    cat[index].isFixed = true;
    return true;
}


bool updateCatWeight ( const int index, const Weight newWeight) {

/*    if ( isIndexValid(index) == false ) {
        return false;
    }

    if ( isWeightValid(newWeight) == false ) {
        return false;
    }*/


    cat[index].weight = newWeight;
    return true;
}


bool updateCatCollar1 ( const int index, enum Color newCollarColor1 ) {

/*    if ( isIndexValid(index) == false ) {
        return false;
    }*/

    cat[index].collarColor1 = newCollarColor1;
    return true;
}


bool updateCatCollar2 ( const int index, enum Color newCollarColor2 ) {

/*    if ( isIndexValid(index) == false ) {
        return false;
    }*/

    cat[index].collarColor2 = newCollarColor2;
    return true;
}


bool updateLicense ( const int index, const unsigned long long newLicense ) {

/*    if ( isIndexValid(index) == false ) {
        return false;
    }*/

    cat[index].license = newLicense;
    return true;
}