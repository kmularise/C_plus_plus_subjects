#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("animal") {
  std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type) {
  std::cout << "WrongAnimal Copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
  if (&obj != this) {
    this->type = obj.type;
  }
  return *this;
}
void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal Sound!" << std::endl;
}
const std::string& WrongAnimal::getType() const { return this->type; };