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
#include <cassert>
#include <iostream>

#include "catDatabase.h"
#include "deleteCats.h"
#include "Cat.h"

#include "config.h"

using namespace std;

bool deleteCat(Cat* byeCat){
    assert( validateDB() );
    assert( byeCat != nullptr );

    if( byeCat == catDBHeadPtr ) {
        catDBHeadPtr = catDBHeadPtr->next;
        delete byeCat;
        numberOfCats--;

        assert( validateDB() );

        cout << "Cat successfully deleted" << endl;

        return true;
    }

    Cat* index = catDBHeadPtr;
    while (index != nullptr ) {
        if( index->next == byeCat ) {
            index->next = byeCat->next ;
            delete byeCat ;
            numberOfCats--;

            assert( validateDB() );

            cout << "Cat successfully deleted" << endl;

            return true;
        }
        index = index->next;
    }

    assert( validateDB() );

    cerr << PROGRAM_NAME << ": This Cat can not be deleted" << endl;
    return NULL;
}

bool deleteAllCats () {
    while( catDBHeadPtr != nullptr ) {
        deleteCat( catDBHeadPtr );
    }

    numberOfCats == 0;

    cout << "Database successfully deleted" << endl;

    return true;
}
