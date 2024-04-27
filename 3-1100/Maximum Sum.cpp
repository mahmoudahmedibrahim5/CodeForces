#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define NUM 1000000007
using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, k;
    long long sum;
    long long maxSubArray;
    long long result;
    while (t--)
    {
        cin >> n >> k;
        vector<int> arr(n);
        sum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        /* Find the max subarray */
        long long currentSum = 0;
        maxSubArray = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] + currentSum < 0)
                currentSum = 0;
            else
                currentSum += arr[i];
            
            if(currentSum > maxSubArray)
                maxSubArray = currentSum;
        }

        sum = (sum + NUM) % NUM;
        maxSubArray = (maxSubArray + NUM) % NUM;
        int p = 1;
        for(int i = 0; i < k; i++){
            p = (p * 2) % NUM;
        }
        result = (sum + maxSubArray * (p - 1) + NUM) % NUM;
        cout << result << endl;
    }
    
}
