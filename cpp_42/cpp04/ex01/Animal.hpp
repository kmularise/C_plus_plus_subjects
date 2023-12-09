#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
 protected:
  std::string type;

 public:
  Animal();
  Animal(const Animal& obj);
  virtual ~Animal();
  virtual Animal& operator=(const Animal& obj);
  virtual void makeSound() const;
  const std::string& getType() const;
};

#endif
