///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <exception>
#include <iostream>

#include "Cat.h"
#include "SinglyLinkedList.h"

#include "config.h"

using namespace std;

int main() {
    cout << "Starting Animal Farm 3" << endl;

    SinglyLinkedList catDB ;

    catDB.push_front( new Cat( "Loki", Color::CREAM, true, Gender::MALE, 1.0 ) ) ;
    catDB.push_front( new Cat( "Milo", Color::BLACK, true, Gender::MALE, 1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::BROWN, true, Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali", Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin", Color::WHITE, true, Gender::FEMALE, 1.4 ) ) ;

    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::GINGER, true, Gender::MALE, 1.5 ) );

    for( Animal* pAnimal = (Animal*)catDB.get_first();
         pAnimal != nullptr ;
         pAnimal = (Animal*)List::get_next( (Node*)pAnimal ) ) {
        cout << pAnimal->speak() << endl;
    }

    catDB.validate() ;
    catDB.dump() ;

    catDB.deleteAllNodes() ;
    catDB.dump() ;

    cout << "Done with Animal Farm 3" << endl;

    return( EXIT_SUCCESS ) ;
}