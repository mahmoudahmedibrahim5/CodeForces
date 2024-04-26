#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define NUM 1000000007
using namespace std;

long long mod_pow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

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

        //cout << "Sum = " << sum << ", maxSubArray = " << maxSubArray << ", Result = " << result << endl;
        cout << result << endl;
    }
    
}
