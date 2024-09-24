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
    while (t--)
    {
        cin >> n >> m;
        vector<int> infected(m);
        for(int i = 0; i < m; i++)
            cin >> infected[i];
        sort(infected.begin(), infected.end());
        
        vector<int> spaces(m);
        for(int i = 0; i < m - 1; i++)
            spaces[i] = infected[i + 1] - infected[i] - 1;
        spaces[m - 1] = infected[0] + (n - infected[m - 1]) - 1;
        sort(spaces.begin(), spaces.end());

        int protectedCount = 0;  
        for(int i = 0; i < m; i++)
        {
            if((spaces[m - 1 - i] - 4 * i) > 0){

                if(spaces[m - 1 - i] - 4 * i == 1)
                    protectedCount += 1;
                else
                    protectedCount += spaces[m - 1 - i] - 1 - 4 * i;
            }
            else
                break;
        }

        cout << n - protectedCount << endl;
    }
    
}
