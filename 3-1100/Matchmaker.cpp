#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> markers;
    vector<pair<int, int>> caps;
    
    pair <int, int> e;
    for(int i = 0; i < n; i++){
        cin >> e.second >> e.first;
        markers.push_back(e);
    }
    for(int i = 0; i < m; i++){
        cin >> e.second >> e.first;
        caps.push_back(e);
    }

    sort(markers.begin(), markers.end());
    sort(caps.begin(), caps.end());

    int max = 0, beautiful = 0;

    int caps_index = 0, markers_index = 0;
    while(caps_index < m && markers_index < n)
    {
        if(markers[markers_index].first == caps[caps_index].first){
            max++;
            caps_index++;
            markers_index++;
        }
        else if(markers[markers_index].first > caps[caps_index].first){
            caps_index++;
        }
        else if(markers[markers_index].first < caps[caps_index].first){
            markers_index++;
        }
    }

    int start = 0;
    bool first;
    for(int i = 0; i < n; i++)
    {
        first = true;
        for(int j = start; j < m; j++)
        {
            if(markers[i].first == caps[j].first)
            {
                if(first){
                    start = j;
                    first = false;
                }
                if(markers[i].second == caps[j].second){
                    beautiful++;
                    caps.erase(caps.begin() + j);
                    m--;
                    break;
                }
            }
            else if(markers[i].first < caps[j].first)
                break;
        }
    }
    cout << max << " " << beautiful << endl;
}
