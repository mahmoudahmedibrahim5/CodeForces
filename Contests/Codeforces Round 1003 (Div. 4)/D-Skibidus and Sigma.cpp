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

    uint64_t n, m;
    uint64_t elem;
    while (t--)
    {
        cin >> n >> m;
        vector<pair<uint64_t, uint64_t>> score(n);
        for(int i = 0; i < n; i++)
        {
            score[i].first = 0;
            score[i].second = 0;
            for(int j = 0; j < m; j++)
            {
                cin >> elem;
                score[i].first += elem;
                score[i].second += (elem * (m - j));
            }
        }

        sort(score.begin(), score.end());
        uint64_t lastTotal = 0;
        uint64_t result = 0;
        for(int i = 0; i < n; i++)
        {
            result += (lastTotal * m);
            lastTotal += score[n - i - 1].first;
            result += score[n - i - 1].second;
        }

        cout << result << endl;
    }
    

    return 0;
}
