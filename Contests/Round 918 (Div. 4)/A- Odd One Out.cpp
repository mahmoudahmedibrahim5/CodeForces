#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int a, b, c;
    int result; 
    while(t--)
    {
        cin >> a >> b >> c;
        if(a == b)
            result = c;
        else if(b == c)
            result = a;
        else if(a == c)
            result = b;
        cout << result << endl;
    }

}
