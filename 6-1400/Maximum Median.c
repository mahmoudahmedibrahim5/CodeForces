#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;

void merge(int* arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int* a = (int *)malloc(sizeof(int) * n1);
    for(int i = 0; i < n1; i++)
        a[i] = arr[start + i];

    int n2 = end - mid;
    int* b = (int *)malloc(sizeof(int) * n2);
    for(int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int c1 = 0, c2 = 0, k = 0;
    while (c1 != n1 && c2 != n2)
    {
        if(a[c1] < b[c2])
            arr[start++] = a[c1++];
        else
            arr[start++] = b[c2++];
    }
    
    while (c1 != n1)
        arr[start++] = a[c1++];
    
    while (c2 != n2)
        arr[start++] = b[c2++];
    
    free(a);
    free(b);
}

void mergeSort(int* arr, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end)
        return;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int* arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    mergeSort(arr, 0, n - 1);

    int mid = n / 2;
    for(int i = 1; i <= mid; i++)
    {
        if((uint64_t)(((uint64_t)arr[mid + i] - (uint64_t)arr[mid]) * (uint64_t)i) < (uint64_t)k){
            k -= ((arr[mid + i] - arr[mid]) * i);
            arr[mid] = arr[mid + i];
        }
        else{
            arr[mid] += (k / i);
            k = 0;
            break;
        }
    }
    if(k != 0)
        arr[mid] += (k / (mid + 1));
    
    printf("%d\n", arr[mid]);

    free(arr);
    return 0;
}
