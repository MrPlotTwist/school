#include <stdio.h>
#include <stdlib.h>

void selection_sort(int a[], int N, int* comparison, int* swap);

void print_array(int a[], int N, int i, int min) {
    printf("Step %d: ", i+1);
    for (int k = 0; k < N; k++) {
        if (k == i && k == min) {
            printf("[(%d)] ", a[k]);
        }
        else if (k == i)
            printf("(%d) ", a[k]);
        else if (k == min)
            printf("[%d] ", a[k]);
        else
            printf("%d ", a[k]);
    }
    printf("\n");
}


int main()
{
    int zahl = 1, size, comparison = 0, swap = 0;
    int* array = malloc(1024 * sizeof(int));
    printf(":\n");
    while(zahl != 0) {
        scanf("%d", &zahl);
        if (zahl != 0) {
        array[size] = zahl;
        ++size;
        }
        //printf("size:%d", size);
        //printf("zahl:%d", zahl);
    }
    selection_sort(array, size, &comparison, &swap);

    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("\nNumber of comparisons: %d", comparison);
    printf("\nNumber of swaps: %d", swap);

    free(array);

    return 0;
}

void selection_sort(int a[], int N, int* comparison, int* swap) {
    int i, j, min, t;
        for(i = 0; i < N-1; i++)    {
            min = i;
            for (j = i+1; j < N; j++) {// suche kleinstes El.
                if (a[j] < a[min])
                    min = j; // merke Position des kleinsten El.
                ++(*comparison);
            }
             print_array(a, N, i, min);
            t = a[min]; // Tausch
            a[min] = a[i];
            a[i] = t;
            ++(*swap);
        }
}
