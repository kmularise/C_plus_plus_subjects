#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string name;
  AMateria*(inventory[4]);

 public:
  Character();
  Character(const std::string& name);
  Character(const Character& obj);
  ~Character();
  Character& operator=(const Character& obj);
  void equip(AMateria* materia);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
  std::string const& getName() const;
};

#endif

// Character::Character(/* args */) {}
// Character::Character(const std::string& name) : name(name){};
// Character::Character(const Character& obj) {}
// Character::~Character() {}
// Character& Character::operator=(const Character& obj) {}
// void Character::equip(AMateria* materia) {
//   if (!materia) {
//     std::cout << "AMateraia is null" << std::endl;
//   }
//   for (int i = 0; i < 4; i++) {
//     if (this->inventory[i] == NULL) {
//       (this->inventory)[i] = materia;
//     }
//   }
//   std::cout << this->name << " can not equip more than 4 materia" <<
//   std::endl;
// };
// void Character::unequip(int idx) {
//   if (idx < 0 || idx >= 4) {
//     std::cout << this->name << " can not unequip invalid index" << std::endl;
//     return;
//   }
//   if ((this->inventory)[idx] == NULL) {
//     std::cout << this->name << " can not unequip empty inventory" <<
//     std::endl; return;
//   }
//   AMateria* materia = (this->inventory)[idx];
//   (this->inventory)[idx] = NULL;
// }
// void Character::use(int idx, ICharacter& target){

// };
