#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int da, va, dc, vc;
    int d, v;
    while (t--)
    {
        cin >> n;
        cin >> da >> va;
        cin >> dc >> vc;
        cin >> d;

        v = vc - (dc - d);
        if(v < va)
            v = va;
        
        cout << v << endl;

    }
    
}
