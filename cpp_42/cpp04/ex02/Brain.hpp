#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
 private:
  std::string ideas[100];

 public:
  Brain();
  Brain(const Brain& obj);
  ~Brain();
  Brain& operator=(const Brain& obj);
  std::string& getIdeas(int n);
  void setIdeas(int n, std::string target);
};

#endif
