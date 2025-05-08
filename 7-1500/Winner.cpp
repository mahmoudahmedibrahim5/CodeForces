#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, int64_t> playersScore;
    set <string> playersName; 

    vector<string> s(n);
    vector<int64_t> score(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> s[i] >> score[i];
        playersScore[s[i]] += score[i];
        playersName.insert(s[i]);
    }

    int64_t max = 0;
    for(auto player : playersName)
    {
        if(playersScore[player] > max)
            max = playersScore[player];
    }

    map <string, int64_t> playersScoreAgain;
    string winner;
    for(int i = 0; i < n; i++)
    {
        playersScoreAgain[s[i]] += score[i];
        if(playersScoreAgain[s[i]] >= max && playersScore[s[i]] == max)
        {
            cout << s[i] << endl;
            break;
        }
    }
}
