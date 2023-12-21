#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    bool feasible;
    for(int i = 0; i < t; i++)
    {
        feasible = true;
        cin >> n;
        vector<string> mat(n);
        for(int j = 0; j < n; j++)
            cin >> mat[j];
        
        for(int j = 0; j < n - 1; j++)
        {
            for(int k = 0; k < n - 1; k++)
            {
                if(mat[j][k] == '1'){
                    if(mat[j+1][k] == '1' || mat[j][k+1] == '1')
                        continue;
                    else{
                        feasible = false;
                        break;
                    }
                }
            }
            if(!feasible)
                break;
        }
        if(feasible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
