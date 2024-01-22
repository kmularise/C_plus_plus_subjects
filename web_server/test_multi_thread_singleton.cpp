#include <thread>

#include "NginxConfiguration.hpp"

void function() {
  std::cout << "wow!" << std::endl;
  NginxConfiguration& configuration = NginxConfiguration::getInstance();
}

int main() {
  // 스레드 생성 및 시작
  std::thread myThread(function);

  // 메인 스레드에서 실행되는 코드
  for (int i = 0; i < 10; ++i) {
    // std::cout << "메인 스레드에서 실행 중: " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  // 스레드 종료 대기
  myThread.join();

  return 0;
}