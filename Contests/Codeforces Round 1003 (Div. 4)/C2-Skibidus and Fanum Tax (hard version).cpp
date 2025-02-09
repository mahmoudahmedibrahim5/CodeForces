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

    int n, m;
    bool answer;
    while (t--)
    {
        cin >> n >> m;

        vector<int64_t> a(n);
        vector<bool> can(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            can[i] = true;
        }

        int64_t lowest, highest;
        vector<int64_t> b(m);
        for(int i = 0; i < m; i++)
            cin >> b[i];
        sort(b.begin(), b.end());
        lowest = b[0];
        highest = b[m - 1];

        answer = true;
        for(int i = 0; i < n - 1; i++)
        {
            if((lowest < (2 * a[i])) && can[i])
            {
                if(i > 0)
                {
                    for(int j = 0; j < m; j++)
                    {
                        if(a[i - 1] <= b[j] - a[i]){
                            a[i] = b[j] - a[i];
                            break;
                        }
                    } 
                }
                else
                    a[i] = lowest - a[i];
            }
            if(a[i] > a[i + 1])
            {
                if(a[i] > highest - a[i + 1]){
                    answer = false;
                    break;
                }
                for(int j = m - 1; j >= 0; j--)
                {
                    if(a[i] > b[j] - a[i + 1])
                        break;
                    a[i + 1] = b[j] - a[i + 1];
                }
                can[i + 1] = false;
            }
        }

        if(answer)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    

    return 0;
}
