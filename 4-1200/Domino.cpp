#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> lower(n);
    int lowerSum = 0;
    vector<int> upper(n);
    int upperSum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> lower[i] >> upper[i];
        lowerSum += lower[i];
        upperSum += upper[i];
    }

    bool lowerEven = (lowerSum%2==0)?true:false;
    bool upperEven = (upperSum%2==0)?true:false;

    int result;
    if(lowerEven && upperEven)
        result = 0;
    else if((!lowerEven) && (!upperEven)){
        result = -1;
        for(int i = 0; i < n; i++){
            if( (lower[i]%2==0 && upper[i]%2!=0) || (lower[i]%2!=0 && upper[i]%2==0) ){
                result = 1;
                break;
            }
        }
    }
    else
        result = -1;
    
    cout << result << endl;

    return 0;
}
