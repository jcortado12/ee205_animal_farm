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
#include <exception>
#include <iostream>

#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "Cat.h"

#include "config.h"

#define MAX_NAME1 "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2 "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

//#define DEBUG

using namespace std;

int main ( ) {

    printf("\nStarting Animal Farm 2\n\n");

    initializeDB();

    #ifdef DEBUG
    {
        // Verify that a cat's default values are set
        Cat testCat = Cat();
        assert(testCat.getName() != nullptr );
        assert(strcmp(testCat.getName(), "") == 0);
        assert(testCat.getGender() == UNKNOWN_GENDER);
        assert(testCat.getBreed() == UNKNOWN_BREED);
        assert(testCat.isFixed() == false);
        assert(testCat.getWeight() == UNKNOWN_WEIGHT);
        assert(!testCat.isFixed());
        assert(!testCat.validate());  // The default cat is invalid

        // Test for NULL name
        try {
            testCat.setName(nullptr);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        // Test for empty name
        try {
            testCat.setName("");
            assert(false); // We should never get here
        } catch (exception const &e) {}

        // Test valid names
        testCat.setName("A");       // A 1 character name is valid
        testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

        // Test for name too large
        try {
            testCat.setName(ILLEGAL_NAME);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.setGender(FEMALE);

        try {
            testCat.setGender(MALE);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.setBreed(MAINE_COON);

        try {
            testCat.setBreed(MANX);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.fixCat();
        assert(testCat.isFixed());

        // Test for Weight <= 0
        try {
            testCat.setWeight(0);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.setWeight(1.0 / 1024);
        assert(testCat.getWeight() == 1.0 / 1024);

        assert(testCat.validate());  // The cat should now be valid
        testCat.print() ;

        assert(!isCatInDatabase(&testCat)) ;
    }
    #endif

    bool result ;
    result = addCat( new Cat( "Loki", MALE, PERSIAN, 1.0 )) ;
    assert( result ) ;
    if( !result ) throw logic_error ("addCat() failed") ;
    result = addCat( new Cat( "Milo", MALE, MANX , 1.1 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Trin", FEMALE, MANX, 1.4 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5 )) ;
    assert( result ) ;

    #ifdef DEBUG
    {
        // Test finding a cat...
        Cat *bella = findCatByName("Bella");
        assert(bella != nullptr);
        // Test not finding a cat
        assert(findCatByName("Bella's not here") == nullptr);

        // Test deleting a cat...
        assert(deleteCat(bella) == true);
        try {
            deleteCat(bella); // Verify that Bella's not there
        } catch (exception const &e) {}

        bella = nullptr;
    }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    printf ("Done with Animal Farm 2");

    return EXIT_SUCCESS  ;
}