#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    bool negative;
    while (t--)
    {
        cin >> n;
        negative = true;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] > 0)
                negative = false;
        }

        if(negative)
        {
            int maxNeg = arr[0];
            for(int i = 1; i < n; i++) maxNeg = max(maxNeg, arr[i]);
            cout << maxNeg << endl;
        }
        else
        {
            int64_t maxEven = 0, maxOdd = 0;
            for(int i = 0; i < n; i++)
            {
                if(i & 1)
                    maxEven += max(arr[i], 0);
                else
                    maxOdd += max(arr[i], 0);
            }
            cout << ((maxEven > maxOdd)? maxEven : maxOdd) << endl;
        }
    }
    
}
