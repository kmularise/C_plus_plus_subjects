#include "Character.hpp"

Character::Character() : name("default") {}
Character::Character(const std::string& name) : name(name){};
Character::Character(const Character& obj) {
  for (int i = 0; i < 4; i++) {
    (this->inventory)[i] = obj.inventory[i];
  }
}
Character::~Character() {}
Character& Character::operator=(const Character& obj) {
  this->name = obj.name;
  for (int i = 0; i < 4; i++) {
    (this->inventory)[i] = obj.inventory[i];
  }
  return *this;
}
void Character::equip(AMateria* materia) {
  if (!materia) {
    std::cout << "AMateraia is null" << std::endl;
  }
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i] == NULL) {
      (this->inventory)[i] = materia;
      return;
    }
  }
  std::cout << this->name << " can not equip more than 4 materia" << std::endl;
};
void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4) {
    std::cout << this->name << " can not unequip invalid index" << std::endl;
    return;
  }
  if ((this->inventory)[idx] == NULL) {
    std::cout << this->name << " can not unequip empty inventory" << std::endl;
    return;
  }
  (this->inventory)[idx] = NULL;
}
void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 4 || this->inventory[idx] == NULL) {
    return;
  }
  this->inventory[idx]->use(target);
}

std::string const& Character::getName() const { return this->name; }
