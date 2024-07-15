

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

   /* 如果你移除了 fflush(stdout) 这行代码，使用 exit(0) 时你仍然会看到所有三行输出，
   因为 exit 会在程序退出前刷新输出缓冲区。 */

   exit(0);      
}
