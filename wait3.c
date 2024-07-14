#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* https://www.youtube.com/watch?v=CIKBGUYEKto&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=18 
    
    取出子进程的退出信息：
    WIFEXITED(status)：如果子进程正常终止，此宏返回一个非零值。

    WEXITSTATUS(status)：如果 WIFEXITED(status) 为真，则此宏返回子进程的退出码。
    返回子进程的退出状态，退出状态保存在status变量的 8 - 16位。
    在用此宏前应先用宏 WIFEXITED 判断子进程是否正常退出，正常退出才可以使用此宏。

*/
int main(void)
{
    pid_t pid;
    pid_t pid_bk;

    int i;
    int s;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if (pid == 0)
    {
        for (i = 0; i < 5; i++)
        {
            printf("I am child process, pid = %d\n", getpid());
            sleep(1);
        }

        return 5; //子进程正常终止，返回值为 5
    }
    else
    {
        pid_bk = wait(&s); //调用成功，wait 函数会返回子进程的进程 ID

        if (WIFEXITED(s) != 0)  //如果子进程正常终止，此宏返回一个非零值。
        {
            printf("WEXITSTATUS: %d\n", WEXITSTATUS(s)); //如果 WIFEXITED(status) 为真，则此宏返回子进程的退出码。
        }
    

        printf("pid_bk = %d\n", pid_bk);

        while (1)
        {
            printf("I am parent process, pid = %d\n", getpid());
            sleep(1);
        }      
    }
}