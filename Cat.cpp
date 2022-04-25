///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>

#include "Cat.h"

//////namespace///////
using namespace std;

const string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;


/////////////Getters/////////////////
string Cat::getName() const noexcept {    ////Name
    return name;
}

bool Cat::isCatFixed() const noexcept{              ////Fixed
    return isFixed;
}

//////////////////////////Setters///////////////////////////
void Cat::setName(const string& newName) {
    if( isNameValid( newName )) {
        throw invalid_argument( "Cats should have a good name" );
    }
    name = newName;
}

void Cat::fixCat() noexcept {
    Cat::isFixed = true;
}

////////////////////Validation/////////////////////////
bool Cat::isNameValid( const string& newName ) {
    if( newName.empty() ) {
        cerr << PROGRAM_NAME << ": Name must not be nothing" << endl;
        return false;
    }
    return true;
}



/////////////////Validate////////////
bool Cat::validate() const noexcept {
    if (isNameValid( name ) == false) {
        return false;
    }
    return true;
}

/////////////////Print/////////////////
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

void Cat::dump() const noexcept{

    Mammal::dump();

    FORMAT_LINE_FOR_DUMP( "Cat", "name" ) << getName() << endl;
    FORMAT_LINE_FOR_DUMP( "Cat", "isFixed") << isCatFixed() << endl;
}



