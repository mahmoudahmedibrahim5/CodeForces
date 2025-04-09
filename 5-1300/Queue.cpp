#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int sum = 0, count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= sum)
        {
            count++;
            sum += arr[i];
        }
    }

    cout << count << endl;
}
