#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] %= 2;
    }
    
    int even = 1;
    if(arr[0] + arr[1] + arr[2] > 1)
        even = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == even){
            cout << i + 1 << endl;
            break;
        }
    }
}
