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
    int repeatStart, repeatEnd;
    bool stop;
    int result;

    while (t--)
    {
        cin >> n;
        vector <int> arr(n);

        stop = false;
        cin >> arr[0];

        repeatStart = 1;
        for(int i = 1; i < n; i++){
            cin >> arr[i];
            if(!stop && arr[i] == arr[i - 1]){
                repeatStart++;
            }
            else{
                stop = true;
            }
        }
        
        if((repeatStart > n / 2 && arr[0] != arr[n - 1]) || (repeatStart == n))
            result = n - repeatStart;
        else
        {
            repeatEnd = 1;
            for(int i = n - 2; i >= 0; i--)
            {
                if(arr[i] == arr[i + 1]){
                    repeatEnd++;
                }
                else{
                    break;
                }
            }
            if(arr[0] == arr[n - 1])
                result = n - (repeatStart + repeatEnd);
            else
            {
                if(repeatEnd > repeatStart)
                    result = n - repeatEnd;
                else
                    result = n - repeatStart;
            }
        }
        
        cout << result << endl;
    }

    return 0;
}
