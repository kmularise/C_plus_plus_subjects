#include "Animal.hpp"

Animal::Animal() : type("animal") {
  std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(const Animal& obj) : type(obj.type) {
  std::cout << "Animal Copy constructor called" << std::endl;
}
Animal::~Animal() { std::cout << "Animal Destructor called" << std::endl; }
Animal& Animal::operator=(const Animal& obj) {
  if (&obj != this) {
    this->type = obj.type;
  }
  return *this;
}
void Animal::makeSound() const { std::cout << "Animal Sound!" << std::endl; }
const std::string& Animal::getType() const { return this->type; };