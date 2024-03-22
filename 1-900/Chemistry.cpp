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
    char input;
    while (t--)
    {
        int count[26] = {0};
        cin >> n >> k;

        for(int i = 0; i < n; i++){
            cin >> input;
            count[(int)(input - 'a')]++;
        }

        if((n - k) % 2 != 0)
            k++;
        
        for(int i = 0; i < 26; i++)
        {
            if(count[i] % 2 == 0)
                continue;
            else
                k--;
        }

        if(k < 0 || k % 2 != 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    
    return 0;
}
