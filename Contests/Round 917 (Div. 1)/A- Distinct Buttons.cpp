#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    vector<int> coordinates(2);
    bool first = false;
    bool second = false;
    bool third = false;
    bool fourth = false;
    bool positiveX = false;
    bool positiveY = false;
    bool negativeX = false;
    bool negativeY = false;

    while (t--)
    {
        cin >> n;
        first = false;
        second = false;
        third = false;
        fourth = false;
        positiveX = false;
        positiveY = false;
        negativeX = false;
        negativeY = false;

        for(int i = 0; i < n; i++){
            cin >> coordinates[0] >> coordinates[1];
            if(coordinates[0] > 0 && coordinates[1] > 0)
                first = true;
            else if(coordinates[0] < 0 && coordinates[1] > 0)
                second = true;
            else if(coordinates[0] < 0 && coordinates[1] < 0)
                third = true;
            else if(coordinates[0] > 0 && coordinates[1] < 0)
                fourth = true;
            else if(coordinates[0] == 0 && coordinates[1] > 0)
                positiveY = true;
            else if(coordinates[0] == 0 && coordinates[1] < 0)
                negativeY = true;
            else if(coordinates[0] < 0 && coordinates[1] == 0)
                negativeX = true;
            else if(coordinates[0] > 0 && coordinates[1] == 0)
                positiveX = true;
        }
        bool result = true;
        if(
            (first && third) || (second && fourth) 
        
        || (first && second && negativeY) || (second && third && positiveX) 
        || (third && fourth && positiveY) || (fourth && first && negativeX) 
        
        || (negativeX && negativeY && positiveX && positiveY) 

        || (negativeX && negativeY && positiveX && first) 
        || (negativeX && negativeY && positiveX && second) 

        || (negativeX && positiveY && positiveX && third) 
        || (negativeX && positiveY && positiveX && fourth) 

        || (negativeX && positiveY && negativeY && first) 
        || (negativeX && positiveY && negativeY && fourth) 

        || (positiveX && positiveY && negativeY && second) 
        || (positiveX && positiveY && negativeY && third)
        
        || (positiveX && positiveY && third) || (positiveY && negativeX && fourth)
        || (negativeX && negativeY && first) || (negativeY && positiveX && second)
        )
            result = false;

        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
