///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME (50)
#define MAX_CATS (1024)

//typedefs
typedef float   Weight;
//typedef int     NumCats;

extern int numberOfCats;


enum Gender { UNKNOWN_GENDER = 0, MALE, FEMALE };

enum Breed { UNKNOWN_BREED , MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };

enum Color { BLACK, WHITE, RED, BLUE, GREEN, PINK };


struct Cats {
    char                 name[ MAX_NAME ];
    enum Gender          gender;
    enum Breed           breed;
    bool                 isFixed;
    Weight                weight;
    enum Color           collarColor1;
    enum Color           collarColor2;
    unsigned long long   license;
};


extern struct Cats cat[];

extern const char* sGender ( const enum Gender gender );
extern const char* sBreed ( const enum Breed breed );
extern const char* sColor ( const enum Color color );

extern bool isWeightValid ( const Weight weight );
extern bool isNameValid ( const char name[ MAX_NAME ] );
extern bool isIndexValid ( const int index );
