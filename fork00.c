/*
https://www.youtube.com/watch?v=iqtZrODsDj0&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=15
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int var = 10;

int main(int argc, char *argv[])
{
    pid_t pid;
    int number = 9;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
    }

    if (pid == 0)
    {
        var++;
        number++;
        printf("in son process var = %d, number = %d\n", var, number);
    }else{
        sleep(1);
        printf("in father process var = %d, number = %d\n", var, number);
    }
    
    printf("common code area\n");
    
    return 0;
}
