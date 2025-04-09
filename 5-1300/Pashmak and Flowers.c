#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    // Scan the first element
    int tmp;
    scanf("%d", &tmp);
    int min = tmp, max = tmp;
    int minCount = 1, maxCount = 1;
    
    // Scan the rest of the elements
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp > max)
        {
            max = tmp;
            maxCount = 1;
        }
        else if(tmp == max)
            maxCount++;
        
        if(tmp < min)
        {
            min = tmp;
            minCount = 1;
        }
        else if(tmp == min)
            minCount++;
    }

    uint64_t ways;
    if(min == max)
        ways = ((uint64_t)minCount * (uint64_t)(minCount - 1)) / 2;
    else
        ways = (uint64_t)minCount * (uint64_t)maxCount;

    printf("%d %llu\n", (max - min), ways);
}
