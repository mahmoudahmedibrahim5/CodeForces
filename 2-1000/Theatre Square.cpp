#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;

    int x, y;
    x = n / a;
    y = m / a;
    if(n%a != 0)
        x++;
    if(m%a != 0)
        y++;
    
    cout << (unsigned long long) x * y << endl;
}
