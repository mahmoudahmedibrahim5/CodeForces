#include <stdio.h>
#include <stdlib.h>

unsigned long long findResult(unsigned long long result, int t, unsigned long long** cmp, unsigned long long* row1, unsigned long long* row2, int n)
{
    //printf("Initial result = %d\n", result);
    for(int i = 1; i < n - 1; i++){
        if(t == 1)
        {
            if(cmp[i][1] > cmp[i + 1][1]){
                result += row2[i];
                //printf("Row2 chosen\n");
                t = 0;
            }
            else
                t = 3;
        }
        else if(t == 3)
        {
            if(cmp[i][1] > cmp[i + 1][1]){
                result += row2[i];
                //printf("Row2 chosen\n");
                t = 0;
            }
            else{
                result += row2[i - 1];
                //printf("Row2 chosen\n");
                result += row1[i];
                //printf("Row1 chosen\n");
                t = 1;
            }
        }

        else if(t == 0)
        {
            if(cmp[i][0] > cmp[i + 1][0]){
                result += row1[i];
                //printf("Row1 chosen\n");
                t = 1;
            }
            else
                t = 2;
        }
        else if(t == 2)
        {
            if(cmp[i][0] > cmp[i + 1][0]){
                result += row1[i];
                //printf("Row1 chosen\n");
                t = 1;
            }
            else
            {
                result += row1[i - 1];
                //printf("Row1 chosen\n");
                result += row2[i];
                //printf("Row2 chosen\n");
                t = 0;
            }
        }
        //printf("Result = %d\n", result);
    }
    if(n != 1)
    {
        if(t == 1 || t == 3)
            result += row2[n - 1];
        else
            result += row1[n - 1];
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    unsigned long long* row1 = (unsigned long long *)malloc(sizeof(unsigned long long) * n);
    unsigned long long* row2 = (unsigned long long *)malloc(sizeof(unsigned long long) * n);

    for(int i = 0; i < n; i++)
        scanf("%ld", &row1[i]);
    
    for(int i = 0; i < n; i++)
        scanf("%ld", &row2[i]);

    unsigned long long** cmp = (unsigned long long **)malloc(sizeof(unsigned long long *) * n);

    cmp[n - 1] = (unsigned long long *)malloc(sizeof(unsigned long long) * 2);
    cmp[n - 1][0] = row1[n - 1];
    cmp[n - 1][1] = row2[n - 1];

    for(int i = n - 2; i >= 0; i--){
        cmp[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * 2);
        cmp[i][0] = row1[i] + cmp[i + 1][1];
        cmp[i][1] = row2[i] + cmp[i + 1][0];
    }

    unsigned long long result1 = findResult(row1[0], 1, cmp, row1, row2, n);
    unsigned long long result2 = findResult(row2[0], 0, cmp, row1, row2, n);
    //printf("Result1 = %d, Result2 = %d\n", result1, result2);

    if(result1 > result2)
        printf("%ld\n", result1);
    else
        printf("%ld\n", result2);

    free(row1);
    free(row2);
    for(int i = 0; i < n; i++)
        free(cmp[i]);
    free(cmp);
    return 0;
}
