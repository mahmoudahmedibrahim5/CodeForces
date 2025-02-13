#include <stdio.h>
#include <string.h>

typedef unsigned long long uint64_t;

#define ABS_MAX         1000000007
#define STRING_MAX_LEN  100014
uint64_t mem[STRING_MAX_LEN + 1];

void calculatePossibilities(void)
{
    mem[0] = 1;
    mem[1] = 1;
    for(int i = 2; i <= STRING_MAX_LEN; i++)
        mem[i] = (mem[i - 2] + mem[i - 1]) % ABS_MAX;
}

int main()
{
    char string[STRING_MAX_LEN];
    fgets(string, STRING_MAX_LEN, stdin);
    int n = strlen(string);
    calculatePossibilities();

    uint64_t result = 1;
    uint64_t count = 0;
    char current = 'o';
    for(int i = 0; i < n; i++)
    {
        /* 0 Case */
        if(string[i] == 'm' || string[i] == 'w'){
            result = 0;
            break;
        }

        /* If found u or n */
        if(current == 'o' && (string[i] == 'u' || string[i] == 'n'))
        {
            count = 1;
            current = string[i];
        }

        /* Repeating u or n */
        else if(current == 'u' || current == 'n')
        {
            if(string[i] == current)
                count++;
            else
            {
                result = (result * mem[count]) % ABS_MAX;
                if(string[i] == 'n' || string[i] == 'u'){
                    current = string[i];
                    count = 1;
                }
                else
                    current = 'o';
            }
        }
    }
    if(current != 'o')
        result = (result * mem[count]) % ABS_MAX;

    printf("%llu\n", result);
    return 0;
}
