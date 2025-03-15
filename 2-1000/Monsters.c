#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int** arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int** a1 = (int **)malloc(2 * sizeof(int *));
    a1[0] = (int *)malloc(n1 * sizeof(int));
    a1[1] = (int *)malloc(n1 * sizeof(int));
    for(int i = 0; i < n1; i++){
        a1[0][i] = arr[0][start + i];
        a1[1][i] = arr[1][start + i];
    }

    int n2 = end - mid;
    int** a2 = (int **)malloc(2 * sizeof(int *));
    a2[0] = (int *)malloc(n2 * sizeof(int));
    a2[1] = (int *)malloc(n2 * sizeof(int));
    for(int i = 0; i < n2; i++){
        a2[0][i] = arr[0][mid + i + 1];
        a2[1][i] = arr[1][mid + i + 1];
    }

    int c1 = 0, c2 = 0;
    while (c1 != n1 && c2 != n2)
    {
        if(a1[0][c1] < a2[0][c2])
        {
            arr[0][start] = a2[0][c2];
            arr[1][start] = a2[1][c2];
            c2++;
        }
        else
        {
            arr[0][start] = a1[0][c1];
            arr[1][start] = a1[1][c1];
            c1++;
        }
        start++;
    }

    while (c2 != n2)
    {
        arr[0][start] = a2[0][c2];
        arr[1][start] = a2[1][c2];
        c2++;
        start++;
    }

    while (c1 != n1)
    {
        arr[0][start] = a1[0][c1];
        arr[1][start] = a1[1][c1];
        c1++;
        start++;
    }
    
    free(a1[0]);
    free(a1[1]);
    free(a1);

    free(a2[0]);
    free(a2[1]);
    free(a2);
}

void mergeSort(int** arr, int start, int end)
{
    if(start == end)
        return;
    
    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end); 
}

int main()
{
    int t;
    scanf("%d ", &t);

    int n, k, elem;
    while (t--)
    {
        /* Handle the input */
        scanf("%d %d ", &n, &k);
        int** healthPair = (int **)malloc(2 * sizeof(int *));
        healthPair[0] = (int *)malloc(n * sizeof(int));
        healthPair[1] = (int *)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &healthPair[0][i]);
            healthPair[0][i] %= k;
            healthPair[1][i] = i + 1;
        }

        /* Print the zeros */
        for(int i = 0; i < n; i++)
        {
            if(healthPair[0][i] == 0)
                printf("%d ", healthPair[1][i]);
        }

        /* Sort Descending */
        mergeSort(healthPair, 0, n - 1);


        /* Print the rest of the monsters in order */
        for(int i = 0; i < n; i++)
        {
            if(healthPair[0][i] == 0)
                break;
            printf("%d ", healthPair[1][i]);
        }
        printf("\n");
        
        /* Free the allocated memory */
        free(healthPair[0]);
        free(healthPair[1]);
        free(healthPair);
    }
    
    return 0;
}
