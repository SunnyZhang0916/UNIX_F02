/*
exec 系列函数（如 execv, execl 等）的行为是这样的：它们会用指定的新程序替换当前进程的内存空间。
这意味着如果 exec 调用成功，当前进程会被新程序覆盖，并且新程序的第一条指令将从 main 函数开始执行。
如果 exec 调用失败，它会返回 -1，并设置 errno 以指示错误。

因为 exec 调用永远不会返回成功的情况，所以我们通常在 exec 调用的后面添加一个检查语句来处理失败的情况。
如果 exec 成功，那么调用 exec 的进程会被新程序覆盖，不会执行 exec 调用之后的任何代码。
如果 exec 失败，代码会继续执行，从而可以在 if 语句中处理错误情况。
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main ( void ){
    
  pid_t pid;
    
  pid = fork();
    
  if ( pid < 0 ) {
    perror("fork:");
    exit(1);

  } else if ( pid == 0 ) {

    sleep(5);

    /* (char *) 0) 表示一个空的环境变量列表，即没有额外的环境变量需要传递给新程序。
       这是一个惯例，表示不传递任何额外的环境变量。

       < 0：这是一个条件语句，用于检查 execl 函数是否成功执行。
       如果 execl 函数成功执行，它将在新程序中启动，然后不再返回。
       如果 execl 函数执行失败，它将返回-1，表示出现了错误。
    */
    if ( execl("sillyprog", "Funky","business", "at hand", (char *) 0) < 0 ) {
      perror("Exec:");
      exit(1);
    }

    printf("This line is never executed\n");

  } else {
    sleep(3);

    printf("Parent signing off \n");
  }
        
  return 0;
}
