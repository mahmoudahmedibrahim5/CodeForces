#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    int result;
    string s;
    while (t--)
    {
        cin >> n;
        cin >> s;
        result = 0;
        vector<int> buffer;
        for(int i = n; i > 0; i--)
        {
            auto found = find(buffer.begin(), buffer.end(), s[n-i]);

            if(found == buffer.end())
                buffer.push_back(s[n-i]);
            
            result += (int)buffer.size();
            
        }
        cout << result << endl;
    }

    return 0;
}
