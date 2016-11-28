/*
 * Design, develop and run a program to implement the Banker’s Algorithm.
 * Demonstrate its working with different data values.
 */

#include <stdio.h>
#include <stdlib.h>


void res_request();
int safety();
void input();
int banker();


int main(void) {
    int n;                     // Number of processes
    int m;                     // Number of resources types
    int allocation[10][10];    // (A)
    int maximum[10][10];       // (M)
    int need[10][10];          // (N)
    int available[10];         // (W)

    input(allocation, need, maximum, available, &n, &m);
    int res = banker(allocation, need, available, n, m);

    if (res != 0) {
        int choice;
        printf("\nMake an additional request? (1/0): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int pid;
            printf("\nWhich process: ");
            scanf("%d", &pid);

            res_request(allocation, need, available, pid - 1, m);
            res = banker(allocation, need, available, n, m);
        }
    }

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


int safety(int allocation[10][10], int need[10][10], int available[10], int n, int m, int sequence[10]) {

	int i, j, k;
    int index = 0;
	int finish[10];
    int work[10];
	int pflag = 0;
    int flag = 0;

	for (i = 0; i < n; i++)
		finish[i] = 0;

	for (i = 0; i < m; i++)
        work[i] = available[i];

	for(k = 0; k < n; k++) {

		for (i = 0; i < n; i++) {

			if (finish[i] == 0) {
				flag = 0;

				for (j = 0; j < m; j++) {
					if (need[i][j] > work[j])
						flag = 1;
				}

				if (flag == 0 && finish[i] == 0) {
					for (j = 0; j < m; j++)
						work[j] += allocation[i][j];

					finish[i] = 1;
					pflag++;
					sequence[index++] = i;
				}
			}
		}

		if (pflag == n)
			return 1;

	}

	return 0;
}


int banker(int allocation[10][10], int need[10][10], int available[10], int n, int m) {
    int safe;
    int sequence[10];
    int i;

    safe = safety(allocation, need, available, n, m, sequence);

    if (safe != 0) {
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("%d ", sequence[i]);
        }

        printf("\nA safe sequence exists.");
        return 1;

    } else {

        printf("\nNo safe sequence exists.");
        return 0;
    }
}


void res_request(int allocation[10][10], int need[10][10], int available[10], int pid, int m) {
    int request[10];
    int i;

    printf("Request vector: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &request[i]);
    }

    for (i = 0; i < m; i++) {
        if (request[i] > need[pid][i]) {
            printf("\nError");
            printf("\nThe request exceeds the maximum declared by the process.");
            exit(0);
        }

        if (request[i] > available[i]) {
            printf("\nError");
            printf("\nThere are not enough resources available.");
            exit(0);
        }
    }

    for (i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }
}