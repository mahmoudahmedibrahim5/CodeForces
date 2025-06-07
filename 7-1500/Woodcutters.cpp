#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int64_t, int64_t>> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());

    int64_t result = 2;
    if(n == 1)
        result = 1;
    int64_t last = arr[0].first;
    for(int i = 1 ; i < n - 1; i++)
    {
        if(arr[i].first - arr[i].second > last){
            result++;
            last = arr[i].first;
        }
        else if(arr[i].first + arr[i].second < arr[i + 1].first){
            result++;
            last = arr[i].first + arr[i].second;
        }

        if(arr[i].first > last)
            last = arr[i].first;
    }

    cout << result << endl;
}
