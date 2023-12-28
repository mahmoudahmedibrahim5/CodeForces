#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    string input;

    while(t--)
    {
        cin >> n;
        cin >> input;

        string result;
        for(int i = 0; i < n - 2; i++)
        {
            result.push_back(input[i]);
            if(input[i] == 'a' || input[i] == 'e'){
                if(input[i + 2] == 'a' || input[i + 2] == 'e'){
                    result.push_back('.');
                }
                else{
                    result.push_back(input[i + 1]);
                    result.push_back('.');
                    i++;
                }
            }
        }
        result.push_back(input[n - 2]);
        result.push_back(input[n - 1]);

        cout << result << endl;
    }

}