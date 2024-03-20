#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int a, b;
    int Qa, Qb;
    int Ka, Kb;
    int result;
    
    while (t--)
    {
        cin >> a >> b;
        cin >> Qa >> Qb;
        cin >> Ka >> Kb;
        result = 0;
        int possibleKingCoordinates[8][2] = {
                                            {Ka + a, Kb + b}, {Ka + b, Kb + a},
                                            {Ka + a, Kb - b}, {Ka + b, Kb - a},
                                            {Ka - a, Kb + b}, {Ka - b, Kb + a},
                                            {Ka - a, Kb - b}, {Ka - b, Kb - a} };
        int possibleQueenCoordinates[8][2] = {
                                            {Qa + a, Qb + b}, {Qa + b, Qb + a},
                                            {Qa + a, Qb - b}, {Qa + b, Qb - a},
                                            {Qa - a, Qb + b}, {Qa - b, Qb + a},
                                            {Qa - a, Qb - b}, {Qa - b, Qb - a} };
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(possibleKingCoordinates[i][0] == possibleQueenCoordinates[j][0]
                && possibleKingCoordinates[i][1] == possibleQueenCoordinates[j][1])
                    result++;
            }
        }
        if(a == b)
            result /= 4;
        
        cout << result << endl;
    }
    
    return 0;
}
