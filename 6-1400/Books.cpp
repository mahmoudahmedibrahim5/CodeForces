#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> books(n);
    for(int i = 0; i < n; i++)
        cin >> books[i];

    int result = 0, max = 0;
    int start, end;
    for(int i = 0; i < n; i++){
        if(books[i] <= t){
            start = end = i;
            result = 1;
            max = 1;
            break;
        }
    }

    if(result != 0)
    {
        int total = books[start];
        while(end != n - 1)
        {
            end++;
            if((total + books[end]) <= t)
            {
                result++;
                total += books[end];
            }
            else if(start == end)
            {
                total = 0;
                start++;
                result = 0;
            }
            else
            {
                end--;
                total -= books[start];
                start++;
                result--;
            }
            if(result > max)
                max = result;
        }
    }

    cout << max << endl;
}
