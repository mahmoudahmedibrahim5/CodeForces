#include <iostream>
#include <vector>

using namespace std;

#define MEMOIZE     1

#if MEMOIZE
vector<vector<int>> mem;
#endif
int bestOperation(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(n%2 != 0)
        return 1;
    
    #if MEMOIZE
    for(int i = 0; i < (int)mem.size(); i++)
    {
        if(n == mem[i][0])
            return mem[i][1];
    }
    #endif


    vector<int> count;
    int index = 0;
    for(int j = 3; j <= n/2; j+=2){
        if((n%j)==0){
            count.push_back(j);
            count[index] = bestOperation(n/count[index]);
            if(count[index] %2 == 0){
                #if MEMOIZE
                vector<int> memoize(2);
                memoize[0] = n;
                memoize[1] = count[index] + 1;
                mem.push_back(memoize);
                #endif
                return count[index] + 1;
            }
            index++;
        }
    }
    
    if((int)count.size() > 0){
        #if MEMOIZE
        vector<int> memoize(2);
        memoize[0] = n;
        memoize[1] = count[0] + 1;
        mem.push_back(memoize);
        #endif
        return count[0] + 1;
    }
    else{
        return 2;
    }
        
}

int main()
{
    int t;
    cin >> t;
    int n;

    while(t--)
    {
        cin >> n;
        int best = bestOperation(n);
        if(best%2 == 0)
            cout << "FastestFinger" << endl;
        else
            cout << "Ashishgup" << endl;
    }

    return 0;
}
