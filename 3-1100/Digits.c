#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long uint64_t;

uint64_t factorial(int n)
{
    uint64_t result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main()
{
    int t;
    scanf("%d ", &t);

    int n, d;
    while (t--)
    {
        scanf("%d %d", &n, &d);
        printf("1");
        if(d % 3 == 0 || n >= 3)
            printf(" 3");
        if(d == 5 || d == 0)
            printf(" 5");
        if(n >= 3 || d == 7)
            printf(" 7");
        if(n >= 9 || d == 9 || ((factorial(n) * d) % 9 == 0))
            printf(" 9");
        printf("\n");
    }
    
}
