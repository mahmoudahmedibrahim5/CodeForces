#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int result;
    int firstOne, secondZero, secondOne;
    while (t--)
    {
        cin >> n;
        string s;
        cin >> s;
        result = n;
        firstOne = secondZero = secondOne = n;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1'){
                result++;
                firstOne = i;
                break;
            }
        }
        for(int i = firstOne; i < n; i++)
        {
            if(s[i] == '0'){
                result++;
                secondZero = i;
                break;
            }
        }
        for(int i = secondZero; i < n; i++)
        {
            if(s[i] == '1'){
                result++;
                secondOne = i;
                break;
            }
        }

        for(int i = secondOne; i < n - 1; i++)
        {
            if(s[i] != s[i + 1])
                result++;
        }

        // Case all ones
        if(secondZero == n && secondOne == n)
            cout << result << endl;
        else if(secondZero != n && secondOne == n)
            cout << result - 1 << endl;
        else 
            cout << result - 2 << endl;
    }
}
