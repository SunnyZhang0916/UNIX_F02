

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>

/* 基本的输入/输出操作、刷新输出缓冲区和使用 sleep 函数来暂停程序执行。*/
int main(void)
{
    printf("Rad 1\n");
    printf("Rad 2\n");

    printf("Rad 3");


    sleep(3);

   /* 如果你移除了 fflush(stdout) 这行代码，如果你使用 _exit(0)，"Rad 3" 可能不会被输出，因为没有换行符或 fflush 来触发缓冲区的刷新。 */
    _exit(0);      
}
