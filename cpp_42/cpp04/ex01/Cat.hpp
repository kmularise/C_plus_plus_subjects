#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  Cat();
  Cat(const Cat& obj);
  ~Cat();
  Cat& operator=(const Cat& obj);
  void makeSound(void) const;
  const Brain getBrain();
  void setBrain(int idx, std::string source);
};

#endif
