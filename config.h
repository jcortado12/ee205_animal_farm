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

#include <iomanip>

#define PROGRAM_NAME ("Animal Farm 3")

#define MAX_NAME (50)
#define MAX_CATS (1024)

#define FORMAT_LINE_FOR_DUMP( className, member ) \
    std::cout << std::setfill( ' ' )  /* Space pad    */  \
              << std::left            /* Left justify */  \
              << std::boolalpha  /* Print `true` or `false` for `bool`s */ \
              << std::setw( 8) << (className)             \
              << std::setw(20) << (member)                \
              << std::setw(52)  /* (data) */

#define PRINT_HEADING_FOR_DUMP \
std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl


enum Gender { UNKNOWN_GENDER = 0, MALE, FEMALE };
enum Breed { UNKNOWN_BREED , MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };

//typedefs
//typedef float   Weight;
const float UNKNOWN_WEIGHT = (-1);

