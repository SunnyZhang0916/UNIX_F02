#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>

/* 基本的输入/输出操作、刷新输出缓冲区和使用 sleep 函数来暂停程序执行。*/
int main(void)
{
    printf("Rad 1\n");
    printf("Rad 2\n");

    printf("Rad 3");

    /* 刷新标准输出缓冲区，确保所有前面的输出都已经被发送到屏幕或其他标准输出设备。
       这在缓冲区还没有被自动刷新时很有用（比如，当输出没有换行符时）。*/
	fflush(stdout);

    /* 如果你使用 exit(0);，会先刷新 I/O 缓冲区再结束程序。*/
    sleep(3);

    exit(0);      
}
