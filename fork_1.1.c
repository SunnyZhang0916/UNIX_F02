/*
验证子进程继承父进程的缓冲区

printf 是带缓冲，然后去掉\n

before fork.in son process. 是从父进程的缓冲区继承了before fork，然后靠子进程的\n 刷新出来
before fork.in father process. 父进程依然保留着自己的缓冲区，然后靠父进程的的\n 刷新出来

https://www.youtube.com/watch?v=cNiCLY6kZzk&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=16
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int length = 0;
    char buff[] = "a write to stdout\n";
    pid_t pid;

    /* write 系统调用级，不带缓冲区*/
    length = write(1, buff, strlen(buff));

    if (length != strlen(buff))
    {
        printf("write error");
    }
    
    /* printf 因为有\n， 所以把缓冲区里面内容打到频幕上*/
    printf("before fork.");

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
    }else if (pid == 0)
    {
        printf("in son process.\n");
    }else
    {
        sleep(1);
        printf("in father process.\n");
    }

    return 0;
}