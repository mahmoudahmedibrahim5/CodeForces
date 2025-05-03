#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int length = input.size();

    int firstSmallLetter = length;
    int lastCapitalLetter = 0;
    for(int i = 0; i < length; i++)
    {
        if(input[i] <= 'z' && input[i] >= 'a'){
            firstSmallLetter = i;
            break;
        }
    }

    for(int i = firstSmallLetter + 1; i < length; i++)
    {
        if(input[i] <= 'Z' && input[i] >= 'A')
            lastCapitalLetter = i;
    }

    int small = 0, capital = 0;
    int result = 0;
    for(int i = lastCapitalLetter; i >= firstSmallLetter; i--)
    {
        if(input[i] <= 'Z' && input[i] >= 'A')
        {
            if(small > capital){
                result += capital;
                small = capital = 0;
            }
            capital++;
        }
        else
            small++;
    }
    if(small > capital)
        result += capital;
    else
        result += small;

    cout << result << endl;
}
