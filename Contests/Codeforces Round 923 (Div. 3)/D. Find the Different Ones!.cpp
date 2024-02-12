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
    int element, lastElement;
    while(t--)
    {
        cin >> n;
        vector<int> arr(n);
        arr[0] = -1;
        cin >> lastElement;
        for(int i = 1; i < n; i++){
            cin >> element;
            if(element == lastElement)
                arr[i] = arr[i - 1];
            else
                arr[i] = i;
            lastElement = element;
        }

        cin >> q;
 
        for(int i = 0; i < q; i++){
            cin >> l >> r;
            l--;
            r--;
            if(arr[l] == arr[r])
                cout << "-1 -1" << endl;
            else{
                cout << arr[r] << " " << r + 1 << endl;
            }
        }
        cout << endl;
    }
 
    return 0;
}
