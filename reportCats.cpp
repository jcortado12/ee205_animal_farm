///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
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

#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"

#include "config.h"

/*
bool printCat ( const int index ) {

    if ( index < 0 || index >= MAX_CATS ) {
        fprintf( stderr, "%s: Bad cat [%d] \n", PROGRAM_NAME, index);
        return false;
    }
    printf( "\n--------------------\n" );
    printf( "cat index = [%d] \n",   index);
    printf( "name = [%s] \n",        cat[index].name);
    printf( "gender = [%s] \n",      sGender(cat[index].gender));
    printf( "breed = [%s] \n",       sBreed(cat[index].breed));
    printf( "isFixed = [%d] \n",     cat[index].isFixed);
    printf( "weight = [%f] \n",      cat[index].weight);

    printf( "collar color 1 = [%s] \n",    sColor(cat[index].collarColor1));
    printf( "collar color 2 = [%s] \n",    sColor(cat[index].collarColor2));
    printf( "license # = [%llu] \n",       cat[index].license);
    printf( "--------------------\n" );

    return true;
}
*/


bool printAllCats() {
    int numCats = 0;

    for(Cat* index = catDBHeadPtr ; index != nullptr ; index = index->next ) {
        index->print() ;
        numCats++ ;
    }
    return true;
}

Cat* findCatByName( const char* name ) {
    assert( Cat().isNameValid( name ) );

    for(Cat* index = catDBHeadPtr ; index != nullptr ; index = index->next ) {
        if(strcmp(name, index->getName() ) == 0 ) {
            return index ;
        }
    }
    return nullptr ;
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
