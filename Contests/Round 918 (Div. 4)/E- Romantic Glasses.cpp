#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int odd, even;
    bool result;
    while(t--)
    {
        result = false;
        cin >> n;
        vector<int> arr(n);
        cin >> arr[0];
        for(int i = 1; i < n; i++){
            cin >> arr[i];
            if(arr[i] == arr[i - 1])
                result = true;
        }
        if(!result)
        {
            for(int i = 0; i < n; i++)
            {
                odd = arr[i];
                even = arr[i + 1];
                for(int j = i + 2; j < n; j++)
                {
                    if(j%2 == 0)
                        odd += arr[j];
                    else
                        even += arr[j];
                    if(odd == even){
                        result = true;
                        break;
                    }
                }
                if(result)
                    break;
            }
        }
        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}