#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> countElements(vector<int> arr);
int findBestSolution(vector<pair<int, int>> count);

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    /* Count Elements */
    vector<pair<int, int>> count = countElements(arr);

    cout << findBestSolution(count);
}

vector<pair<int, int>> countElements(vector<int> arr)
{
    vector<pair<int, int>> result;
    pair<int, int> element;

    sort(arr.begin(), arr.end());
    
    element.first = arr[0];
    element.second = arr[0];
    for(int i = 1; i < (int)arr.size(); i++)
    {
        if(arr[i] == arr[i-1])
            element.second += arr[i];
        else{
            result.push_back(element);
            element.first = arr[i];
            element.second = arr[i];
        }
    }
    result.push_back(element);

    return result;
}

int findBestSolution(vector<pair<int, int>> count)
{
    if(count.size() == 0)
        return 0;
    else if(count.size() == 1)
        return count[0].second;
    else
    {
        vector<pair<int, int>> countCopy;
        countCopy = count;
        // take first
        int r1 = count[0].second;
        if(count[0].first == count[1].first - 1)
            count.erase(count.begin() + 1);
        count.erase(count.begin() + 0);
        r1 += findBestSolution(count);
        // take second
        int r2 = countCopy[1].second;
        if(countCopy.size() >= 2 && countCopy[1].first == countCopy[2].first - 1)
            countCopy.erase(countCopy.begin() + 2);
        if(countCopy[0].first == countCopy[1].first - 1){
            countCopy.erase(countCopy.begin() + 1);
            countCopy.erase(countCopy.begin() + 0);
        }
        else{
            countCopy.erase(countCopy.begin() + 1);
        }
        r2 += findBestSolution(countCopy);

        if(r1 > r2)
            return r1;
        else
            return r2;
    }
}
