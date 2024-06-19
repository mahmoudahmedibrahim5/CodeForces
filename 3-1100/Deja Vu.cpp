#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
// To decrease the time of calculating (2 pow x), note that there is constrain that x is not exceeding 30
int twos[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
                 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
                 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
int main()
{
    int t;
    cin >> t;
 
    int n, q;
    while (t--)
    {
        cin >> n >> q;
        vector<int> arr(n);
        vector<int> x(q);
 
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < q; i++)
            cin >> x[i];
        
        int min = 31;
        for(int i = 0; i < q; i++)
        {
            if(x[i] >= min)
                continue;
            else
                min = x[i];
            for(int j = 0; j < n; j++)
            {
                if(arr[j] % twos[x[i]] == 0){
                    arr[j] += twos[x[i] - 1];
                }
            }
        }
 
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
 
    return 0;
}