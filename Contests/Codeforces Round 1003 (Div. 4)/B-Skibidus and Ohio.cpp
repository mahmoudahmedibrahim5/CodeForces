#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long uint64_t;
typedef long long int64_t;

int main()
{
    int t;
    cin >> t;

    int len;
    int result;
    while (t--)
    {
        string s;
        cin >> s;
        len = (int)s.size();

        result = len;
        for(int i = len - 1; i > 0; i--)
        {
            if(s[i] == s[i - 1]){
                result = 1;
                break;
            }
        }
        cout << result << endl;
    }
    

    return 0;
}
