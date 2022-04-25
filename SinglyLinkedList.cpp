///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "SinglyLinkedList.h"
#include "config.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() {}


void SinglyLinkedList::push_front(Node* newNode) {
    if (newNode == nullptr) {
        throw invalid_argument("newNode cannot be nullptr");
    }
    if (head != nullptr) {
        newNode -> next = head;
        head = newNode;
    } else {
        newNode -> next = nullptr;
        head = newNode;
    }
    count++;
    SinglyLinkedList::validate();
}


Node* SinglyLinkedList::pop_front() noexcept {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head -> next;
    count--;

    SinglyLinkedList::validate();

    return temp;
}


bool SinglyLinkedList::validate() const noexcept {

    if( !List::validate() ){
        return false;
    }

    unsigned int forwardCount = 0;
    Node* currentNode = head;

    while( currentNode != nullptr ){
        forwardCount++;
        currentNode = currentNode -> next;
    }

    return true;
}


void SinglyLinkedList::insert_after(Node* currentNode, Node* newNode) {
    if(List::empty()){
        throw std::logic_error("List is empty");
    }
    if (currentNode == nullptr) {
        throw std::invalid_argument( "Cannot insert newNode after nullptr");
    }

    if (newNode == nullptr) {
        throw std::invalid_argument( "newNode cannot be nullptr");
    }
    // checking if the nodes are in the list
    if(!isIn(currentNode)){
        throw std::logic_error( "currentNode not in the list");
    }
    if(isIn(newNode)){
        throw std::logic_error( "newNode is already in the list");
    }
    //validate new node
    if(!newNode->validate()){
        throw std::domain_error("newNode is not valid");
    }

    newNode -> next = currentNode -> next;
    currentNode -> next = newNode;

    count++;

    SinglyLinkedList::validate();
}


void SinglyLinkedList::dump() const noexcept{
    Node* currentNode = head;
    while (currentNode != nullptr){
        currentNode->dump();
        currentNode = currentNode -> next;
    }
}