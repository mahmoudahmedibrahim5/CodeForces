#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    long long x, y;
    long long result;
    while (t--)
    {
        cin >> x >> y;
        for(long long i = 2; i <= 1000000000; i++)
        {
            result = i * y;
            if((result%x==0) && (result%y==0)){
                cout << result << endl;
                break;
            }
        }  
    }
    
}