#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long uint64_t;
//typedef long long int64_t;

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
        ||  (x != 0) && (k != 1) && (y - x > k)
        ||  (k > y)
        )
        {
            cout << "-1" << endl;
            continue;
        }

        if(highest)
        {
            printOnes(k);
            y -= k;
            for(int i = 0; i < y; i++)
                cout << "01";
            printZeros(x - y);
        }
        else
        {
            printZeros(k);
            y -= k;
            for(int i = 0; i < y; i++)
                cout << "10";
            printOnes(x - y);
        }
        
        cout << endl;
    }
    

    return 0;
}
