///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "addCats.h"
#include "catDatabase.h"

#include "config.h"

using namespace std;

bool addCat (Cat* newCat) {

    assert(newCat != nullptr);

    if ((newCat->validate()) == false) {
        cerr << PROGRAM_NAME << ": Bad Cat in addCats" << endl;
    }

    assert(validateDB());

    newCat->next = catDBHeadPtr;
    catDBHeadPtr = newCat;

    cout << "Successfully added Cat" << endl;

    numberOfCats++;
    return true;
}