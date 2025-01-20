#include <stdio.h>
#include <math.h>

#define DEBUG   0
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

const uint64_t power10[] = {1, 10, 100, 1000, 10000,
                            1e5, 1e6, 1e7, 1e8, 1e9,
                            1e10, 1e11, 1e12, 1e13, 1e14, 1e15
                            };
/* Factorize Fa */
void Factorize(uint64_t a, uint32_t n, uint32_t* twos, uint32_t* threes, uint32_t* fives, uint32_t* sevens);

/* Find maximum x that satisfies the two conditions 
 * x doesn't contain neither digit 0 nor digit 1
 * F(x) = F(a)
*/
void FindMaximumX(uint32_t twos, uint32_t threes, uint32_t fives, uint32_t sevens);

int main()
{
    /* Take the input */
    uint32_t n;
    uint64_t a;
    scanf("%d", &n);
    scanf("%lld", &a);

    /* Factorize */
    uint32_t twos = 0, threes = 0, fives = 0, sevens = 0;
    Factorize(a, n, &twos, &threes, &fives, &sevens);

    /* Find maximum x that satisfies the two conditions */
    FindMaximumX(twos, threes, fives, sevens);

    return 0;
}

void Factorize(uint64_t a, uint32_t n, uint32_t* twos, uint32_t* threes, uint32_t* fives, uint32_t* sevens)
{
    for(int i = 0; i < n; i++)
    {
        uint64_t digit = a / power10[i];
        #if DEBUG
            printf("digit before modulo = %u\n", digit);
        #endif
        if(digit == 0)
            break;
        digit %= 10;
        #if DEBUG
            printf("digit = %u\n", digit);
        #endif
        switch (digit)
        {
            case 2:
                (*twos)++;
                break;
            case 3:
                (*twos)++;
                (*threes)++;
                break;
            case 4:
                (*twos) += 3;
                (*threes)++;
                break;
            case 5:
                (*twos) += 3;
                (*threes)++;
                (*fives)++;
                break;
            case 6:
                (*twos) += 4;
                (*threes) +=2;
                (*fives)++;
                break;
            case 7:
                (*twos) += 4;
                (*threes) +=2;
                (*fives)++;
                (*sevens)++;
                break;
            case 8:
                (*twos) += 7;
                (*threes) +=2;
                (*fives)++;
                (*sevens)++;
                break;
            case 9:
                (*twos) += 7;
                (*threes) += 4;
                (*fives)++;
                (*sevens)++;
                break;
            default:
                break;
        }
    }
}

void FindMaximumX(uint32_t twos, uint32_t threes, uint32_t fives, uint32_t sevens)
{
    #if DEBUG
        printf("\ntwos = %u, threes = %u, fives = %u, sevens = %u\n", twos, threes, fives, sevens);
    #endif
    if(sevens != 0)
    {
        fives -= sevens;
        threes -= (sevens * 2); // Sixes and threes
        twos -= (sevens * 4);   // Sixes, fours, and twos
        for(int i = 0; i < sevens; i++)
            printf("7");
    }
    #if DEBUG
        printf("\ntwos = %u, threes = %u, fives = %u, sevens = %u\n", twos, threes, fives, sevens);
    #endif

    if(fives != 0)
    {
        threes -= fives;
        twos -= (fives * 3);   // fours and twos
        for(int i = 0; i < fives; i++)
            printf("5");
    }
    #if DEBUG
        printf("\ntwos = %u, threes = %u, fives = %u, sevens = %u\n", twos, threes, fives, sevens);
    #endif
    
    if(threes != 0)
    {
        twos -= threes;
        for(int i = 0; i < threes; i++)
            printf("3");
    }
    #if DEBUG
        printf("\ntwos = %u, threes = %u, fives = %u, sevens = %u\n", twos, threes, fives, sevens);
    #endif

    if(twos != 0)
    {
        for(int i = 0; i < twos; i++)
            printf("2");
    }
    #if DEBUG
        printf("\ntwos = %u, threes = %u, fives = %u, sevens = %u\n", twos, threes, fives, sevens);
    #endif

    printf("\n");
}
