/*

僵尸进程

假如没有了wait，也就是子进程结束了，但资源还没有被回收，而父进程还没结束了，子进程就处于僵尸状态。

https://www.youtube.com/watch?v=CIKBGUYEKto&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=18
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   pid_t pid;

   pid = fork();

   if (pid < 0)
   {
    perror("fork");
    return 0;
   }else if (pid == 0)
   {
    for (int i = 0; i < 5; i++)
    {
        printf("this is son process.\n");
    }    
   }else
   {
    while (1)
    {
        printf("this is father process.\n");
        sleep(1);
    }
    
   }
   
    


    return 0;
}