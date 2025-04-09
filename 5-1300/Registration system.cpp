#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    int n;
    cin >> n;

    map<string, int> arr;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(!arr[s])
            cout << "OK" << endl;
        else
            cout << s << arr[s] << endl;
        arr[s]++;
    }
}
