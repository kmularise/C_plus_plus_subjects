#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure& obj) : AMateria(obj.getType()) {}
Cure::~Cure() {}
Cure& Cure::operator=(const Cure& obj) {
  this->type = obj.type;
  return *this;
}
Cure* Cure::clone() const { return new Cure(); };
void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
