#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    int oddNumbers;
    while (t--)
    {
        cin >> n;
        
        vector<int>arr(n);
        vector<int>sums(n);
        vector<int>results(n);
        
        cin >> arr[0];
        results[0] = arr[0];
        sums[0] = arr[0];
        if(arr[0] % 2 == 0)
            oddNumbers = 0;
        else 
            oddNumbers = 1;

        for(int i = 1; i < n; i++){
            cin >> arr[i];
            if(arr[i] % 2 != 0)
                oddNumbers++;
            sums[i] = arr[i] + sums[i - 1];
            results[i] = sums[i] - (oddNumbers/3);
            if(oddNumbers%3 == 1)
                results[i]--;
        }

        cout << results[0] ;
        for(int i = 1; i < n; i++){
            cout << " ";
            if(results[i]%2 == 0)
                cout << results[i];
            else
                cout << results[i] - 1;
        }
        cout << endl;
    }
}