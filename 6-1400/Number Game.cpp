#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool FastestFingerWin(int n)
{
    if(n == 1)
        return true;
    if(n == 2 || n % 2 != 0)
        return false;
    
    if((n / 2) % 2 != 0)
        return isPrime(n / 2);
    else if(log2((double)n) == (double)(int)log2((double)n))
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    int n;

    while(t--)
    {
        cin >> n;
        bool check = FastestFingerWin(n);
        if(check)
            cout << "FastestFinger" << endl;
        else
            cout << "Ashishgup" << endl;
    }

    return 0;
}
