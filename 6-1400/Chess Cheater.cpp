#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, k;
    int result;
    int firstWin, lastWin;
    while (t--)
    {
        cin >> n >> k;
        string s;
        cin >> s;
        result = 0;
        firstWin = n;
        map<int, int> streaks;
        int totalStreaks = 0;

        /* Find first win */
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'W'){
                result++;
                firstWin = i;
                lastWin = i;
                break;
            }
        }

        // If all loss
        if(firstWin == n){
            if(k > 0)
                cout << 2 * k - 1 << endl;
            else
                cout << 0 << endl;
            continue;
        }

        /* Find wins and loss streaks */
        bool lossStreak = false;
        int length = 0;
        for(int i = firstWin + 1; i < n; i++)
        {
            if(s[i] == 'W')
            {
                lastWin = i;
                result++;
                if(s[i - 1] == 'W')
                    result++;
                if(lossStreak)
                {
                    streaks[length]++;
                    totalStreaks++;
                    length = 0;
                    lossStreak = false;
                }
            }
            else
            {
                length++;
                lossStreak = true;
            }
        }

        /* Find the result after converting streaks */
        int c = 1;
        while (k > 0 && totalStreaks > 0)
        {
            if(k >= (streaks[c] * c))
            {
                result += ((2 * streaks[c] * c) + streaks[c]);
                k -= (streaks[c] * c);
                totalStreaks -= streaks[c];
            }
            else
            {
                int q = k / c;
                result += ((2 * q * c) + q);
                k -= (q * c);
                result += (2 * k);
                k = 0;
            }
            c++;
        }
        
        // If still some changes and streaks finished
        if(k > 0)
        {
            if(k <= (firstWin + (n - lastWin - 1)))
                result += (2 * k);
            else
                result = 2 * n - 1;
        }

        cout << result << endl;
    }
    
}
