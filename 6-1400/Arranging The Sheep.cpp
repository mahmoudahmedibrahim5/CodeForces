#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    string s;

    int sheepsCount, middleIndex, destinationIndex;
    uint64_t result;
    while (t--)
    {
        cin >> n;
        cin >> s;

        /* Count the sheeps */
        sheepsCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
                sheepsCount++;
        }
        
        /* Find the middle sheep */
        middleIndex = -1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
                middleIndex++;
            if(middleIndex == sheepsCount / 2){
                middleIndex = i;
                break;
            }
        }

        /* Count the minimum moves */
        result = 0;

        // Before middle index
        destinationIndex = middleIndex - 1; 
        for(int i = middleIndex - 1; i >= 0; i--)
        {
            if(s[i] == '*')
            {
                result += (destinationIndex - i);
                destinationIndex--;
            }
        }

        // After middle index
        destinationIndex = middleIndex + 1;
        for(int i = middleIndex + 1; i < n; i++)
        {
            if(s[i] == '*')
            {
                result += (i - destinationIndex);
                destinationIndex++;
            }
        }

        cout << result << endl;
    }
    
}
