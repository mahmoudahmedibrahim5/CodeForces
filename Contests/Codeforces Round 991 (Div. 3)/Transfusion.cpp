#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    unsigned long long n;
    unsigned long long sum, x, evenSum, oddSum;
    while (t--)
    {
        cin >> n;
        sum = 0;
        evenSum = 0;
        oddSum = 0;

        vector<unsigned long long> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
            if(i % 2 == 0)
                evenSum += arr[i];
            else
                oddSum += arr[i];
        }

        if(sum % n != 0)
            cout << "NO" << endl;
        else
        {
            x = sum / n;

            if((oddSum == x * (n / 2)) && (evenSum == x * ((n + 1) / 2)))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    
}
