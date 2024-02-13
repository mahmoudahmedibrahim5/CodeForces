#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int sum;
    int x;
    bool result;
    while (t--)
    {
        cin >> n;
        sum = 0;
        vector <int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        x = sum / n;
        result = true;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] < x){
                result = false;
                break;
            }
            else{
                arr[i + 1] += (arr[i] - x);
            }
        }
        if(arr[n - 1] != x)
            result = false;
        
        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}