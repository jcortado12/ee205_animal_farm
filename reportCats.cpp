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

#include <string.h>
#include <cassert>
#include <iostream>

#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"

#include "config.h"

using namespace std;

bool printAllCats() {

    assert( validateDB() );

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

    cerr << PROGRAM_NAME << "Unable to find cat. Cat not in the database. Check spelling" << endl;
}


