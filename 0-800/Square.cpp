#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int coordinates[4][2];
    int x, y;
    while (t--)
    {
        for(int i = 0; i < 4; i++)
            cin >> coordinates[i][0] >> coordinates[i][1];
        
        if(coordinates[0][0] == coordinates[1][0])
            x = abs(coordinates[0][1] - coordinates[1][1]);
        else if(coordinates[0][0] == coordinates[2][0])
            x = abs(coordinates[0][1] - coordinates[2][1]);
        else if(coordinates[0][0] == coordinates[3][0])
            x = abs(coordinates[0][1] - coordinates[3][1]);

        if(coordinates[0][1] == coordinates[1][1])
            y = abs(coordinates[0][0] - coordinates[1][0]);
        else if(coordinates[0][1] == coordinates[2][1])
            y = abs(coordinates[0][0] - coordinates[2][0]);
        else if(coordinates[0][1] == coordinates[3][1])
            y = abs(coordinates[0][0] - coordinates[3][0]);

        cout << x * y << endl;
    }

    return 0;
}
