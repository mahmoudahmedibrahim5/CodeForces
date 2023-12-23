#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int  n;
    int firstNumber, secondNumber;
    bool found;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        found = true;
        for(long long i = 2; i <= 1000000000000000000; i++)
        {
            firstNumber = arr[0] % i;
            secondNumber = -1;
            found = true;
            for(int j = 1; j < n; j++)
            {
                if(arr[j]%i != firstNumber){
                    if(secondNumber == -1)
                        secondNumber = arr[j]%i;
                    else if(arr[j]%i == secondNumber)
                        continue;
                    else{
                        found = false;
                        break;
                    }
                }
            }
            if(found && secondNumber != -1){
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}
