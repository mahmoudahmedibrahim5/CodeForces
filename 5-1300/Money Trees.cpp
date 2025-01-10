#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, k;
    int currentLength, result, sum;
    int start;
    while (t--)
    {
        cin >> n >> k;
        vector<int> heights(n);
        vector<int> fruits(n);

        for(int i = 0; i < n; i++)
            cin >> fruits[i];
        for(int i = 0; i < n; i++)
            cin >> heights[i];

        result = 0;
        currentLength = 0;
        start = n;

        // Find the first feasible index
        for(int i = 0; i < n; i++)
        {
            if(fruits[i] <= k)
            {
                start = i;
                sum = fruits[i];
                currentLength = 1;
                result = 1;
                break;
            }
        }

        for(int i = start; i < n - 1; i++)
        {
            //cout << "Start: " << start << ", Sum = " << sum <<  ", Result = " << result << endl;
            if(heights[i] % heights[i + 1] == 0)
            {
                sum += fruits[i + 1];
                currentLength++;
            }
            else
            {
                if(currentLength > result)
                    result = currentLength;
                currentLength = 1;
                start = i + 1;
                sum = fruits[i + 1];
            }

            if(sum > k)
            {
                // Check the length without the last added element
                if((currentLength - 1) > result)
                    result = currentLength - 1;

                while (sum > k)
                {
                    sum -= fruits[start];
                    start++;
                    currentLength--;
                }
                
            }
        }

        if(sum <= k && currentLength > result)
            result = currentLength;

        cout << result << endl;
    }
}
