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
        vector<long long> temp(n);
        sum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
            temp[i] = 0;
        }

        /* Find the max subarray */
        maxSubArray = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                temp[j] += arr[j - i];
                if(temp[j] > maxSubArray)
                    maxSubArray = temp[j];
            }
        }

        if(maxSubArray == 0 && sum == 0)
            result = 0;
        else if(maxSubArray == 0 && sum < 0)
            result = NUM - (abs(sum) % NUM);    
        else
        {
            result = (sum % NUM) + ((maxSubArray * ((long long) mod_pow(2, k, NUM) - 1)) % NUM);
            
            if(result < 0)
                result = NUM - (abs(result) % NUM);
            else if(result > 0)
                result %= NUM;
        }
        cout << result << endl;
    }
    
}
