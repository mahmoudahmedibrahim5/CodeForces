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
    int temp, biggest;
    int result;
    while (t--)
    {
        result = 0;
        cin >> n >> k;
        vector<int> arr(n);
        biggest = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            arr[i] = temp % k;
            if(arr[i] == 0)
                biggest = k;
            else if(arr[i] > biggest)
                biggest = arr[i];
        }
        if(k == 4){
            if(biggest == 4)
                result = 0;
            else if(n == 1)
                result = 4 - arr[0];
            else{
                // we need to find two 2's
                int twos = 0;
                for(int i = 0; i < n; i++)
                {
                    if(arr[i] == 2){
                        twos++;
                        if(twos == 2){
                            result = 0;
                            break;
                        }
                    }
                }

                if(twos == 1){
                    result = 1;
                }
                else if(twos == 0){
                    if(biggest == 3)
                        result = 1;
                    else
                        result = 2;
                }
            }
        }
        else{
            result = k - biggest;
        }
        cout << result << endl;
    }
    
}
