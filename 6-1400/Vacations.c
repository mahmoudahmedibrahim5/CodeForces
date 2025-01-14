#include <stdio.h>
#include <stdlib.h>

int findMinimumFreeDays(int* days, int n)
{
    int previousState = 0, minimum = 0;
    
    for(int i = 0; i < n; i++)
    {
        switch (days[i])
        {
        case 0:
            minimum++;
            previousState = 0;
            break;
        
        case 1:
            if(previousState == 0 || previousState == 2)
                previousState = 1;
            else if(previousState == 1){
                minimum++;
                previousState = 0;
            }
            break;

        case 2:
            if(previousState == 0 || previousState == 1)
                previousState = 2;
            else if(previousState == 2){
                minimum++;
                previousState = 0;
            }
            break;
        
        case 3:
            if(previousState == 1)
                previousState = 2;
            else if(previousState == 2)
                previousState = 1;
            else if(previousState == 0 && i != n - 1)
                previousState = 0;
            break;

        default:
            break;
        }
    }

    return minimum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int* days = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &days[i]);

    int result = findMinimumFreeDays(days, n);
    printf("%d\n", result);

    free(days);
    return 0;
}
