///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#define PROGRAM_NAME ("Animal Farm 2")

#define MAX_NAME (50)
#define MAX_CATS (1024)

enum Gender { UNKNOWN_GENDER = 0, MALE, FEMALE };
enum Breed { UNKNOWN_BREED , MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };

//typedefs
typedef float   Weight;
const Weight UNKNOWN_WEIGHT = (-1);

