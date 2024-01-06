#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t;

    long long x, y;
    while (t--)
    {
        cin >> x >> y;
        if(y%x == 0)
        {
            cout << y*y/x << endl;
        }
        else
        {
            int g = gcd(x, y);
            cout << x * y / gcd << endl;
        }  
    }
    
}