#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    bool evenFlag;
    bool result;
    while (t--)
    {
        /* Handling the input */
        cin >> n;
        vector<int> arr(n);
        evenFlag = true;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(!evenFlag)
                arr[i] *= -1;
            evenFlag = !evenFlag;
        }

        result = false;
        set<int64_t> sum;
        int64_t s = 0;
        for(int i = 0; i < n; i++)
        {
            s += arr[i];
            if(s == 0)
            {
                result = true;
                break;
            }
            auto error = sum.insert(s);
            if(!error.second)
            {
                result = true;
                break;
            }
        }

        cout << (result ? "YES" : "NO") << endl;
    }
    
}
