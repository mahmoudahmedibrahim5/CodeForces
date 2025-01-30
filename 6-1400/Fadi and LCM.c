#include <stdio.h>

typedef unsigned long long uint64_t;

int main()
{
    uint64_t x;
    scanf("%llu", &x);

    uint64_t a = 1, b = x;
    uint64_t pairA = 1, pairB = x;
    uint64_t c = 1;
    char t;
    while (pairA < pairB)
    {
        if(x % c == 0)
        {
            t = 1;
            for(int i = 1; i < pairA; i++)
            {
                if((pairB * i) % pairA == 0){
                    t = 0;
                    break;
                }
            }
            if(t){
                a = pairA;
                b = pairB;
            }
        }
        c++;
        pairA = c;
        pairB = x / c;
    }

    printf("%llu %llu\n", a, b);
    return 0;
}
