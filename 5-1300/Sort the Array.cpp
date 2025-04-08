#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bool result = true;
    bool descending = false;
    int start = 1, end = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1] && !descending)
        {
            if(start == 1 && end == 1)
            {
                descending = true;
                start = i + 1;
            }
            else
            {
                result = false;
                break;
            }
        }
        else if(arr[i] < arr[i + 1] && descending){
            end = i + 1;
            descending = false;
            if(arr[start - 1] > arr[end] || (start > 1 && arr[start - 2] > arr[end - 1]))
            {
                result = false;
                break;
            }
        }
    }
    if(end == 1 && descending)
    {
        end = n;
        if(start > 1 && arr[start - 2] > arr[end - 1])
            result = false;
    }
    if(result)
        cout << "yes" << endl << start << " " << end << endl;
    else
        cout << "no" << endl;
}
