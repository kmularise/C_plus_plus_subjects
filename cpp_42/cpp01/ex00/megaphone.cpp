#include <iostream>

int main(int ac, char *argv[]) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < ac ; i++) {
            for (int j = 0; argv[i][j]; j++) {
                std::cout << (char) (toupper(argv[i][j]));
            }
            if (i != ac -1) std::cout << ' ';
        }
    }
    std::cout << '\n';
}