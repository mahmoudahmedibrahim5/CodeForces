#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, k, d;
    int result;
    int count;
    while (t--)
    {
        cin >> n >> k >> d;
        vector<int> arr(n);
        vector<int> intervals(k);
        result = 0;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < k; i++)
            cin >> intervals[i];
        
        for(int i = 1; i <= d; i++){
            count = 0;
            for(int j = 0; j < intervals[(i-1)%k]; j++){
                if(arr[j] == j + 1)
                    count++;
                arr[j]++;
            }
            for(int j = intervals[(i-1)%k]; j < n; j++){
                if(arr[j] == j + 1)
                    count++;
            }
            count += (d-i)/2;
            if(count > result)
                result = count;
        }
        cout << result << endl;
    }

    return 0;
}