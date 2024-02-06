#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m, k;
    int element;
    int first, second, common;
    while(t--)
    {
        first = 0;
        second = 0; 
        common = 0;
        cin >> n >> m >> k;
        vector<bool> a(k);
        vector<bool> b(k);
        for(int i = 0; i < n; i++){
            cin >> element;
            if(element <= k){
                if(!a[element - 1])
                    first++;
                a[element - 1] = true;
            }
        }
        for(int i = 0; i < m; i++){
            cin >> element;
            if(element <= k){
                if(!b[element - 1]){
                    second++;
                    if(a[element - 1])
                        common++;
                }
                b[element - 1] = true;
            }
        }
        
        first -= common;
        second -= common;
        bool result = true;
        if(first > (k / 2)){
            result = false;
        }
        else if(first < (k / 2)){
            if((first + common) >= (k / 2)){
                common -= ((k/2) - first);
                if((second + common) < (k / 2)){
                    result = false;
                }
            }
            else
                result = false;
        }
        else{
            if((second + common) < (k / 2)){
                result = false;
            }
        }

        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
