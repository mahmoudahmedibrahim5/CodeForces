#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;

    int initialTarget = x * n;
    bool allEqual = true;
    bool anyNumberEqual = false;
    int sum = 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        if(arr[i] != x)
            allEqual = false;
        else
            anyNumberEqual = true;
    }

    if(allEqual)
        cout << "0" << endl;
    else if((!anyNumberEqual && sum == initialTarget) ||(anyNumberEqual))
        cout << "1" << endl;
    else
        cout << "2" << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
        solve();
}
