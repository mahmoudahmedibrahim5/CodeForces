#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m;
    int x, y;
    int cost;
    while (t--)
    {
        cin >> n;
        vector<int> cities(n);
        for(int i = 0; i< n; i++)
            cin >> cities[i];
        
        cin >> m;
        
        vector<int> right(n);
        vector<int> left(n);
        right[0] = 1;
        left[0] = 0;
        right[n - 1] = 0;
        left[n - 1] = 1;

        int r, l;
        for(int i = 1; i < n - 1; i++)
        {
            r = cities[i + 1] - cities[i];
            l = cities [i] - cities[i - 1];
            if(r > l){
                right[i] = r;
                left[i] = 1;
            }
            else{
                right[i] = 1;
                left[i] = l;
            }
        }

        while (m--)
        {
            cin >> x >> y;
            cost = 0;
            if(x > y){
                // left
                for(int i = x - 1; i > y - 1; i--)
                    cost += left[i];
            }
            else{
                // right
                for(int i = x - 1; i < y - 1; i++)
                    cost += right[i];
            }
            cout << cost << endl;
        }
        
    }
    
    return 0;
}
