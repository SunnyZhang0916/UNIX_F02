#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* https://www.youtube.com/watch?v=CIKBGUYEKto&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=18 
    加wait（），让父进程等待子进程结束，这样子进程的资源就会被回收，不会产生僵尸进程了。

    pid_t wait(int *status);
    等待子进程终止，如果子进程终止了，此函数会回收子进程的资源。
    调用 wait 函数的进程会挂起，直到它的一个子进程退出或收到一个不能被忽略的信号时才被唤醒。
    若调用进程没有子进程或它的子进程已经结束，该函数立即返回。

    如果子进程还没有终止，此函数会阻塞父进程，直到子进程终止。
    如果子进程已经终止，此函数会立即返回。

    参数 status 用于获取子进程的退出状态。
    如果不关心子进程的退出状态，可以将 status 设置为 NULL。
    如果子进程正常终止，status 会被设置为子进程的退出状态。
    如果子进程异常终止，status 会被设置为一个非零值。
    如果子进程被信号终止，status 会被设置为 0。
    
    如果调用失败，此函数会返回 -1。
    如果调用成功，此函数会返回子进程的进程 ID。

*/
int main(void)
{
    pid_t pid;
    pid_t pid_back;

    int s;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if (pid == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("I am child process, pid = %d\n", getpid());
            sleep(1);
        }
    }
    else
    {
        //子进程循环五秒的时候，父进程在这里等五秒。五秒后，子进程结束，并且把状态存入到s里面，返回值给pid_back
        pid_back = wait(&s); //调用成功，wait 函数会返回子进程的进程 ID

        printf("pid_back = %d\n", pid_back);

        while (1)
        {
            printf("I am parent process, pid = %d\n", getpid());
            sleep(1);
        }      
    }
    









}
