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

using namespace std;

const string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;


string Cat::getName() const noexcept {
    return name;
}
bool Cat::isCatFixed() const noexcept{
    return isFixed;
}


void Cat::setName(const string& newName) {
    if( isNameValid( newName )) {
        throw invalid_argument( "Cats should have a good name" );
    }
    name = newName;
}
void Cat::fixCat() noexcept {
    Cat::isFixed = true;
}


bool Cat::isNameValid( const string& newName ) {
    if( newName.empty() ) {
        cerr << PROGRAM_NAME << ": Name must not be nothing" << endl;
        return false;
    }
    return true;
}
bool Cat::validate() const noexcept {
    if (isNameValid( name ) == false) {
        return false;
    }
    return true;
}


void Cat::dump() const noexcept{
    Mammal::dump();

    FORMAT_LINE_FOR_DUMP( "Cat", "name" ) << getName() << endl;
    FORMAT_LINE_FOR_DUMP( "Cat", "isFixed") << isCatFixed() << endl;
}


std::string Cat::speak() const noexcept {
    return "Meow";
}

