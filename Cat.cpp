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
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "Cat.h"
#include "reportCats.h"

//////namespace///////
using namespace std;

void Cat::zeros() {
    memset ( name, 0, MAX_NAME );
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
}

Cat::Cat() {
    zeros();
}

Cat::Cat(   const   char    *newName,
            const   Gender  newGender,
            const   Breed   newBreed,
            const   Weight  newWeight) : Cat() {
    setName( newName );
    setGender( newGender );
    setBreed( newBreed );
    setWeight( newWeight );
}

Cat::~Cat() {
    zeros();
}

/////////////Getters/////////////////
const char *Cat::getName() const noexcept {    ////Name
    return name;
}

Gender Cat::getGender() const noexcept {        ////Gender
    return gender;
}

Breed Cat::getBreed() const noexcept {           ////Breed
    return breed;
}

bool Cat::isCatFixed() const noexcept{              ////Fixed
    return isFixed;
}

Weight Cat::getWeight() const noexcept {        ////Weight
    return weight;
}

//////////////////////////Setters///////////////////////////
void Cat::setName(const char *newName) {        ////Name
    isNameValid( newName );
    memset(name, 0, MAX_NAME);
    strcpy(name, newName);
}
void Cat::setGender(Gender newGender) {         ////Gender
    if ( gender != UNKNOWN_GENDER ) {
        cerr << PROGRAM_NAME << ": Gender can not be changed" << endl;
    }
    isGenderValid( newGender );
    Cat::gender = newGender;
}
void Cat::setBreed(Breed newBreed) {        ////Breed
    if( breed != UNKNOWN_BREED ) {
        cerr << PROGRAM_NAME << ": Breed can not be changed" << endl;
    }
    isBreedValid( newBreed );
    Cat::breed = newBreed;
}
void Cat::fixCat() noexcept {
    Cat::isFixed = true;
}
void Cat::setWeight(Weight newWeight) {
    isWeightValid( newWeight );
    Cat::weight = newWeight;
}

////////////////////Validation/////////////////////////
bool Cat::isNameValid( const char *newName ) {
    if( newName == nullptr ) {
        cerr << PROGRAM_NAME << ": Name must not be NULL" << endl;
        return false;
    }
    if( strlen(newName) <= 0 ) {
        cerr << PROGRAM_NAME << ": Name must be > 0 " << endl;
        return false;
    }
    if( strlen(newName) >= MAX_NAME ) {
        cerr << PROGRAM_NAME << ": name must be less than " << MAX_CATS << endl;
        return false;
    }
    return true;
}

bool Cat::isWeightValid( const Weight newWeight ) {
    if( newWeight <= 0 ) {
        cerr << PROGRAM_NAME << ": Weight must be > 0 " << endl;
        return false;
    }
    return true;
}

bool Cat::isBreedValid(const Breed newBreed) {
    if( newBreed == UNKNOWN_BREED ){
        cerr << PROGRAM_NAME << ": Breed must be known " << endl;
        return false;
    }
    return true;
}

bool Cat::isGenderValid(const Gender newGender) {
    if ( newGender == UNKNOWN_GENDER ){
        cerr << PROGRAM_NAME << ": Gender must be known " << endl;
        return false;
    }
    return true;
}



/////////////////Validate////////////
bool Cat::validate() const noexcept {
    if (isNameValid( name ) == false) {
        return false;
    }
    if (isGenderValid( gender ) == false){
        return false;
    }
    if (isBreedValid( breed ) == false) {
        return false;
    }
    if (isWeightValid( weight ) == false) {
        return false;
    }
    return true;
}

/////////////////Print/////////////////
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

bool Cat::print() const noexcept{
    assert( validate() ) ;

    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )         << getName()   << endl ;
    FORMAT_LINE( "Cat", "gender" )       << sGender( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" )        << sBreed( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isFixed" )      << isCatFixed()   << endl ;
    FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;

    return true ;
}



