#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool FastestFingerWin(int n)
{
    if(n == 1)
        return true;
    if(n == 2)
        return false;
    if(n%2 != 0)
        return false;

    bool found = false;
    bool prime = true;
    int pr = n/2;
    int sq = sqrt(pr);

    for(int j = 3; j <= n/3; j+=2){
        if((!found) && ((n%j)==0)){
            found = true;
            if(n%4 == 0)
                return false;
        }
        if((prime) && (j<=sq) && (pr%j==0)){
            prime = false;
            break;
        }
    }
    
    if(found && (!prime))
        return false;
    else
        return true;
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
