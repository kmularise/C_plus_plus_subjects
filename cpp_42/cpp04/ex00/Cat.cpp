#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "cat";
  std::cout << "Cat Default constructor called" << std::endl;
}
Cat::Cat(const Cat& obj) : Animal(obj) {
  std::cout << "Cat Copy constructor called" << std::endl;
}
Cat::~Cat() { std::cout << "Cat Destructor called" << std::endl; }
Cat& Cat::operator=(const Cat& obj) {
  Animal::operator=(obj);
  return *this;
}
void Cat::makeSound() const { std::cout << "Cat Sound!" << std::endl; }