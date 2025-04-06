#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int calculate(int n, int a, int b)
{
    int count = 1;
    n -= a;
    while (n > 0)
    {
        if(n % b == 0)
            return count + (n / b);
        count++;
        n -= a;
    }
    return -1;
}

int main()
{
    int n;
    vector<int> arr(3);
    cin >> n >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    int result = 0;

    /* Only one element */
    for(int i = 0; i < 3; i++)
    {
        if(n % arr[i] == 0)
        {
            if((n / arr[i]) > result)
                result = n / arr[i];
        }
    }

    /* Only Two elements */
    if(calculate(n, arr[1], arr[0]) > result)
        result = calculate(n, arr[1], arr[0]);
    if(calculate(n, arr[2], arr[0]) > result)
        result = calculate(n, arr[2], arr[0]);
    if(calculate(n, arr[2], arr[1]) > result)
        result = calculate(n, arr[2], arr[1]);

    /* 3 Elements */
    int count = 1;
    n -= arr[2];
    while (n > 0)
    {
        if(calculate(n, arr[1], arr[0]) + count > result)
            result = calculate(n, arr[1], arr[0]) + count;
        count++;
        n -= arr[2];
    }
    
    /* Print the result */
    cout << result << endl;
}
