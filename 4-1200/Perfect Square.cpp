#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findDifferences(char c1, char c2, char c3, char c4)
{
    if(c1 >= c2 && c1 >= c3 && c1 >= c4)
        return (int)((c1 - c2) + (c1 - c3) + (c1 - c4));
    if(c2 >= c1 && c2 >= c3 && c2 >= c4)
        return (int)((c2 - c1) + (c2 - c3) + (c2 - c4));
    if(c3 >= c2 && c3 >= c1 && c3 >= c4)
        return (int)((c3 - c2) + (c3 - c1) + (c3 - c4));
    if(c4 >= c2 && c4 >= c3 && c4 >= c1)
        return (int)((c4 - c2) + (c4 - c3) + (c4 - c1));
}

int main()
{
    int t;
    cin >> t;

    int n;
    char element;
    int result;
    while (t--)
    {
        cin >> n;
        vector<vector<char>> mat(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> element;
                mat[i].push_back(element);
            }
        
        result = 0;
        for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < n / 2; j++)
                result += findDifferences(mat[i][j], mat[j][(n-1) - i], mat[(n-1) - i][(n-1) - j], mat[(n-1) - j][i]);
        
        cout << result << endl;
    }
    

    return 0;
}
