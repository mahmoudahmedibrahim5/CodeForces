#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t; 
    cin >> t;
    int n;
    long long result;
    int rotations;
    bool available;

    while (t--)
    {
        cin >> n;
        vector<int> l(n);
        vector<int> r(n);
        vector<int> diff(n);
        vector<int> c(n);
        for(int i = 0; i < n; i++)
            cin >> l[i];      

        for(int i = 0; i < n; i++)
            cin >> r[i];

        for(int i = 0; i < n; i++)
            cin >> c[i];

        sort(l.begin(), l.end()); 
        sort(r.begin(), r.end());

        available = true;
        rotations = 0;
        while (available)
        {
            rotations++;
            for(int i = 0; i < n - rotations; i++)
            {
                if(r[i] > l[i + rotations])
                    continue;
                else
                    available = false;
            }
            if(rotations == n - 1){
                rotations++;
                break;
            }
        }
        rotations--;

        int index = n;
        result = 0;
        sort(c.begin(), c.end());
        
        for(int i = n-rotations; i < n; i++)
            result +=  c[--index] * (r[i] - l[i - rotations]);
        for(int i = 0; i < n - rotations; i++)
            result +=  c[--index] * (r[i] - l[i + rotations]);
        
        cout << result << endl;
    }
    
    return 0;
}
