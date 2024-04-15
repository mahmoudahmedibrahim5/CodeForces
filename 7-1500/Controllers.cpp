#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char input;
    int pluses = 0, minuses = 0;
    for(int i = 0; i < n; i++){
        cin >> input;
        if(input == '+')
            pluses++;
        else
            minuses++;
    }

    int q;
    cin >> q;
    long long a, b;
    long long tot = pluses - minuses;
    long long k;
    while (q--)
    {
        cin >> a >> b;
        if(tot == 0)
            cout << "YES" << endl;
        else if(b == a)
            cout << "NO" << endl;
        else if( abs(b * tot) % abs(b - a) == 0)
        {
            k = (b * tot) / (b - a);
            if(k >= -minuses && k <= pluses)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } 
        else
            cout << "NO" << endl;
    }
    
}
