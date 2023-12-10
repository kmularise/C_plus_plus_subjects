#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& obj) : AMateria(obj.getType()) {}
Ice::~Ice() {}
Ice& Ice::operator=(const Ice& obj) {
  this->type = obj.type;
  return *this;
}
Ice* Ice::clone() const { return new Ice(); };
void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
};
