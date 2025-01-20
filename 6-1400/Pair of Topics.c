#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int* arr1 = (int *)malloc(sizeof(int) * n1);
    for(int i = 0; i < n1; i++)
        arr1[i] = arr[start + i];
    
    int n2 = end - mid;
    int* arr2 = (int *) malloc(sizeof(int) * n2);
    for(int i = 0; i < n2; i++)
        arr2[i] = arr[mid + 1 + i];

    int index1 = 0;
    int index2 = 0;
    int k = start;

    while (index1 != n1 && index2 != n2)
    {
        if(arr1[index1] > arr2[index2])
        {
            arr[k] = arr2[index2];
            k++;
            index2++;
        }
        else
        {
            arr[k] = arr1[index1];
            k++;
            index1++;
        }
    }

    if(index1 == n1)
    {
        while(index2 != n2)
        {
            arr[k] = arr2[index2];
            k++;
            index2++;
        }
    }
    else
    {
        while(index1 != n1)
        {
            arr[k] = arr1[index1];
            k++;
            index1++;
        }
    }
    
    free(arr1);
    free(arr2);
}

void sortArray(int* arr, int start, int end)
{
    if(start == end)
        return;
    int mid = start + (end - start) / 2;
    sortArray(arr, start, mid);
    sortArray(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    /* Input array a */
    int* arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    /* Input array b 
     * make arr[i] = a[i] - b[i]
     * Count positive, negative and zeros in arr
    **/
    int b;
    int zeros = 0, negative = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &b);
        arr[i] -= b;
        if(arr[i] < 0)
            negative++;
        else if(arr[i] == 0)
            zeros++;
    }
    int positive = n - zeros - negative;

    /* Sort arr */
    sortArray(arr, 0, n - 1);
    
    /* Count the good pairs from the positive and zeros categories */
    int result = (zeros * positive) + ((positive * (positive - 1)) / 2);
    
    /* Count the good pairs in the negative category */
    int index1 = 0;
    int index2 = n - 1;
    
    int count = 0;
    while (index1 != negative && index2 != negative + zeros - 1)
    {
        if((-1 * arr[index1]) >= arr[n - 1]){
            index1++;
        }
        else if((-1 * arr[index1]) < (arr[index2]) && (-1 * arr[index1]) >= (arr[index2 - 1])){
            result += (n - index2);
            index1++;
        }
        else
            index2--;
    }
    
    // for(int i = 0; i < negative; i++)
    // {
    //     int elem = arr[i] * -1;

    //     if(elem >= arr[n - 1])
    //         continue;

    //     /* Binary search starting from index */
    //     int start = negative + zeros, end = n - 1;
    //     for(int j = start; j < n; i++)
    //     {
    //         int mid = (start + end) / 2;
    //         if(arr[mid] > elem && arr[mid - 1] <= elem)
    //         {
    //             result += (n - mid);
    //             break;
    //         }
    //         else if(arr[mid] > elem)
    //             end = mid;
    //         else if(arr[mid] <= elem)
    //             start = mid;
    //     }
    // }

    printf("%d\n", result);

    free(arr);
    return 0;
}
