///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10b_typedef - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "catDatabase.h"


extern bool updateCatName ( const NumCats index, const char newName[] );

extern bool fixCat ( const NumCats index );

extern bool updateCatWeight ( const NumCats index, const Weight newWeight);

extern bool updateCatCollar1 ( const NumCats index, enum Color newCollarColor1 );

extern bool updateCatCollar2 ( const NumCats index, enum Color newCollarColor2 );

extern bool updateLicense ( const NumCats index, const unsigned long long newLicense );
