///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "Cat.h"

#include "config.h"

#define MAX_NAME1 "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2 "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

#define DEBUG

int main ( ) {

    printf("\nStarting Animal Farm 2\n\n");


   /* addCat( "Loki",   MALE,             PERSIAN,    true,     8.5,    BLACK,   WHITE,   101 );
    addCat( "Milo",   MALE,             MANX,       true,     7.0,    BLACK,   RED,     102 );
    addCat( "Bella",  FEMALE,           MAINE_COON, true,    18.2,    BLACK,   BLUE,    103 );
    addCat( "Kali",   FEMALE,           SHORTHAIR,  false,    9.2,    BLACK,   GREEN,   104 );
    addCat( "Trin",   FEMALE,           MANX,       true,    12.2,    BLACK,   PINK,    105 );
    addCat( "Chili",  UNKNOWN_GENDER,   SHORTHAIR,  true,    7.0,     WHITE,   BLACK,   106 );*/


   {
       Cat testCat = Cat();
       assert(testCat.getName() != nullptr );
       assert(strcmp(testCat.getName(), "") == 0);
       assert(testCat.getGender() == UNKNOWN_GENDER);
       assert(testCat.getBreed() == UNKNOWN_BREED);
       assert(testCat.isFixed() == false);
       assert(testCat.getWeight() == UNKNOWN_WEIGHT);
       assert(!testCat.isFixed());
       assert(!testCat.validate());

       //assert(testCat.setName(nullptr) == false);

    };


    printf("Done with Animal Farm 2\n\n");

    return EXIT_SUCCESS;
}
