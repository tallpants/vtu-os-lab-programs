/*
 * Design, develop and run a program to implement the Banker’s Algorithm.
 * Demonstrate its working with different data values.
 */

 #include <stdio.h>


void res_request();
int safety();
void input();
int banker();


int main(void) {
    int n;                     // Number of processes
    int m;                     // Number of resources types
    int allocation[10][10];    // Allocation matrix          (A)
    int maximum[10][10];       // Maximum matrix             (M)
    int need[10][10];          // Need matrix                (N)
    int available[10];         // Available vector           (W)

    input(allocation, need, maximum, available, &n, &m);

    return 0;
}


void input(int allocation[10][10], int need[10][10], int maximum[10][10], int available[10], int *n, int *m) {               
    int i, j;

    printf("How many processes: ");
    scanf("%d", n);

    printf("How many resources types: ");
    scanf("%d", m);

    printf("Allocation matrix:\n");
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nMaximum matrix:\n");
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("\nAvailable resource vector:\n");
    for (i = 0; i < *m; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nThe need matrix is:\n");
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }
}