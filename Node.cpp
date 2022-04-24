///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "config.h"
#include "Node.h"

void Node::dump() const {
    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl;
    FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl;

}

bool Node::compareByAddress(const Node *node1, const Node *node2) {
    if ( node1 > node2 ) {
        return true;
    }
    return false;
}

bool Node::operator>(const Node &rightSide) {
    return Node::compareByAddress( this, &(Node&)rightSide);
}

bool Node::validate() const noexcept {
    if( next == nullptr ) {
        return true;
    }
    if( next == next->next ) {
        std::cout << PROGRAM_NAME << "Recursion error. Next is pointing to itself. No bueno" << std::endl;
        return false;
    }

    return true;
}