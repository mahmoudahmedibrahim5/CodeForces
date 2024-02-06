#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    int n, q;
    int l, r;
    while(t--)
    {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> q;
 
        for(int i = 0; i < q; i++){
            cin >> l >> r;
            int x = arr[l - 1];
            int y = -2;
            for(int j = l; j < r; j++){
                if(x != arr[j]){
                    y = j;
                    break;
                }
            }
            x = l - 1;
            if(y == -2)
                x = -2;
            cout << x + 1 << " " << y + 1 << endl;
        }
        cout << endl;
    }
 
    return 0;
}
