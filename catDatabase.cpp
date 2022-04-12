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

Cat* catDBHeadPtr = nullptr;        ////Head pointer

void initializeDB(){
    if( catDBHeadPtr != nullptr ) {
        cerr << PROGRAM_NAME << ": Delete old database " << endl;
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
        cerr << PROGRAM_NAME << ": Error:  numberOfCats [" << numberOfCats
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

////////////////////////////enum to string/////////////////////////////////
const char* sGender ( const enum Gender gender ) {
    switch ( gender ) {
        case 0:
            return "Unknown Gender";
            break;

        case 1:
            return "Male";
            break;

        case 2:
            return "Female";
            break;
    }
    return "null";
}

const char* sBreed ( const enum Breed breed ) {
    switch ( breed ) {
        case 0:
            return "Unknown Breed";
            break;

        case 1:
            return "Maine Coon";
            break;

        case 2:
            return "Manx";
            break;

        case 3:
            return "Shorthair";
            break;

        case 4:
            return "Persian";
            break;

        case 5:
            return "Sphynx";
            break;
    }
    return "null";
}
