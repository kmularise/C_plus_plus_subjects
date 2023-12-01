#include "Harl.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "no log level" << "\n";
        return 1;
    }
    Harl harl;
    std::string logLevel = argv[1];
    harl.complain(logLevel);
}