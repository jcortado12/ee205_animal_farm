///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
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
#include "deleteCats.h"
#include "Cat.h"

#include "config.h"

bool deleteCat(Cat* byeCat){
    if( byeCat == catDBHeadPtr ) {
        catDBHeadPtr = catDBHeadPtr->next;
        delete byeCat;
        numberOfCats--;

        return true;
    }

    Cat* index = catDBHeadPtr;
    while (index != nullptr ) {
        if( index->next == byeCat ) {
            index->next = byeCat->next ;
            delete byeCat ;
            numberOfCats--;

            assert( validateDB() ) ;

            return true ;
        }
        index = index->next ;
    }
}

bool deleteAllCats () {
    while( catDBHeadPtr != nullptr ) {
        deleteCat( catDBHeadPtr );
    }
    return true;
}
