#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long uint64_t;
typedef long long int64_t;

void printZeros(int x)
{
    for(int i = 0; i < x; i++)
        cout << "0";
}

void printOnes(int x)
{
    for(int i = 0; i < x; i++)
        cout << "1";
}

int main()
{
    int t;
    cin >> t;

    int n, m, k;
    int x, y; // x = lowest, y = highest
    bool highest; // 0 (false) zeros are more than ones, 1 (true) ones are more than zeros
    while (t--)
    {
        cin >> n >> m >> k;
        if(n < m){
            x = n;
            y = m;
            highest = true; // ones are more than zeros
        }
        else{
            x = m;
            y = n;
            highest = false; // zeros are more than ones
        }

        /* Check the impossible cases */
        if(
            ((x == 0 || y == 0) && (x + y > k))
        ||  ((k == 1) && (y - x > 1))
        ||  (x != 0) && (k != 1) && (y / x >= k)
        )
        {
            cout << "-1" << endl;
            continue;
        }

        /* Possible Cases */
        if(k == 1)
        {
            if(highest)
            {
                cout << "1";
                for(int i = 0; i < x; i++)
                    cout << "01";
            }
            else
            {
                cout << "0";
                for(int i = 0; i < x; i++)
                    cout << "10";
            }
        } 
        else if(x == 0 || y == 0)
        {
            if(highest)
                printOnes(m);
            else
                printZeros(n);
        }
        else
        {
            /* Print the maximum balance value */
            if(highest)
                printOnes(k);
            else
                printZeros(k);

            y -= k;
            if(y == 0)
            {
                if(!highest)
                    printOnes(m);
                else
                    printZeros(n);
            }
            else
            {
                /* Update the highest */
                bool oldHeigest = highest;
                if(y < x)
                {
                    /* Swap */
                    y += x;
                    x = y - x;
                    y -= x; 
                    highest = !highest;
                }

                int ratio = y / x;
                if(highest)
                {
                    while (y % x != 0)
                    {
                        if(oldHeigest){
                            printZeros(1);
                            printOnes(ratio + 1);
                        }
                        else
                        {
                            printOnes(ratio + 1);
                            printZeros(1);
                        }
                        x--;
                        y -= (ratio + 1);
                    }

                    for(int i = 0; i < x; i++){
                        if(oldHeigest){
                            printZeros(1);
                            printOnes(ratio);
                        }
                        else
                        {
                            printOnes(ratio);
                            printZeros(1);
                        }
                        
                    }
                }   
                else
                {
                    while (y % x != 0)
                    {
                        if(oldHeigest){
                            printZeros(ratio + 1);
                            printOnes(1);
                        }
                        else
                        {
                            printOnes(1);
                            printZeros(ratio + 1);
                        }
                        x--;
                        y -= (ratio + 1);
                    }

                    for(int i = 0; i < x; i++){
                        if(oldHeigest){
                            printZeros(ratio);
                            printOnes(1);
                        }
                        else
                        {
                            printOnes(1);
                            printZeros(ratio);
                        }
                    }
                }
            }
            }

            
        cout << endl;
    }
    

    return 0;
}
