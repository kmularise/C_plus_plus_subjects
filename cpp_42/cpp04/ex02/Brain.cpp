#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain Default Constructor called" << std::endl; }
Brain::Brain(const Brain& obj) {
  std::cout << "Brain Copy Constructor called" << std::endl;
  *this = obj;
}
Brain::~Brain() { std::cout << "Brain Deconstructor called" << std::endl; }
Brain& Brain::operator=(const Brain& obj) {
  if (this != &obj) {
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = obj.ideas[i];
    }
  }
  return *this;
}
std::string& Brain::getIdeas(int n) { return this->ideas[n]; };
void Brain::setIdeas(int n, std::string target) { this->ideas[n] = target; };