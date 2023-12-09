#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->type = "dog";
  this->brain = new Brain();
  std::cout << "Dog Default constructor called" << std::endl;
}
Dog::Dog(const Dog& obj) : Animal(obj) {
  this->brain = new Brain(*(obj.brain));
  std::cout << "Dog Copy constructor called" << std::endl;
}
Dog::~Dog() {
  delete this->brain;
  std::cout << "Dog Destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& obj) {
  // Animal::operator=(obj);

  std::cout << "check " << &obj << this << std::endl;
  return *this;
}
void Dog::makeSound() const { std::cout << "Dog Sound!" << std::endl; }