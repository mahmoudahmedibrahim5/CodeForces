#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    uint64_t result = 0;
    uint64_t odd = 0, even = 0;
    bool oddFlag = true;
    int i = n - 1;
    while (i >= 0)
    {
        if(oddFlag)
        {
            while (i > 0 && arr[i] == arr[i - 1])
            {
                odd += arr[i];
                i--;
            }
            odd += arr[i];
            if(i == 0 || arr[i] - arr[i - 1] > 1 || even > odd){
                result += (odd > even)? odd : even;
                odd = 0;
                even = 0;
                i--;
                continue;
            }
        }
        else
        {
            while (i > 0 && arr[i] == arr[i - 1])
            {
                even += arr[i];
                i--;
            }
            even += arr[i];
            if(i == 0 || arr[i] - arr[i - 1] > 1 || odd > even){
                result += (odd > even)? odd : even;
                odd = 0;
                even = 0;
                i--;
                continue;
            }
        }
        oddFlag = !oddFlag;
        i--;
    }
    result += (odd > even)? odd : even;
    
    cout << result << endl;
}
