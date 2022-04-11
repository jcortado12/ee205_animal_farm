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

#include "catDatabase.h"
#include "Cat.h"
#include "config.h"

using namespace std;

int numberOfCats = 0;

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

/*const char* sColor ( const enum Color color ) {
    switch ( color ) {
        case 0:
            return "Black";
            break;

        case 1:
            return "White";
            break;

        case 2:
            return "Red";
            break;

        case 3:
            return "Blue";
            break;

        case 4:
            return "Green";
            break;

        case 5:
            return "Pink";
            break;
    }
    return "null";
}*/

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
            cout << PROGRAM_NAME ": Warning:  Duplicate names are prohibited [" << index->getName() << "]" << endl ;
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

    assert( validateDatabase() ) ;

    for(Cat* index = catDBHeadPtr ; index != nullptr ; index = index->next ) {
        if( index == aCat ) {
            return true ;
        }
    }

    assert( validateDatabase() ) ;

    return false ;
}
