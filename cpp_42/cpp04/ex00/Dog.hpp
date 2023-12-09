#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& obj);
  ~Dog();
  Dog& operator=(const Dog& obj);
  void makeSound(void) const;
};

#endif
