///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <string>

#include "Mammal.h"
#include "config.h"

using namespace std;

const string Mammal::MAMMAL_NAME = "Mammilian";

void Mammal::dump() const noexcept {

    Animal::dump();

    FORMAT_LINE_FOR_DUMP("Mammal", "color") << color << endl;
}
