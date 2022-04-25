///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "List.h"

class SinglyLinkedList : public List{
public:
    SinglyLinkedList();

    void push_front(Node *newNode);

    Node *pop_front() noexcept override;

    void insert_after(Node *currentNode, Node *newNode);

    void dump() const noexcept override;

    bool validate() const noexcept override;
};

