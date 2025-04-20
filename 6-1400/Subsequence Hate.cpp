#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int zeros = 0, ones = 0, operationsCount = 0;
        int firstOne = -1;
        while (firstOne != s.size() - 1 && s[++firstOne] == '0');
        for(int i = firstOne; i < (int)s.size(); i++)
        {
            if(s[i] == '0')
            {
                zeros++;
                if(zeros > ones){
                    operationsCount += ones;
                    ones  = 0;
                    zeros = 0;
                    while (i != s.size() && s[i] == '0')
                        i++;
                    if(i != s.size())
                        ones++;
                }
            }
            else
                ones++;
        }
        operationsCount += zeros;
        int result = operationsCount;

        zeros = ones = operationsCount = 0;
        firstOne = s.size();
        while (firstOne != 0 && s[--firstOne] == '0');
        for(int i = firstOne; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                zeros++;
                if(zeros > ones){
                    operationsCount += ones;
                    ones  = 0;
                    zeros = 0;
                    while (i != -1 && s[i] == '0')
                        i--;
                    if(i != -1)
                        ones++;
                }
            }
            else
                ones++;
        }
        operationsCount += zeros;
        result = min(operationsCount, result);

        cout << result << endl;
    }
    
}

