#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    bool first;
    int f, l;
    char element;
    while(t--)
    {
        first = true;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> element;
            if(element == 'B'){
                if(first){
                    f = i;
                    first = false;
                }
                l = i;
            }
        }

        cout << l - f + 1 << endl;
    }

    return 0;
}
