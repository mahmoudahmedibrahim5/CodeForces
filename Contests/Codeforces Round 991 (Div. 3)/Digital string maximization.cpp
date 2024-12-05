#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    int n;
    int bigger, index, prevIndex;
    while (t--)
    {
        cin >> s;
        n = s.size();
        vector<int> arr(n);

        for(int i = 0; i < n; i++)
        {
            arr[i] = s[i] - '0' - i;
        }

        prevIndex = n;
        for(int i = 0; i < n; i++)
        {
            bigger = -n;
            for(int j = 0; j < arr.size(); j++)
            {
                if(j >= prevIndex)
                    arr[j]++;
                if(arr[j] > bigger){
                    bigger = arr[j];
                    index = j;
                }
            }
            cout << arr[index];
            arr.erase(arr.begin() + index);
            prevIndex = index;
        }
        cout << endl;
    }
    
}
