#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int alpha[26];
    int n;
    int index;
    int trace;
    while(t--)
    {
        cin >> n;
        string original;
        index = 0;
        for(int i = 0; i < n; i++){
            cin >> trace;
            if(trace == 0){
                original.push_back('a' +  index);
                alpha[index] = 1;
                index++;
            }
            else{
                for(int j = 0; j < 26; j++)
                {
                    if(alpha[j] == trace){
                        original.push_back('a' + j);
                        alpha[j]++;
                        break;
                    }
                }
            }
            
        }
        cout << original << endl; 
    }
    
    return 0;
}
