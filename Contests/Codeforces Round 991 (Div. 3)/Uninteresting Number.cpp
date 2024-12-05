#include <iostream> 
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    int n, sum;
    int two, three;
    while (t--)
    {
        cin >> s;
        n = s.size();
        two = 0;
        three = 0;
        sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += s[i] - '0';
            if(s[i] == '2')
                two++;
            else if(s[i] == '3')
                three++;
        }

        if(sum % 9 == 0)
            cout << "YES" << endl;
        else
        {
            int x = (sum / 9) + 1;
            x *= 9;
            if((x - sum) % 2 != 0)
                x += 9;

            int diff = x - sum;

            if(diff / 6 > three)
                diff -= (three * 6);
            else
                diff %= 6;

            if(diff / 2 > two)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    
}
