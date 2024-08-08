#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    int sx, sy, ex, ey;

    cin >> t >> sx >> sy >> ex >> ey;
    int east, north; 
    east = ex - sx;
    north = ey - sy;

    bool acheive = false;
    
    string wind;
    cin >> wind;
    for(int i = 0; i < t; i++)
    {
        switch (wind[i])
        {
        case 'E':
            if(east > 0)
                east--;
            break;
        case 'W':
            if(east < 0)
                east++;
            break;
        case 'N':
            if(north > 0)
                north--;
            break;
        case 'S':
            if(north < 0)
                north++;
            break;
        default:
            break;
        }
        if(east == 0 && north == 0){
            cout << i + 1 << endl;
            acheive = true;
            break;
        }
    }

    if(!acheive)
        cout << "-1" << endl;

}
