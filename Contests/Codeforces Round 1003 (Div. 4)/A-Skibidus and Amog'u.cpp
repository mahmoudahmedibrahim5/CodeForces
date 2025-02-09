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

    while (t--)
    {
        string w;
        cin >> w;
        w.erase(w.end() - 1);
        w.erase(w.end() - 1);
        w.push_back('i');
        cout << w << endl;        
    }
    

    return 0;
}
