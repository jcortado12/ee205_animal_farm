///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "catDatabase.h"
#include "deleteCats.h"

#include "config.h"

void deleteAllCats () {

    memset(&cat, 0, sizeof(struct Cats));

    numberOfCats = 0;

    printf("\nDeleted all cats. Database is empty.\n\n");

}
