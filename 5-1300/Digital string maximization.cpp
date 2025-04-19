#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    while (t--)
    {
        cin >> s;
        while (!s.empty())
        {
            int c = 0, index = 0;
            int biggest = s[0] - '0';
            while (biggest < 9 - c && c < s.size() - 1)
            {
                c++;
                if(s[c] - '0' - c > biggest){
                    biggest = s[c] - '0' - c;
                    index = c;
                }
            }
            cout << (char)(s[index] - index);
            s.erase(s.begin() + index);
        }
        cout << endl;
        
    }
    
}
