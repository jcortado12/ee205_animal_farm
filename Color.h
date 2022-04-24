///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>

#include "config.h"

enum class Color {
    UNKNOWN_COLOR, BLACK, BROWN, WHITE, RED, BLUE, GREEN, GINGER, CREAM, CINNAMON, CALICO
};

inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ){
    switch( rhs_Color ) {
        case Color::UNKNOWN_COLOR:
            lhs_stream << "Unknown Color";
            break;
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::BROWN:
            lhs_stream << "Brown";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
        case Color::RED:
            lhs_stream << "Red";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREEN:
            lhs_stream << "Green";
            break;
        case Color::GINGER:
            lhs_stream << "Ginger";
            break;
        case Color::CINNAMON:
            lhs_stream << "Cinnamon";
            break;
        case Color::CREAM:
            lhs_stream << "Cream";
            break;
        case Color::CALICO:
            lhs_stream << "Calico";
            break;
        default:
            throw std::out_of_range("Color not mapped to a string");
    }
    return lhs_stream;
}
