#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long uint64_t;
typedef long long sint64_t;

int main()
{
    int t;
    cin >> t;

    int x, y;
    while (t--)
    {
        cin >> x >> y;

        if(
            y - x == 1
        || ((x - y > 0) && ((x - y + 1) % 9 == 0))
        )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}

