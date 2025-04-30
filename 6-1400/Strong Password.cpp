#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    int n, m;
    char boundaries[10][2];
    bool result;
    while (t--)
    {
        cin >> s;
        n = s.size();
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> boundaries[i][0];

        for(int i = 0; i < m; i++)
            cin >> boundaries[i][1];
        result = false;

        int startingIndex = 0;
        for(int i = 0; i < m; i++)
        {
            int count = boundaries[i][1] - boundaries[i][0] + 1;
            bool arr[10] = {0};
            for(int j = startingIndex; j < n; j++)
            {
                if(s[j] <= boundaries[i][1] && s[j] >= boundaries[i][0] && !arr[s[j] - '0']){
                    count--;
                    if(count == 0){
                        startingIndex = j + 1;
                        break;
                    }
                    arr[s[j] - '0'] = true;
                }
            }
            if(count != 0)
            {
                result = true;
                break;
            }
        }
        cout << (result? "YES" : "NO") << endl;
    }
    
}
