/*
 * Using OpenMP, Design, develop and run a multi-threaded program
 * to generate and print Fibonacci Series. One thread has to generate
 * the numbers up to the specified limit and another thread has to
 * print them. Ensure proper synchronization.
 */

#include <stdio.h>
#include <omp.h>

int main(void) {
    int number_of_terms;
    int i;
    int array[10];

    omp_set_num_threads(2);

    printf("Enter the number of terms: ");
    scanf("%d", &number_of_terms);

    array[0] = 0;
    array[1] = 1;

    #pragma omp parallel
    {
        #pragma omp single
        for (i = 2; i < number_of_terms; i++) {
            array[i] = array[i - 1] + array[i - 2];
            printf("Thread %d -- generated term number %d\n", omp_get_thread_num(), i + 1);
        }

        #pragma omp single
        {
            printf("\nThe series is:\n");
            for (i = 0; i < number_of_terms; i++) {
                printf("Thread %d -- generated term %d\n", omp_get_thread_num(), array[i]);
            }
        }
    }

    return 0;
}