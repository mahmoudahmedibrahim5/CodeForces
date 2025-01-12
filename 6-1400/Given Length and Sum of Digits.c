#include <stdio.h>
#include <stdlib.h>

void printMinimum(int m, int s);
void printMaximum(int m, int s);

int main()
{
    int m, s;
    scanf("%d %d", &m, &s);

    /* Invalid */
    if((m * 9) < s || (s == 0 && m > 1))
        printf("-1 -1\n");
    
    else
    {
        /* Print the minimum number */
        printMinimum(m, s);

        /* Print the maximum number */
        printMaximum(m, s);
        
        printf("\n");
    }

    return 0;
}

void printMinimum(int m, int s)
{
    char* minimum = malloc(sizeof(char) * (m + 1));
    minimum[m] = '\0';

    // Add the nines
    while (s > 10)
    {
        minimum[--m] = '9';
        s -= 9;
    }

    // Add the last number
    if(m == 1)
        minimum[0] = s + '0';
    
    else if(m != 0)
    {
        // Add the last non-zero number
        minimum[--m] = s - 1 + '0';

        // Fill the rest with zeros
        while (m > 1)
        {
            m--;
            minimum[m] = '0';
        }

        minimum[0] = '1';
    }
    
    
    
    printf("%s ", minimum);
    free(minimum);
}

void printMaximum(int m, int s)
{
    // Print the nines
    while (s > 9)
    {
        printf("9");
        m--;
        s -= 9;
    }

    // Print the last non-zero number
    if(m > 0){
        printf("%d", s);
        m--;
    }
    
    // Fill the rest with zeros
    while (m--)
        printf("0");
}
