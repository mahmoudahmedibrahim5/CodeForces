#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, k;
    int product;
    while (t--)
    {
        product = 1;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> result(k);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            product *= arr[i];
        }
        
        if(2023%product == 0){
            cout << "YES" << endl;
            cout << 2023/product;
            for(int i = 1; i < k; i++)
                cout << " 1";
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
}
