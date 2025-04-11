#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m, x;
    int start, end;
    while (t--)
    {
        cin >> n >> x >> m;
        start = end = x;

        int l, r;
        for(int i = 0; i < m; i++)
        {
            cin >> l >> r;
            if(l >= start && l <= end)
                end = max(end, r);
            else if(r >= start && r <= end)
                start = min(start, l);
            else if(l <= start && r >= end){
                start = l;
                end = r;
            }
        }
        cout << end - start + 1 << endl;
    }
    

}
