#ifndef Location_HPP
#define Location_HPP
#include <string>
#include <vector>
class Location {
 private:
  std::string& root;
  std::vector<int> index;
  /* data */
 public:
  Location();
  ~Location();
  const std::string& getValue(std::string& path) const;
  const std::string& getValue()
};

#endif