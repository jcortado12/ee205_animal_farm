///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Jordan Cortado <jcortado@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdexcept>
#include <iostream>
#include <iomanip>

#include "config.h"
#include "Animal.h"
#include "Node.h"

using namespace std;

const string Animal::KINGDOM_NAME = "Animalia";

//////////Getters//////////////
string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

string Animal::getClassification() const noexcept {
    return classification;
}

string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight  Animal::getWeight() const noexcept {
    return weight.getWeight();
}

//////////setters/////////////
void Animal::setWeight( const Weight::t_weight newWeight ) {
    weight.setWeight( newWeight );
}

void Animal::setGender( const Gender newGender ) {
    if( gender != Gender::UNKNOWN_GENDER ) {
        throw logic_error( "Gender is set already" );
    }
}

/////Constructors//////////
Animal::Animal (const Weight::t_weight newMaxWeight,
                const std::string &newClassification,
                const std::string &newSpecies) : Node(), weight( Weight::POUND, newMaxWeight ) {

    classification = newClassification;
    species = newSpecies;
}

Animal::Animal (const Gender newGender,
                const Weight::t_weight newWeight,
                const Weight::t_weight newMaxWeight,
                const std::string &newClassification,
                const std::string &newSpecies) : Node(), weight( newWeight, newMaxWeight ){
    setGender(newGender);
    setWeight(newWeight);
    classification = newClassification;
    species = newSpecies;
}
//////////Validation//////////////
bool Animal::validateClassification( const std::string &checkClassification ) noexcept {
    if( checkClassification.compare("Mammalia") ){
        return true;
    }
    if( checkClassification.compare("Aves") ){
        return true;
    }
    if( checkClassification.compare("Reptilia") ){
        return true;
    }
    if( checkClassification.compare("Amphibia") ){
        return true;
    }
    if( checkClassification.compare("Osteichthyes") ){
        return true;
    }
    if( checkClassification.compare("Chrondrichtyes") ){
        return true;
    }
    if( checkClassification.compare("Agnatha") ){
        return true;
    }

    cout << checkClassification << ". Not a valid Animal Class" << endl;
    return false;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if( checkSpecies.compare("Cat") ) {
        return true;
    }
    if( checkSpecies.compare("Dog") ) {
        return true;
    }

    cout << checkSpecies << ". Not a valid species." << endl;
    return false;
}

bool Animal::validate() const noexcept {
    if( !validateClassification(getClassification()) ) {
        return false;
    }
    if( !validateClassification(getSpecies()) ) {
        return false;
    }
    if( KINGDOM_NAME.compare("Animalia") ) {
        cout << "Invalid Kingdom" << endl;
        return false;
    }
}

void Animal::dump() const noexcept {
    PRINT_HEADING_FOR_DUMP;

    Node::dump();

    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << getWeight() << endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl;

}