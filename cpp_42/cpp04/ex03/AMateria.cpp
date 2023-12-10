#include "AMateria.hpp"

AMateria::AMateria() : type("default") {}
AMateria::AMateria(std::string const& type) : type(type) {}
AMateria::AMateria(const AMateria& obj) : type(obj.type) {}
AMateria::~AMateria() {}
AMateria& AMateria::operator=(const AMateria& obj) {
  this->type = obj.type;
  return *this;
}
std::string const& AMateria::getType() const { return this->type; }
void AMateria::use(ICharacter& target) {
  std::cout << "AMateria use: " << target.getName() << std::endl;
}
