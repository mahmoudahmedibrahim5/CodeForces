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
    int x, y;
    int ones;
    int result;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        ones = 0;
        result = 0;
        for(int i = 0; i < n - 1; i++){
            cin >> x >> y;
            arr[x - 1]++;
            arr[y - 1]++;
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == 1)
                ones++;
        }

        result = (((((n) * (n - 1)) / 2) + n + 1) % 998244353);

        if(ones > 2){
            if(ones == 3)
                result += 1;
            else if(ones == 4)
                result += 5;
            else// if(ones == 5)
                result += (((ones) * (ones - 1)) / 2) + ones + 1;
        }
        result %= 998244353;

        cout << result << endl;
    }
    

}