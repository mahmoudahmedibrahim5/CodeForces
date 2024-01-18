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
    int inc;
    int elem;
    while (t--)
    {
        vector<int> result;
        cin >> n;
        elem = 0;
        inc = 1;
        n -= 2;
        result.push_back(-1);
        while (n)
        {
            if(n > inc){
                result.push_back(elem++);
                inc++;
            }
            else if(n > 2){
                result.push_back(-1);
                inc = 1;
            }
            n -= inc;
        }
        
    }

    return 0;
}