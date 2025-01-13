#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x;
        scanf("%d", &x);
        
        
        if( (x >= 11) && ( x % 11 == 0 || x % 111 == 0) )
            printf("YES\n");
        else
        {
            int result = 0;
            while (x >= 11)
            {
                if(x % 11 == 0){
                    result = 1;
                    break;
                }
                x -= 111;
            }
            
            if(result)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    
    return 0;
}
