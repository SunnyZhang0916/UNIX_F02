/* 
https://www.youtube.com/watch?v=QxvRw_Ekxo4&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=27
int execlp(const char *filename, const char *arg0, ..., NULL) 

execlp里面的p表示path，因此file必须是放在系统默认的路径。

*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execlp("ls", "ls" "-l", "-a", "-h", NULL);  //第一个"ls"是文件名，第二个"ls"和 "-l", "-a", "-h"都是参数

    printf("after execlp\n");                       //因此printf不会再执行


    return 0;
}