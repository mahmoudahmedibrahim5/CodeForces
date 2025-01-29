#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int* a = malloc(n1 * sizeof(int));
    for(int i = 0; i < n1; i++)
        a[i] = arr[start + i];
    
    int n2 = end - mid;
    int* b = malloc(n2 * sizeof(int));
    for(int i = 0; i < n2; i++)
        b[i] = arr[mid + i + 1];

    int c1 = 0, c2 = 0;
    while (c1 != n1 && c2 != n2)
    {
        if(a[c1] < b[c2])
            arr[start++] = a[c1++];
        else
            arr[start++] = b[c2++];
    }

    while (c1 != n1)
    {
        arr[start++] = a[c1++];
    }
    
    while (c2 != n2)
    {
        arr[start++] = b[c2++];
    }
    
    free(a);
    free(b);
}

void mergeSort(int* arr, int start, int end)
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
    scanf("%d", &t);

    unsigned long long n, k;
    while (t--)
    {
        scanf("%llu %llu", &n, &k);

        int* arr = (int *)malloc(n * sizeof(int));
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i] = k - (arr[i] % k);
            if(arr[i] == k)
                arr[i] = 0;
        }

        mergeSort(arr, 0, n - 1);

        /* Find the non-zero start of the array */
        int lastZero = n;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != 0){
                lastZero = i;
                break;
            }
        }
        
        /* Find the biggest index with the biggest count */
        unsigned long long biggestCount = 1, biggestIndex = 0, count = 1;
        for(int i = lastZero; i < n - 1; i++)
        {
            if(arr[i] == arr[i + 1]){
                count++;
            }
            else
            {
                if(count >= biggestCount){
                    biggestCount = count;
                    biggestIndex = arr[i];
                }
                count = 1;
            }
        }
        if(count >= biggestCount){
            biggestCount = count;
            biggestIndex = arr[n - 1];
        }

        /* Find the result */
        unsigned long long result;
        if(lastZero == n)
            result = 0;
        else
            result = k * (biggestCount - 1) + biggestIndex + 1;
        printf("%llu\n", result);
        
        /* Free the allocated space */
        free(arr);
    }
    
    return 0;
}
