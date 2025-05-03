#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> towers(n);
 
    int average = 0;
    for(int i = 0; i < n; i++){
        cin >> towers[i].first;
        average += towers[i].first;
        towers[i].second = i + 1;
    }
    bool isInteger = (average % n == 0);
    average /= n;
    
    sort(towers.begin(), towers.end());
 
    int biggerIndex = n - 1, smallerIndex = 0;
 
    vector<pair<int, int>> result;
    pair<int, int> element;
 
    while (k--)
    {
        if((towers[n - 1].first - towers[0].first) <= 1)
            break;
        if(towers[smallerIndex].first == average)
            smallerIndex = 0;
        if(towers[biggerIndex].first == average)
            biggerIndex = n - 1;


        while(towers[smallerIndex].first == towers[smallerIndex + 1].first)
            smallerIndex++;
        while(towers[biggerIndex].first == towers[biggerIndex - 1].first)
            biggerIndex--;

        element.first = towers[biggerIndex].second;
        element.second = towers[smallerIndex].second;
        result.push_back(element);
 
        towers[smallerIndex].first++;
        if(smallerIndex > 0)
            smallerIndex--;

        towers[biggerIndex].first--;
        if(biggerIndex < n - 1)
            biggerIndex++;
    }
    
    cout << towers[n - 1].first - towers[0].first << " " << result.size() << endl;
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i].first << " " << result[i].second << endl;
}
