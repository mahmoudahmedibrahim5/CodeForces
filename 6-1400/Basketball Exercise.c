#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;

int main()
{
    int n;
    scanf("%d", &n);

    uint64_t* row1 = (uint64_t *)malloc(sizeof(uint64_t) * n);
    uint64_t* row2 = (uint64_t *)malloc(sizeof(uint64_t) * n);

    for(int i = 0; i < n; i++)
        scanf("%llu", &row1[i]);
    
    for(int i = 0; i < n; i++)
        scanf("%llu", &row2[i]);

    uint64_t** cmp = (uint64_t **)malloc(sizeof(uint64_t *) * 2);
    cmp[0] = (uint64_t *)malloc(sizeof(uint64_t) * n);
    cmp[1] = (uint64_t *)malloc(sizeof(uint64_t) * n);

    uint64_t first = 0, second = 0;
    for(int i = 0; i < n; i++)
    {
        if(first + row2[i] > second)
            cmp[0][i] = first + row2[i];
        else
            cmp[0][i] = second;

        if(second + row1[i] > first)
            cmp[1][i] = second + row1[i];
        else
            cmp[1][i] = first;

        first = cmp[1][i];
        second = cmp[0][i];
    }

    if(cmp[0][n - 1] > cmp[1][n - 1])
        printf("%llu\n", cmp[0][n - 1]);
    else
        printf("%llu\n", cmp[1][n - 1]);

    free(row1);
    free(row2);
    free(cmp[0]);
    free(cmp[1]);
    free(cmp);
    return 0;
}
