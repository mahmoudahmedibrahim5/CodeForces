#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int p1, p2, p3;
    while (t--)
    {
        cin >> p1 >> p2 >> p3;
        if((p1 + p2 + p3) % 2 != 0)
            cout << "-1" << endl;
        else if((p1 + p2) < (p1 + p2 + p3) / 2)
            cout << p1 + p2 << endl;
        else
            cout << (p1 + p2 + p3) / 2 << endl;
    }
    
}
