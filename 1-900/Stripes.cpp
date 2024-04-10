#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    char grid[8][8];
    bool red;
    while (t--)
    {
        for(int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> grid[i][j];
        
        for(int i = 0; i < 8; i++)
        {
            red = true;
            for (int j = 0; j < 8; j++)
            {
                if(grid[i][j] != 'R'){
                    red = false;
                    break;
                }
            } 
            if(red)
                break;
        }
        if(red)
            cout << "R" << endl;
        else
            cout << "B" << endl;
    }
    
}
