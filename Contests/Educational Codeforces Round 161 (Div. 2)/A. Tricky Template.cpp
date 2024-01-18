#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    string a, b, c;
    bool match;
    while (t--)
    {
        cin >> n;
        cin >> a >> b >> c;

        match = true;
        for(int i = 0; i < n; i++){
            if(c[i] != a[i] && c[i] != b[i]){
                match = false;
                break;
            }
        }

        if(match)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    
    return 0;
}
