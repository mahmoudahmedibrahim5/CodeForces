#include <stdio.h>
#include <stdlib.h>

int answer[10000];
int input[100];
int element[100];

int main()
{
    int t;
    scanf("%d", &t);

    int n, k;
    while (t--)
    {
        scanf("%d %d", &n, &k);
        int* distinct = (int *)calloc(100, sizeof(int));
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &input[i]);
            /* Find the distinct elements and their count */
            if(distinct[input[i] - 1] == 0)
            {
                distinct[input[i] - 1]++;
                element[count++] = input[i];
            }
        }
        
        /* Array is already beautiful */
        if(n == k)
        {
            printf("%d\n", n);
            for(int i = 0; i < n; i++)
                printf("%d%c", input[i], (i == n - 1)?'\n':' ');
            continue;
        }

        /* Impossible to find beautiful array case */
        if(k < count)
        {
            printf("-1\n");
            continue;
        }

        /* Required elements for beautiful sub array */
        int c = 0;
        while (k > count)
        {
            if(!distinct[c++])
                element[count++] = c;
        }

        int startIndex = 0, answerIndex = 0, inputIndex = count;
        /* First sub array */
        for(int i = 0; i < count; i++)
        {
            if(input[i] == element[i])
                answer[answerIndex++] = input[i];
            else{
                inputIndex = i;
                break;
            }
        }
        for(int i = inputIndex; i < count; i++)
            answer[answerIndex++] = element[i];
        
        /* Rest sub arrays */
        for(int i = inputIndex; i < n; i++)
        {
            while (input[inputIndex] != answer[startIndex])
                answer[answerIndex++] = answer[startIndex++];
            answer[answerIndex++] = input[inputIndex++];
            startIndex++;
        }

        /* Print the answer */
        printf("%d\n", answerIndex);
        for(int i = 0; i < answerIndex; i++)
            printf("%d%c", answer[i], (i == answerIndex - 1)?'\n':' ');
        
        /* Free allocated memory */
        free(distinct);
    }
    
    return 0;
}
