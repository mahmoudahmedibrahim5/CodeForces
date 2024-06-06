#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m;
    while (t--)
    {
        cin >> n >> m;
        cout << n * (m / 2) << endl;
    }
    
}
