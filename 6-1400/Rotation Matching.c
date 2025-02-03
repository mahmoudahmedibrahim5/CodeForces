#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d ", &n);

    int* a = (int *)malloc(n * sizeof(int));
    int* index = (int *)malloc(n * sizeof(int));
    int* offset = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        index[a[i] - 1] = i;
    }

    int* b = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        offset[(index[b[i] - 1] - i + n) % n]++;
    }

    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(offset[i] > max)
            max = offset[i];
    }

    printf("%d\n", max);

    free(a);
    free(b);
    free(index);
    free(offset);
    return 0;
}
