#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m;
    string result;
    while (t--)
    {
        cin >> n >> m;

        if(m > n)
            result = "NO";
        else if(m == n)
            result = "YES";
        else
        {
            result = "NO";
            int level = 1;
            bool found;
            while (n % 3 == 0)
            {
                n /= 3;
                found = false;
                for(int i = 0; i <= level; i++){
                    if(m == n * pow(2, i)){
                        found = true;
                        result = "YES";
                        break;
                    }
                }
                level++;
                if(found)
                    break;
            }
        }
        cout << result << endl;
    }
    
}
