#include "ContentConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc == 4) {
        std::string fileName = argv[1];
        std::string source = argv[2];
        std::string target = argv[3];
        ContentConverter contentConverter(fileName);
        int status = contentConverter.replace(source, target);
        return status;
    } else {
        std::cerr << "input number is invalid" << "\n";
        return 1;
    }
}