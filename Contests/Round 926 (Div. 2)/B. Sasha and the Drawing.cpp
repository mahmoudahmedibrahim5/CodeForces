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
    int result;
    while (t--)
    {
        cin >> n >> k;
        if(k <= 4 * n - 4)
            result = (k + 1) / 2;
        else if(k == 4 * n - 3)
            result = 2 * n - 1;
        else if(k == 4 * n - 2)
            result = 2 * n;
        cout << result << endl;
    }
    
    return 0;
}