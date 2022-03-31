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

#include "catDatabase.h"
#include "reportCats.h"

#include "config.h"

bool printCat ( const NumCats index ) {

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


bool printAllCats() {

    if ( numberOfCats == 0 ){
        fprintf( stderr, "%s: No cats in the database.\n\n", PROGRAM_NAME);
        return false;
    }

    for ( NumCats index = 0; index < numberOfCats; ++index){
        printCat( index );
    }

    return true;
}


int findCat( const char name[] ){

    for ( NumCats index = 0; index <= MAX_CATS; index++ ){
        if ( strcmp( cat[ index ].name, name ) == 0 ) {
            printf("\n[%s] is cat number [%d]\n", cat[ index ].name, index);
            return index;
        }
    }

    return false;
}
