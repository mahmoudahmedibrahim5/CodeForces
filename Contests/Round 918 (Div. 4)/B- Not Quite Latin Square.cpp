#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    bool found;
    bool A;
    bool B;
    bool C;

    string line;
    char result;
    while(t--)
    {
        found = false;
        for(int i = 0; i < 3; i++)
        {
            cin >> line;
            if(!found)
            {
                A = false;
                B = false;
                C = false;

                for(int j = 0; j < 3; j++)
                {
                    
                    if(line[j] == '?')
                        found = true;
                    else if(line[j] == 'A')
                        A = true;
                    else if(line[j] == 'B')
                        B = true;
                    else if(line[j] == 'C')
                        C = true;    
                }
                if(found){
                    if(A && B)
                        result = 'C';
                    else if(B && C)
                        result = 'A';
                    else if(A && C)
                        result = 'B';
                }
            }
        }
        cout << result << endl;
    }
}