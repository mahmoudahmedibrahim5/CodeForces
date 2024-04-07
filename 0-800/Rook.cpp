#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    char columns[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    string square;
    char copy[2];
    while (t--)
    {
        cin >> square;
        copy[0] = square[0];
        copy[1] = square[1];

        for(int i = 0; i < 8; i++){
            if(columns[i] == copy[0])
                continue;
            square[0] = columns[i];
            cout << square << endl;
        }

        square[0] = copy[0];
        for(int i = 1; i <= 8; i++){
            if((i + '0') == copy[1])
                continue;
            square[1] = '0' + i;
            cout << square << endl;
        }
    }
    
}
