#include <iostream>

using namespace std;

int main()
{
    int mat[5][5];
    int x, y;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                x = i; 
                y = j;
            }
        }
    }
    int result = abs(x-2) + abs(y-2);
    cout << result << endl;
    return 0;
}
