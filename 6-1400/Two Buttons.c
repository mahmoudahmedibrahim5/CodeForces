#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int result = 0;
    if(n > m)
        result = n - m;
    else if(n == m)
        result = 0;
    else
    {
        if(m % 2 != 0)
        {
            m++;
            result++;
        }
        while (m > n)
        {
            result++;
            m /= 2;
            if(m % 2 != 0 && m != n)
            {
                m++;
                result++;
            }
        }
        result += n - m;
    }

    printf("%d\n", result);
    return 0;
}
