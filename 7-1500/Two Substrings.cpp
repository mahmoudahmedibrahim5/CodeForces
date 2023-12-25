#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    bool AB = false;
    bool BA = false;
    bool one = false;
    string result = "NO";
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == 'A' && s[i+1] == 'B'){
            if((i < n - 2) && s[i+2] == 'A'){
                if(one || AB || BA){
                    result = "YES";
                    break;
                }
                else{
                    one = true;
                }
                i++;
            }
            else{
                if(one || BA){
                    result = "YES";
                    break;
                }
                else{
                    AB = true;
                }
            }
            i++;
        }
        else if(s[i] == 'B' && s[i+1] == 'A'){
            if((i < n - 2) && s[i+2] == 'B'){
                if(one || AB || BA){
                    result = "YES";
                    break;
                }
                else{
                    one = true;
                }
                i++;
            }
            else{
                if(one || AB){
                    result = "YES";
                    break;
                }
                else{
                    BA = true;
                }
            }
            i++;
        }
    }
    cout << result << endl;
    return 0;
}
