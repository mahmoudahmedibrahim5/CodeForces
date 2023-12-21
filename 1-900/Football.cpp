#include <iostream>

using namespace std;

bool check(string in)
{
    bool dangerous = false;
    int length = (int)in.size();
    int correspondingPlayers = 1;
    for(int i = 0; i < length-1; i++)
    {
        if(in[i] == in[i+1])
            correspondingPlayers++;
        else
            correspondingPlayers = 1;
        if(correspondingPlayers == 7){
            dangerous = true;
            break;
        }
    }
    return dangerous;
}

int main()
{
    string input;
    cin >> input;
    if(check(input))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
