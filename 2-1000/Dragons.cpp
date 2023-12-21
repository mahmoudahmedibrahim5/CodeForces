#include <iostream>
#include <vector>

using namespace std;

bool check(int s, vector<int> x, vector<int> y)
{
    int n = (int) x.size();
    bool died = false;
    if(n==0)
        return true;
    for(int i = 0; i < n; i++)
    {
        died = true;
        for(int j = 0; j < (int)x.size(); j++)
        {
            if(s > x[j]){
                died = false;
                x.erase(x.begin() + j);
                s += y[j];
                y.erase(y.begin() + j);   
            }
        }
        if(died)
            break;
    }

    if(x.size() > 0)
        return false;
    else
        return true;
}

int main()
{
    int s, n;
    cin >> s >> n;
    vector<int> x(n);
    vector<int> y(n);    
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    if(check(s, x, y))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;    
    return 0;
}
