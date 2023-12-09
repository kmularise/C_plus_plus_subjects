#include <stdlib.h>

#include "Cat.hpp"
#include "Dog.hpp"
int main() {
  std::cout << "------------check Brain deep copy--------------" << std::endl;
  Brain *brain = new Brain();
  brain->setIdeas(0, "MySQL");
  Brain *copyBrain = new Brain(*brain);
  brain->setIdeas(0, "euijin");
  std::cout << brain->getIdeas(0) << std::endl;
  std::cout << copyBrain->getIdeas(0) << std::endl;
  std::cout << "------------check Animal Arrays-------------" << std::endl;
  Animal *animals[10];
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      animals[i] = new Cat();
    } else {
      animals[i] = new Dog();
    }
  }
  std::cout << "------------check Animal deep copy-------------" << std::endl;
  Dog dog = Dog();

  std::cout << "------------check Animal sound-------------" << std::endl;
  for (int i = 0; i < 10; i++) {
    animals[i]->makeSound();
  }
  std::cout << "------------check Animal delete-------------" << std::endl;
  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }
  system("leaks animal");
  return 0;
}