#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string a, b, c;
    int result;
    while (t--)
    {
        result = 0;
        int alpha[26] = {0, 0, 0, 0, 0, 0, 0, 0, 
                        0, 0, 0, 0, 0, 0, 0, 0, 
                        0, 0, 0, 0, 0, 0, 0, 0, 
                        0, 0};
        cin >> a >> b >> c;
        
        for(int i = 0; i < a.size(); i++)
            alpha[a[i] - 'a']++;

        for(int i = 0; i < b.size(); i++)
            alpha[b[i] - 'a']++;

        for(int i = 0; i < c.size(); i++)
        {
            alpha[c[i] - 'a']--;
            if(alpha[c[i] - 'a'] < 0)
                result++;
        }

        cout << result << endl;
    }
    
}
