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
    long long result;
    while(t--)
    {
        result = 0;
        cin >> n;
        vector <long long> arr(n);
        int tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            arr[i] = (long long)pow(2, tmp);
        }
        sort(arr.begin(), arr.end());

        int lastk = 0;
        for(int i = 0; i < n - 2; i++)
        {
            lastk = 0;
            for(int j = i + 1; j < n -1 ; j++)
            {
                if(lastk == n - 1){
                    int count = (n-j-1);
                    if(count%2 == 0)
                        result += (count + 1) * (count / 2);
                    else
                        result += (count) * ((count + 1) / 2);
                    break;
                }
                for(int k = n - 1; k > j; k--)
                {
                    if(arr[i] + arr[j] > arr[k]){
                        result += k - j;
                        lastk = k;
                        break;
                    }
                }
                
            }
        }

        cout << result << endl;
    }

    return 0;
}
