#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool mirror[26] = 
{
    1, // A
    0, // B
    0, // C
    0, // D
    0, // E
    0, // F
    0, // G
    1, // H
    1, // I
    0, // J
    0, // K
    0, // L
    1, // M
    0, // N
    1, // O
    0, // P
    0, // Q
    0, // R
    0, // S
    1, // T
    1, // U
    1, // V
    1, // W
    1, // X
    1, // Y
    0 // Z
};

int main()
{
    string input;
    cin >> input;
    int len = input.length();
    bool success = true;
    for(int i = 0; i < len / 2; i++)
    {
        if(!mirror[input[i] - 'A'] || input[i] != input[len - 1 - i]){
            success = false;
            break;
        }
    }

    if(!success)
        cout << "NO" << endl;
    else if(len % 2 == 0)
        cout << "YES" << endl;
    else if(mirror[input[len / 2] - 'A'])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
