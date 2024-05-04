#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int dir;
    int result;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        result = n;
        dir = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] == arr[i - 1])
                result--;
            else if(arr[i] > arr[i - 1]){
                if(dir == 1)
                    result--;
                dir = 1;
            }
            else if(arr[i] < arr[i - 1]){
                if(dir == -1)
                    result--;
                dir = -1;
            }
        }

        cout << result << endl;
    }
    
}
