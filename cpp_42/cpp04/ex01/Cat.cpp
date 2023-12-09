#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "cat";
  this->brain = new Brain();
  std::cout << "Cat Default constructor called" << std::endl;
}
Cat::Cat(const Cat& obj) : Animal(obj) {
  std::cout << "Cat Copy constructor called" << std::endl;
}
Cat::~Cat() {
  delete this->brain;
  std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
  Animal::operator=(obj);
  std::cout << "fuck" << std::endl;
  return *this;
}
void Cat::makeSound() const { std::cout << "Cat Sound!" << std::endl; }
void Cat::setBrain(int idx, std::string source) {
  this->brain->setIdeas(idx, source);
}

const Brain Cat::getBrain() { return *brain; }