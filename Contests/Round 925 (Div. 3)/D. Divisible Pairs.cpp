#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, x, y;
    int element;
    int result;

    while (t--)
    {
        cin >> n >> x >> y;
        vector<int> arr;
        for(int i = 0; i < n; i++){
            cin >> element;
            arr.push_back(element);
        }
        result = 0;
        
        /* Optimize */
        sort(arr.begin(), arr.end());
        int counter = 1;
        int i;
        for(i = 0; i < n - 1; i++){
            if(arr[i] == arr[i + 1]){
                counter++;
                arr.erase(arr.begin() + i);
                i--;
                n--;
            }
            else if(counter > 1){
                if( (arr[i] + arr[i])%x == 0 ){
                    result += (((counter)*(counter-1))/2);
                }
                for(int j = 0; j < n; j++)
                {
                    if(i == j)
                        continue;
                    if( ((arr[i] + arr[j])%x == 0) && (abs(arr[i] - arr[j])%y == 0) )
                        result += counter;
                }
                arr.erase(arr.begin() + i);
                n--;
                counter = 1;
            }
        }      
        if(counter > 1){
            if( (arr[i] + arr[i])%x == 0 ){
                result += (((counter)*(counter-1))/2);
            }
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if( ((arr[i] + arr[j])%x == 0) && (abs(arr[i] - arr[j])%y == 0) )
                    result += counter;
            }
            arr.erase(arr.begin() + i);
            n--;
        }  
        /************/

        for(i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if( ((arr[i] + arr[j])%x == 0) && (abs(arr[i] - arr[j])%y == 0) )
                    result++;
            }
        }

        cout << result << endl;
    }

    return 0;
}
