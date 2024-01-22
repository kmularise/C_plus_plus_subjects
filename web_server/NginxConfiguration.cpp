#include "NginxConfiguration.hpp"

NginxConfiguration& NginxConfiguration::getInstance() {
  static NginxConfiguration config;
  static bool initialized = false;
  if (!initialized) {
    std::string content = config.readFile("nginx.conf");
    config.parse(content);
    initialized = true;
  }
  return config;
}

NginxConfiguration::~NginxConfiguration() {
  std::cout << "[INFO] NginxCofiguation destroy" << std::endl;
}
NginxConfiguration::NginxConfiguration() {
  std::cout << "[INFO] NginxConfig start" << std::endl;
}

std::string NginxConfiguration::readFile(const std::string& fileName) {
  std::ifstream inputFile(fileName);
  if (!inputFile.is_open()) {
    std::cerr << "파일을 열 수 없습니다." << std::endl;
    return "";
  }
  std::string fileContents((std::istreambuf_iterator<char>(inputFile)),
                           std::istreambuf_iterator<char>());
  inputFile.close();
  std::cout << fileContents << std::endl;
  return fileContents;
}

void NginxConfiguration::parse(std::string& content){};
