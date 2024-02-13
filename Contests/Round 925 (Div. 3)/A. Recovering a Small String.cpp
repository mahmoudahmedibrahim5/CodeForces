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
    string result = "aaa";
    while (t--)
    {
        cin >> n;
        for(int i = 2; i >= 0; i--)
        {
            if(n >= 26 + i){
                result[i] = 'z';
                n -= 26;
            }
            else{
                result[i] = ('a' + (n - i - 1));
                n -= (n - i);
            }
        }

        cout << result << endl;
    }

    return 0;
}
