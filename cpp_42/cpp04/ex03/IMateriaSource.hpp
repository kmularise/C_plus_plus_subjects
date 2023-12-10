#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

class IMateriaSource {
 private:
  /* data */
 public:
  virtual ~IMateriaSource() {}
  // virtual IMateriaSource& operator=(const IMateriaSource& obj) = 0;
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif

// IMateriaSource& IMateriaSource::operator=(const IMateriaSource& obj) {}
