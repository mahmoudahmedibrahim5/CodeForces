#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, m, x;
    while (t--)
    {
        cin >> n >> m >> x;
        vector<int> towers(m);
        vector<int> blocks(n);
        vector<int> results(n);

        for(int i = 0; i < n; i++)
            cin >> blocks[i];

        if(m > n)
        {
            cout << "NO" << endl;
        }
        else
        {
            int smallestIndex = 0;
            for(int i = x; i > 0; i--)
            {
                for(int j = 0; j < n; j++)
                {
                    if(blocks[j] == i){
                        results[j] = smallestIndex + 1;
                        smallestIndex = (smallestIndex+1)%m;
                    }
                }
            }
            cout << "YES" << endl;
            for(int i = 0; i < n; i++)
                cout << results[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
