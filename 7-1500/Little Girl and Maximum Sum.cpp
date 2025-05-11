#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    vector<pair<int, int>> count(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[i].first = 0;
        count[i].second = 0;
    }

    int l, r;
    for(int i = 0; i < q; i++)
    {
        cin >> l >> r;
        count[l - 1].first += 1;
        count[r - 1].second -= 1; 
    }

    int carry = 0;
    for(int i = 0; i < n; i++)
    {
        carry += count[i].first;
        count[i].first = carry;
        carry += count[i].second;
    }

    sort(arr.begin(), arr.end());
    sort(count.begin(), count.end());

    uint64_t result = 0;
    for(int i = 0; i < n; i++)
        result += ((uint64_t)count[i].first * (uint64_t)arr[i]);
    cout << result << endl;

}
