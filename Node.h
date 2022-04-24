///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include "config.h"

class Node {

    friend class List;
    friend class SinglyLinkedList;

public:
    virtual void print() const;

    virtual bool validate() const noexcept;

    virtual bool operator> ( const Node &rightSide );

protected:
    static bool compareByAddress ( const Node *node1, const Node *node2 );

    Node* next = nullptr;
};
