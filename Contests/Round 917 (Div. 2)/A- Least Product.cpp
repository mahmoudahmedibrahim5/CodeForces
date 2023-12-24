#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    int element;
    int negatives;
    bool zero;
    while (t--)
    {
        cin >> n;
        negatives = 0;
        zero = false;
        for(int i = 0; i < n; i++)
        {
            cin >> element;
            if(element < 0)
                negatives++;
            else if(element == 0)
                zero = true;
        }
        if( (negatives != 0 && (negatives%2!=0)) || zero)
            cout << "0" << endl;
        else
        {
            cout << "1" << endl;
            cout << "1 0" << endl;
        }
    }

    return 0;
}