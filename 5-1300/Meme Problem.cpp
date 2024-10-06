#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;

    double n;
    double quotient;
    double x, y;
    while (t--)
    {
        cin >> n;
        quotient = (n * n) - (4 * n);
        if(quotient >= 0)
        {
            x = (n + sqrt(quotient)) / 2;
            y = n - x;
            //printf("Y %lf %lf\n", x, y);
            cout << "Y " << setprecision(15) << x << " " << y << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    
}
