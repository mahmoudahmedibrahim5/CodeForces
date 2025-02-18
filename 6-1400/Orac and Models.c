#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);

    int n;
    int result;
    while (t--)
    {
        scanf("%d", &n);
        int* arr = (int *)malloc((n + 1) * sizeof(int));
        int* maxModels = (int *)malloc((n + 1) * sizeof(int));
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        
        result = 1;
        for(int i = n; i > n / 2; i--)
            maxModels[i] = 1;

        for(int i = n / 2; i >= 1; i--)
        {
            maxModels[i] = 1;
            for(int j = 2 * i; j <= n; j+= i)
            {
                if(arr[j] > arr[i] && (maxModels[j] + 1) > maxModels[i])
                    maxModels[i] = maxModels[j] + 1;
            }
            if(maxModels[i] > result)
                result = maxModels[i];
        }

        printf("%d\n", result);
        free(arr);
        free(maxModels);
    }
    
}
