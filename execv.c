#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main ( void ){
    
  char *exampleArgs[] = {"Funky","business", "at hand", NULL};
  
  pid_t pid;
    
  pid = fork();
    
  if ( pid < 0 ) {
    perror("fork:");
    exit(1);

  } else if ( pid == 0 ) {
    sleep(5);

    /* If execv() fails (returns -1), an error message is printed. */
    if ( execv("sillyprog", exampleArgs) < 0 ) {
      perror("Exec:");
      exit(1);
    }

    /* If execv() succeeds, the current program's execution ends, and "sillyprog" begins execution. */
    printf("This line is never executed\n");

  } else {
    /* The parent process sleeps for 3 seconds */
    sleep(3);
    printf("Parent signing off \n");
  }
        
  return 0;
}
