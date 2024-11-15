#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    int sum = 0;
    int max = -100000;
    int firstNegativeIndex = n;
    int lastOddNumber = 0;
 
    if(arr[n-1] >= 0 && arr[0] >= 0) // All values are positive
    {
        // In positive values find the last odd number
        for(int i = n-1; i >= 0; i--)
        {
            sum += arr[i];
            if(arr[i] %2 != 0)
                lastOddNumber = arr[i];
        }
 
        // Find the maximum
        if(sum % 2 == 0)
            max = sum - lastOddNumber;
        else
            max = sum;
    }
    else if(arr[n-1] < 0 && arr[0] < 0) // All values are negative
    {
        // Find the first odd number
        for(int i = n - 1; i >= 0; i--)
            if((-1 * arr[i]) % 2 != 0){
                max = arr[i];
                break;
            }
    }
    else 
    {
        // In positive values find the last odd number
        // Find sum of positive values
        // Find the first negative index
        for(int i = n-1; i >= 0; i--)
        {
            if(arr[i] < 0){
                firstNegativeIndex = i;
                break;
            }
 
            sum += arr[i];
            if(arr[i] %2 != 0)
                lastOddNumber = arr[i];
        }
 
        if(sum % 2 != 0)
        {
            max = sum;
        }
        else // sum is even
        {
            if(lastOddNumber != 0)
                max = sum - lastOddNumber;
 
            // Find the first negative odd number
            for(int i = firstNegativeIndex; i >= 0; i--)
                if((-1 * arr[i]) % 2 != 0){
                    sum += arr[i];
                    if(sum > max)
                        max = sum;
                    break;
                }
 
            
        }
    }
 
    cout << max << endl;
}
