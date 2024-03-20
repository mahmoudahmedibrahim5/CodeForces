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
    int tmp;
    while (t--)
    {
        cin >> n >> k;
        vector<pair<int,int>> monsters(n);
        
        for(int i = 0; i < n; i++){
            cin >> tmp;
            monsters[i].first = tmp % k;
            monsters[i].second = i + 1;
            if(monsters[i].first == 0)
                cout << monsters[i].second << " ";
        }
        
        pair<int, int> temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(monsters[j].first < monsters[j + 1].first)
                {
                    temp.first = monsters[j].first;
                    temp.second = monsters[j].second;
                    monsters[j].first = monsters[j + 1].first;
                    monsters[j].second = monsters[j + 1].second;
                    monsters[j + 1].first = temp.first;
                    monsters[j + 1].second = temp.second;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(monsters[i].first != 0)
                cout << monsters[i].second << " ";
            else
                break;
        }
        cout << endl;
    }
    
    return 0;
}
