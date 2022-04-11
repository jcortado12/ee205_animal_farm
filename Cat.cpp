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

#include "config.h"
#include "Cat.h"
#include "catDatabase.h"

void Cat::zeros() {
    memset ( name, 0, MAX_NAME );
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isCatFixed = false;
    weight = UNKNOWN_WEIGHT;
}

Cat::Cat() {
    zeros();
}

Cat::Cat(   const   char    *newName,
            const   Gender  newGender,
            const   Breed   newBreed,
            const   Weight  newWeight) {
    setName( newName );
    setGender( newGender );
    setBreed( newBreed );
    setWeight( newWeight );
}

Cat::~Cat() {
    zeros();
}

/////////////Getters/////////////////
const char *Cat::getName() const {
    return name;
}

Gender Cat::getGender() const {
    return gender;
}

Breed Cat::getBreed() const {
    return breed;
}

bool Cat::isFixed() const {
    return isCatFixed;
}

Weight Cat::getWeight() const {
    return weight;
}

/////////Setters//////////////
void Cat::setWeight(Weight newWeight) {
    isWeightValid( newWeight );
    Cat::weight = weight;
}
void Cat::setGender(Gender newGender) {
    if ( gender != UNKNOWN_GENDER ) {
        fprintf(stderr, "%s: Gender must not be changed\n", PROGRAM_NAME);
    }
    isGenderValid( newGender );
    Cat::gender = gender;
}
void Cat::setBreed(Breed newBreed) {
    isBreedValid( newBreed );
    Cat::breed = breed;
}
void Cat::setName(const char *newName) {
    isNameValid( newName );
    memset(name, 0, MAX_NAME);
    strcpy(name, newName);
}
////////////////////Validation/////////////////////////
bool Cat::isNameValid( const char *newName ) {
    if( newName == NULL || newName == nullptr ) {
        fprintf(stderr, "%s: Name != NULL\n", PROGRAM_NAME);
        return false;
    }
    if( strlen(newName) <= 0 ) {
        fprintf(stderr, "%s: Name length must be greater than 0\n", PROGRAM_NAME);
        return false;
    }
    if( strlen(newName) >= MAX_NAME ) {
        fprintf(stderr, "%s: Name must not be greater than %d characters\n", PROGRAM_NAME);
        return false;
    }
    return true;
}

bool Cat::isWeightValid( const Weight newWeight ) {
    if( newWeight <= 0 ) {
        fprintf(stderr, "%s: Weight needs to have a weight\n", PROGRAM_NAME);
        return false;
    }
    return true;
}

bool Cat::isBreedValid(const Breed newBreed) {
    if( newBreed == UNKNOWN_BREED ){
        fprintf(stderr, "%s: Cat breed must be known\n", PROGRAM_NAME);
        return false;
    }
    return true;
}

bool Cat::isGenderValid(const Gender newGender) {
    if ( newGender == UNKNOWN_GENDER ){
        fprintf(stderr, "%s: Cat gender must be known\n", PROGRAM_NAME);
        return false;
    }
    return true;
}

