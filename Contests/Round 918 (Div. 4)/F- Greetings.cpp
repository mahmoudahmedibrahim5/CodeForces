#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    long long result;
    int n;

    while(t--)
    {
        result = 0;
        cin >> n;
        vector<pair<int, int>> in(n);
        
        for(int i = 0; i < n; i++)
            cin >> in[i].first >> in[i].second;
        
        //sort(in.begin(), in.end());
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(in[j].second < in[i].second && in[j].first > in[i].first)
                    result++;
            }
        }
        cout << result << endl;
    }
}
