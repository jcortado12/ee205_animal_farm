///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>

#include "catDatabase.h"
#include "Cat.h"
#include "config.h"
#include "reportCats.h"

using namespace std;
int numberOfCats = 0;



Cat* catDBHeadPtr = nullptr;

void initializeDB(){
    if( catDBHeadPtr != nullptr ) {
        fprintf(stderr, "Delete old database first", PROGRAM_NAME);
    }
}

bool validateDB() {
    int validCats = 0;

    for(Cat* index = catDBHeadPtr ; index != nullptr ; index = index->next ) {
        if( !index->validate() ) {
            return false ;
        }

        Cat* foundCat = findCatByName( index->getName() ) ;
        if( foundCat != index ) {
            fprintf(stderr, "%s: Warning:  Duplicate names are prohibited\n", PROGRAM_NAME) ;
        }

        validCats++ ;
    }
    if( validCats != numberOfCats ) {
        cout << PROGRAM_NAME << ": Error:  numberOfCats [" << numberOfCats
             << "] does not equal [" << validCats << "]" << endl ;
        return false ;
    }
    return true ;
}

bool isCatInDatabase( const Cat* aCat ) {
    assert( aCat != nullptr ) ;

    assert( validateDB() ) ;

    for(Cat* index = catDBHeadPtr ; index != nullptr ; index = index->next ) {
        if( index == aCat ) {
            return true ;
        }
    }

    assert( validateDB() ) ;

    return false ;
}
