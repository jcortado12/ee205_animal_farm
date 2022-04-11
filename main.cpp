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

//#define DEBUG

/*int main ( ) {

    printf("\nStarting Animal Farm 1\n\n");


    *//*addCat( "Loki",   MALE,             PERSIAN,    true,     8.5,    BLACK,   WHITE,   101 );
    addCat( "Milo",   MALE,             MANX,       true,     7.0,    BLACK,   RED,     102 );
    addCat( "Bella",  FEMALE,           MAINE_COON, true,    18.2,    BLACK,   BLUE,    103 );
    addCat( "Kali",   FEMALE,           SHORTHAIR,  false,    9.2,    BLACK,   GREEN,   104 );
    addCat( "Trin",   FEMALE,           MANX,       true,    12.2,    BLACK,   PINK,    105 );
    addCat( "Chili",  UNKNOWN_GENDER,   SHORTHAIR,  true,    7.0,     WHITE,   BLACK,   106 );*//*

#ifdef DEBUG
    /////////////////////////////////addCat validation testing///////////////////////////////////////////
      assert( addCat( "",           MALE,    MANX,    true,    8.9,  BLACK,   BLACK,   107 ) == false ); // empty name
      assert( addCat( MAX_NAME1,    MALE,    MANX,    true,    8.9,  BLACK,   BLACK,   107 ) == true  ); // max name
      assert( addCat( ILLEGAL_NAME, MALE,    MANX,    true,    8.9,  BLACK,   BLACK,   107 ) == false ); // name too long
      assert( addCat( "Chili",      MALE,    MANX,    true,    8.9,  BLACK,   BLACK,   107 ) == false ); // non unique name
      assert( addCat( MAX_NAME1,    MALE,    MANX,    true,    0,    BLACK,   BLACK,   107 ) == false ); // weight <= 0


      //////////////////////////////reportCat validation testing////////////////////////////////////////////
      assert( printCat(-1)    == false );    // < 0 cats
      assert( printCat(1025)  == false );    // > MAX_CATS

      assert( findCat("Bella")   == 2 );     // has an index
      assert( findCat("Bella's not here") == false );    // does not have an index

      assert( printAllCats() == true );


      ///////////////////////////////updateCat validation testing///////////////////////////////////////////
      assert( updateCatName( findCat("Milo"), "" )             == false ); // update cat name to empty name
      assert( updateCatName( findCat("Milo"), MAX_NAME2 )      == true  ); // update to max name
      assert( updateCatName( findCat("Milo"), ILLEGAL_NAME )   == false ); // update cat name too long
      assert( updateCatName( findCat("Milo"), "Kali" )         == false ); // update name to an existing name

      assert( updateCatWeight( findCat("Milo"), -1 ) == false ); // update weight to <= 0

      assert( updateCatCollar1( findCat("Milo"), PINK )  == true );  // update cat collar 1 color
      assert( updateCatCollar2( findCat("Milo"), RED )   == true );  // update cat collar 2 color

      assert( updateLicense( findCat("Milo"), 100 ) == true ); // update cat license
#endif


    printAllCats();

    int kali = findCat ( "Kali" );
    printCat ( kali );

*//*    updateCatName ( kali, "Capulet" );
    updateCatWeight ( kali, 9.9 ) ;
    updateCatCollar1 ( kali, WHITE );
    updateCatCollar2 ( kali, BLACK );
    updateLicense ( kali, 99 );*//*

    fixCat ( kali );
    printCat ( kali );

    printAllCats();

    deleteAllCats();
    printAllCats();


    printf("Done with Animal Farm 1\n\n");

    return EXIT_SUCCESS;
}*/
