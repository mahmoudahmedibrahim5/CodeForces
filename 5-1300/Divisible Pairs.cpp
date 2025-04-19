#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, x, y;
    unsigned long long result;
    pair<int, int> elem;
    while (t--)
    {
        cin >> n >> x >> y;

        vector<int>arr(n);
        map<pair<int, int>, int> count;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        result = 0;
        for(int i = 0; i < n; i++)
        {
            elem.first = arr[i] % x;
            elem.second = arr[i] % y;
            result += count[elem];
            
            elem.first = (x - elem.first) % x;
            count[elem]++;
        }
        cout << result << endl;
    }

}
