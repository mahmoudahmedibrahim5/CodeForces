#include <stdio.h>
#include <math.h>

#define DEBUG   0
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

const int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

/* Find F(x)
 * for positive integer x, it's the product of factorials of its digits. 
 * For example F(135) = 1! * 3! * 5!
*/
uint64_t F(uint64_t x, uint32_t n);

/* Factorize Fa */
void Factorize(uint64_t Fa, uint32_t* twos, uint32_t* threes, uint32_t* fives, uint32_t* sevens);

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

    /* Calculate F(a) */
    uint64_t Fa = F(a, n);

    /* Factorize F(a) */
    uint32_t twos = 0, threes = 0, fives = 0, sevens = 0;
    Factorize(Fa, &twos, &threes, &fives, &sevens);

    /* Find maximum x that satisfies the two conditions */
    FindMaximumX(twos, threes, fives, sevens);

    return 0;
}

uint64_t F(uint64_t x, uint32_t n)
{
    uint64_t Fx = 1; 
    for(int i = 0; i < n; i++){
        uint32_t digit = x / (uint64_t)pow(10, (double)i);
        if(digit == 0)
            break;
        Fx *= factorial[(digit % 10)]; 
    }
    #if DEBUG
        printf("Fa = %lld\n", Fx);
    #endif
    return Fx;
}

void Factorize(uint64_t Fa, uint32_t* twos, uint32_t* threes, uint32_t* fives, uint32_t* sevens)
{
    while (Fa > 1)
    {
        #if DEBUG
            printf("Fa = %lld, twos = %u, threes = %u, fives = %u, sevens = %u\n", Fa, *twos, *threes, *fives, *sevens);
        #endif
        if(Fa % 2 == 0){
            Fa /= 2;
            (*twos)++;
        }
        else if(Fa % 3 == 0){
            Fa /= 3;
            (*threes)++;
        }
        else if(Fa % 5 == 0){
            Fa /= 5;
            (*fives)++;
        }
        else if(Fa % 7 == 0){
            Fa /= 7;
            (*sevens)++;
        }
        else{
            printf("error\n");
            break;
        }
    }
    #if DEBUG
        printf("twos = %u, threes = %u, fives = %u, sevens = %u\n", *twos, *threes, *fives, *sevens);
    #endif
}

void FindMaximumX(uint32_t twos, uint32_t threes, uint32_t fives, uint32_t sevens)
{
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
