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

#include "config.h"


NumCats numberOfCats = 0;

/////////////////////////////Structure/////////////////////////////////////
struct Cats cat[ MAX_CATS ] = {};

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

const char* sColor ( const enum Color color ) {
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
}

///////////////////////////Validation functions//////////////////////////////
bool isWeightValid ( const Weight weight ) {
    if ( weight <= 0 ){
        fprintf( stderr, "%s: Cats need to have a weight. \n", PROGRAM_NAME);
        return false;
    }
    return true;
}

bool isNameValid ( const char name[ MAX_NAME ] ){
    if ( strlen( name ) <= 0 ) {
        fprintf( stderr, "%s: Cats need to have a name. \n", PROGRAM_NAME);
        return false;
    }

    if ( strlen( name ) >= MAX_NAME ) {
        fprintf( stderr, "%s: Cats name cannot exceed %d characters. \n", PROGRAM_NAME, MAX_CATS);
        return false;
    }

    for ( NumCats i = 0 ; i <= MAX_CATS ; i++ ) {
        if ( strcmp( cat[i].name, name ) == 0 ) {
            fprintf( stderr, "%s: Name of each cat must be unique. \n", PROGRAM_NAME);
            return false;
        }
    }

    return true;
}

bool isIndexValid ( const NumCats index ) {
    if ( index >= numberOfCats ) {
        fprintf( stderr, "%s: Cat index must not exceed %d. \n", PROGRAM_NAME, numberOfCats );
        return false;
    }
    return true;
}
