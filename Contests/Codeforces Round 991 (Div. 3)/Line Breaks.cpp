#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m, x;
    string s;
    while (t--)
    {
        x = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> s;
            m -= (int)s.size();
            if(m >= 0)
                x++;
        }

        cout << x << endl;
    }
    
}
