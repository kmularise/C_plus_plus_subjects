#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) {
    this->inventory[i] = NULL;
  }
}
MateriaSource::MateriaSource(const MateriaSource& obj) {
  for (int i = 0; i < 4; i++) {
    // Deep copy!
    if (obj.inventory[i]) this->inventory[i] = (obj.inventory[i])->clone();
  }
}
MateriaSource::~MateriaSource() {}
MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i]) delete this->inventory[i];
    if (obj.inventory[i]) this->inventory[i] = obj.inventory[i];  // clone 수정
  }
  return *this;
}
void MateriaSource::learnMateria(AMateria* materia) {
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i] == NULL) {
      // std::cout << "Materia " << materia->getType() << " learned" <<
      // std::endl;
      this->inventory[i] = materia;
      return;
    }
  }
  std::cout << "can not learn more than 4 materia";
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i]->getType() == type) return this->inventory[i];
  }
  return NULL;
}