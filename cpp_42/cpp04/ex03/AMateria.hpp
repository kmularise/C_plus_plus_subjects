#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
 protected:
  std::string type;

 public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const AMateria& obj);
  virtual ~AMateria();
  AMateria& operator=(const AMateria& obj);
  std::string const& getType() const;  // Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif

// AMateria::AMateria(/* args */) {}
// AMateria::AMateria(std::string const& type) {}
// AMateria::AMateria(const AMateria& obj) {}
// AMateria::~AMateria() {}
// AMateria& AMateria::operator=(const AMateria& obj) {}
