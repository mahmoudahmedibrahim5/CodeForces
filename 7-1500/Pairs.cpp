#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pairs(m);
    int x, y;
    bool finished;
    int index;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        pairs[i].first = x;
        pairs[i].second = y;
    }

    for(int j = 0; j <= 1; j++)
    {
        finished = true;
        if(j == 0)
            x = pairs[0].first;
        else
            x = pairs[0].second;
        for(int i = 0; i < m; i++)
        {
            if(pairs[i].first != x && pairs[i].second != x){
                finished = false;
                index = i;
                break;
            }
        }

        if(finished){
            cout << "YES" << endl;
            break;
        }
        else
        {
            y = pairs[index].first;
            finished = true;
            for(int i = index; i < m; i++)
            {
                if(pairs[i].first != x && pairs[i].second != x && pairs[i].first != y && pairs[i].second != y){
                    finished = false;
                    break;
                }
            }
            
            if(finished){
                cout << "YES" << endl;
                break;
            }
            else
            {
                y = pairs[index].second;
                finished = true;
                for(int i = index; i < m; i++)
                {
                    if(pairs[i].first != x && pairs[i].second != x && pairs[i].first != y && pairs[i].second != y){
                        finished = false;
                        break;
                    }
                }
                
                if(finished){
                    cout << "YES" << endl;
                    break;
                }
                else
                {
                    if(j == 0)
                        continue;
                    else
                        cout << "NO" << endl;
                }
            }
        }
    }
                

}
