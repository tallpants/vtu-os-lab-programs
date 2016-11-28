 /*
  * C program that creates a child process to read commands from
  * the standard input and execute them (a minimal implementation
  * of a shell – like program). You can assume that no arguments
  * will be passed to the commands to be executed.
  */

#include <stdio.h>

int main(void) {
    int pid, y;
    char cmd[20];
    pid = fork();
    do {

        if (pid == 0) {
            printf("\nChild Process:\n");
            printf("Enter the command: ");
            scanf("%s", cmd);
            system(cmd);
            printf("\nEnter 0 to exit or 1 to continue: ");
            scanf("%d", &y);
        } else {
            wait();
        }

    } while (y == 1);

    return 0;
}