#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{   
    int t;
    cin >> t;

    int n, k;
    while (t--)
    {
        cin >> n >> k;
        
        if( (int)log2((double)n) >= k)
            cout << (int)pow((double)2, (double)k) << endl;
        else
            cout << n + 1 << endl;
    }
    

    return 0;
}
