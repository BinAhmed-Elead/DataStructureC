#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int secret_num = 0x8badf00d;
    printf("Hello ");
    printf(argv[1]);
    printf("! You'll never get my secret!\n");
    return 0;
}