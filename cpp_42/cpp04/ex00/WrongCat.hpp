#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& obj);
  ~WrongCat();
  WrongCat& operator=(const WrongCat& obj);
  void makeSound(void) const;
};

#endif
