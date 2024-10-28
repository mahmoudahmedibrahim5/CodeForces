#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string result = "";
    if(n > (m + 1) || m > (2 * (n + 1)))
        result = "-1";
    else if(n == m + 1){
        for(int i = 0; i < m; i++)
            result += "01";
        result += '0';
    }
    else if(n == m){
        for(int i = 0; i < n; i++)
            result += "01";
    }
    else if(m == (2 * (n + 1))){
        for(int i = 0; i < n; i++)
            result += "110";
        result += "11";
    }
    else if(m < (2 * (n + 1))){
        while(m > n + 1){
            result += "110";
            m -= 2;
            n--;
        }
        if(m == n + 1)
            result += '1';
        for(int i = 0; i < n; i++)
            result += "01";
    }
    cout << result << endl;
}
