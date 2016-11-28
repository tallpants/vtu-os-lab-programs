/* 
 * C program to do the following: Using fork( ) create a child process. The child
 * process prints its own process-id and id of its parent and then exits. The parent
 * process waits for its child to finish (by executing the wait( )) and prints its
 * own process-id and the id of its child process and then exits.
 */

#include <stdio.h>

int main(void) {
    int pid = fork();

    if (!pid) {
        printf("Child Process:\n");
        printf("Parent PID: %d\n", getppid());
        printf("Child PID: %d\n", getpid());
    } else {
        wait();
        printf("\nParrent Process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}