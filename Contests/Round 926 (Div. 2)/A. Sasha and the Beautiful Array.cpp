#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int min, max;
    int a;
    while (t--)
    {
        cin >> n;
        cin >> a;
        min = max = a;

        for(int i = 1; i < n; i++){
            cin >> a;
            if(a > max)
                max = a;
            if(a < min)
                min = a;
        }

        cout << max - min << endl;
    }

    return 0;
}
