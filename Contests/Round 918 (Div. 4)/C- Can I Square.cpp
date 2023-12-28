#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    int element;
    long long total;
    double sq;
    while(t--)
    {
        total = 0;
        cin >> n; 
        for(int i = 0; i < n; i++)
        {
            cin >> element;
            total += element;
        }
        sq = sqrt(total);
        //cout << sq << " != " << (int)sq << endl;
        if(sq == (int)sq && (pow((int)sq, 2) == total))    
            cout << "YES" << endl;
        else
            cout << "NO" << endl;          
    }
}
