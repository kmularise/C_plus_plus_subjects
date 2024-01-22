#ifndef NginxConfiguration_HPP
#define NginxConfiguration_HPP

#include <fstream>
#include <iostream>
#include <string>

class NginxConfiguration {
 private:
  static const int MY_CONSTANT = 42;
  int port;
  // std::string& serverName;
  // std::string& defaultType;
  // bool sendFile;
  // int keepalive_timeount;
  NginxConfiguration();
  NginxConfiguration(const NginxConfiguration& ref);
  ~NginxConfiguration();
  NginxConfiguration& operator=(const NginxConfiguration& ref);
  std::string readFile(const std::string& fileName);
  void parse(std::string& content);

 public:
  static NginxConfiguration& getInstance();
  // int getPort();
  // const std::string& getServerName() const;
  // const std::string& getLocation(
  //     std::string& path) const;  // 추후에 다른 타입으로 바꿔두기
};

#endif