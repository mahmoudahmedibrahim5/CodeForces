#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void removeOddIndicies(vector<int>* arr, long long* score);

int main()
{
    int t;
    cin >> t;

    int n;
    long long score;
    int element;

    while (t--)
    {
        cin >> n;
        score = 0;
        vector<int> arr;
        for(int i = 0; i < n; i++){
            cin >> element;
            arr.push_back(element);
        }

        // Collect odd indicies
        removeOddIndicies(&arr, &score);

        // Check if there are positives in even
        int firstPositiveIndex;
        bool even = false;
        int size = arr.size();
        
        for(int i = 1; i < size; i+=2){
            if(arr[i] > 0){
                even = true;
                firstPositiveIndex = i;
                break;
            }
        }

        if(even)
        {
            // Choose which index to remove
            if(firstPositiveIndex == 1 && arr[0] + arr[1] > 0){
                score += arr[0];
                arr.erase(arr.begin() + 0);
            }
            else{
                arr.erase(arr.begin() + 1);
            }
            removeOddIndicies(&arr, &score);
        }
            
        cout << score << endl;
    }
    
    return 0;
}

void removeOddIndicies(vector<int>* arr, long long* score)
{
    int n = arr->size();
    bool positiveFound;
    int start;
    for(int i = 0; i < n; i++)
    {
        positiveFound = false;
        start = (int)arr->size();
        if(start % 2 == 0)
            start -= 2;
        else
            start -= 1; 
        for(int j = start; j >= 0; j-=2)
        {
            if(j%2 == 0 && arr->at(j) > 0){
                *score += arr->at(j);
                arr->erase(arr->begin() + j);
                positiveFound = true;
                break;
            }
        }
        if(positiveFound == false)
            break;
    }
}
