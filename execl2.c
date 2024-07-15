/* 
https://www.youtube.com/watch?v=xT7sERov1U4&list=PLwDQt7s1o9J5E4b9lks5f2Nngg5I72scT&index=26
int execl(const char *pathname, const char *arg0, ..., NULL) 
NULL 表示参数的结尾，即可变参数的最后一个参数必须是NULL。
   
execl 的参数列表是一个参数数组，它以第一个参数作为新程序的名称，然后依次列出其他参数。
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execl("/bin/ls", "ls" "-l", "-a", "-h", NULL);  //一旦ls代码成功，就会替代掉main里面的代码，转而去执行"ls" "-l", "-a", "-h"

    printf("after execl\n");                       //因此printf不会再执行


    return 0;
}