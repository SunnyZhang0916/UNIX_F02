#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cleanup1() {
    printf("Running cleanup1\n");
}

void cleanup2() {
    printf("Running cleanup2\n");
}

void cleanup3() {
    printf("Running cleanup3\n");
}

int main()
{
    atexit(cleanup1);
    atexit(cleanup2);
    atexit(cleanup3);

    printf("process exit after 3 sec.\n");
    sleep(3);

    return 0;
}