
/* 
https://www.youtube.com/watch?v=Zkdugt9rnzg&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=29
*/


#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char arg[] = {"ls", "-a", "-l", "-h", NULL};

    execv("/bin/ls", arg);  //只需要传一个指针数组

    printf("after execv\n");

    return 0;
}