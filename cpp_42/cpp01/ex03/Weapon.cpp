#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){
    // this->setType(type);
}

Weapon::~Weapon() {

}

const std::string& Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string newType) {
    this->type = newType;
}