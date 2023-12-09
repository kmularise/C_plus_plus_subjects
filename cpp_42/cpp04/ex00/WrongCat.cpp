#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  this->type = "wrong_cat";
  std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj) {
  std::cout << "WrongCat Copy constructor called" << std::endl;
}
WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& obj) {
  WrongAnimal::operator=(obj);
  return *this;
}
void WrongCat::makeSound() const {
  std::cout << "WrongCat Sound!" << std::endl;
}