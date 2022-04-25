///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>

#include "List.h"
#include "config.h"

using namespace std;

bool List::empty() const noexcept {
    if( head == nullptr ) {
        return true;
    }
    return false;
}


unsigned int List::size() const noexcept {
    return count;
}


bool List::isIn(Node* aNode) const {
    Node* currentNode = head;

    while ( currentNode != nullptr ) {
        if( aNode == currentNode ) {
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}


bool List::isSorted() const noexcept {
    if( count <=  1 ) {
        return true;
    }

    for( Node* i = head; i->next != nullptr; i = i->next ){
        if( *i > *i->next ) {
            return false;
        }
    }

    return true;
}


Node* List::get_first() const noexcept {
    return head;
}


Node* List::get_next(const Node *currentNode) {
    return currentNode->next;
}


void List::deleteAllNodes() noexcept {

    while( head != nullptr ){
        pop_front();
    }

    cout << "All nodes successfully deleted" << endl;
}


bool List::validate() const noexcept {
    if (head == nullptr) {
        assert(size() == 0);
    } else {
        assert(size() != 0);
    }

    return true;
}
