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

    while (t--)
    {
        cin >> n;

        vector<unsigned long long> count(n + 1);
        int input;
        for(int i = 0; i < n; i++){
            cin >> input;
            count[input]++;
        }

        vector<unsigned long long> shorter(n + 1);
        shorter[0] = 0;
        for(int i = 1; i < n + 1; i++)
            shorter[i] = shorter[i - 1] + count[i - 1];
        
        unsigned long long result = 0;
        for(int i = 0; i < n + 1; i++){
            result += (count[i] * (count[i] - 1) * (count[i] - 2)) / 6;
            result += (((count[i] * (count[i] - 1)) / 2) * shorter[i]);
        }
        cout << result << endl;
    }
    
}
