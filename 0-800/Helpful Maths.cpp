#include <iostream>

using namespace std;

string arrange(string in)
{
    char tmp;
    int length = (int)in.size();
    bool finished = true;
    for(int i = 0; i < length; i+=2)
    {
        finished = true;
       for(int j = 0; j < length-2-i; j+=2)
       {
            if(in[j] > in[j+2])
            {
                // swap
                tmp = in[j];
                in[j] = in[j+2];
                in[j+2] = tmp;
                finished = false;
            }
       } 
       if(finished)
        break;
    }
    return in;
}

int main()
{
    string input;
    cin >> input;
    cout << arrange(input);
    return 0;
}
