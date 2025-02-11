#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long uint64_t;
typedef long long sint64_t;

int main()
{
    int t;
    cin >> t;

    int n;
    while (t--)
    {  
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr.begin(), arr.end());

        int requiredNumber;
        int count = 0;
        bool fine = true;
        for(int i = n - 1; i >= 0; i--)
        {
            if(fine)
            {
                if(i > 0 && arr[i] == arr[i - 1])
                    i--;
                else
                {
                    fine = false;
                    requiredNumber = arr[i - 1];
                    count = 2 * (arr[i] - arr[i - 1]) + 1;
                }
            }
            else
            {
                if(arr[i] == requiredNumber)
                    count--;
                else
                {
                    count += ((requiredNumber - arr[i]) * 2);
                    requiredNumber = arr[i];
                    count--;
                }
                if(count == 0)
                    fine = true;
            }
        }

        if(fine)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
