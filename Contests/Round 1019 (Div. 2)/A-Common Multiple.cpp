#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    while (t--)
    {
        cin >> n;
        set<int> arr;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.insert(x);
        }
        cout << arr.size() << endl;
    }
}
