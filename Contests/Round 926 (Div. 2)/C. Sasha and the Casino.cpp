#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int k, x, a;
    int bet, totalBets;
    bool result;
    while (t--)
    {
        cin >> k >> x >> a;
        result = true;
        bet = 1;
        totalBets = 0;
        k--;
        for(int i = 0; i <= x; i++){
            totalBets += bet;
            if(a < bet){
                result = false;
                break;
            }
            else
                a -= bet;
            
            bet = (totalBets / k) + 1;
        }

        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
