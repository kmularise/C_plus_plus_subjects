#include <stdlib.h>

int f() {
    char *a= malloc(sizeof(char) * 8);
    // printf("%p\n", a);
    // for (int i = 0; i < 8; i++) {

    // }
    return (0);
}

int main() {
    // char *a;
    // a= malloc(sizeof(char) * 8);
    // a[8] = 1;
    f();
    system("leaks a.out");
}