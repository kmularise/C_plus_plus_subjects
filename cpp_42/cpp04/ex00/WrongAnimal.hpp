#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
 protected:
  std::string type;

 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& obj);
  virtual ~WrongAnimal();
  WrongAnimal& operator=(const WrongAnimal& obj);
  void makeSound() const;
  const std::string& getType() const;
};

#endif
