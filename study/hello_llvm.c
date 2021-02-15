#include <stdio.h>

void printLessThan2(int number);

void printGe2(int number) {
    printf("ge %d\r\n", number);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printLessThan2(argc);
    } else {
        printGe2(argc);
    }
    printf("hello llvm \r\n");
    return 0;
}

void printLessThan2(int number) {
    printf("less %d\r\n", number);
}