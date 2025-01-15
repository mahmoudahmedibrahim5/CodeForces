#include <stdio.h>
#include <stdlib.h>

void sort2DArray(int** arr, int n)
{
    int* tmp = NULL;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j][0] > arr[j + 1][0] || ((arr[j][0] == arr[j + 1][0]) && (arr[j][1] > arr[j + 1][1])) )
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int** exams = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++)
    {
        exams[i] = (int *) malloc(sizeof(int) * 2);
        scanf("%d %d", &exams[i][0], &exams[i][1]);
    }

    sort2DArray(exams, n);

    int previousDay = exams[0][1];
    for(int i = 1; i < n; i++)
    {
        if(exams[i][1] >= previousDay)
            previousDay = exams[i][1];
        else
            previousDay = exams[i][0];
    }

    printf("%d\n", previousDay);

    for(int i = 0; i < n; i++)
        free(exams[i]);
    free(exams);

    return 0;
}
