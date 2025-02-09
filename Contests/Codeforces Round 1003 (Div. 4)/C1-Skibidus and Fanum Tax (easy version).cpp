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
 
        vector<int64_t>b(m);
        for(int i = 0; i < m; i++)
            cin >> b[i];
 
        answer = true;
        for(int i = 0; i < n - 1; i++)
        {
            if((b[0] < (2 * a[i])) && can[i])
            {
                if(i > 0)
                {
                    if(a[i - 1] <= b[0] - a[i])
                        a[i] = b[0] - a[i];
                }
                else
                    a[i] = b[0] - a[i];
            }
            if(a[i] > a[i + 1])
            {
                a[i + 1] = b[0] - a[i + 1];
                can[i + 1] = false;
                if(a[i] > a[i + 1]){
                    answer = false;
                    break;
                }
            }
        }
 
        if(answer)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
 
    return 0;
}