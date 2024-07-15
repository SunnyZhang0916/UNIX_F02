# include   <stdio.h>

int main ( int argc, char *argv[] ){
  int i;
    
  for (i = 0; i < argc; i++) {

    /* 将参数的位置和值输出到标准输出（stdout）*/
    fprintf(stdout, "Arg nr %d = %s\n", i, argv[i]);
  }

  /* 退出状态码（Exit Status Code）是一个整数值，用于表示程序的退出状态。
     通常，一个程序的退出状态码为0表示成功，非零值表示出现了错误或特定的问题。
     每个程序可以自定义其退出状态码的含义，但通常约定俗成的是，0表示一切正常，非零值表示某种错误或问题。*/
  return 7;
}
