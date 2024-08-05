#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m, tmp;
    cin >> n;
    vector<int> piles(n);
    
    /* Input the piles and store the end number of each pile in the vector */
    int buffer = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        buffer += tmp;
        piles[i] = buffer;
    }

    /* Input the juicy worms */
    cin >> m;
    vector<int> juicy(m);
    for(int i = 0; i < m; i++)
        cin >> juicy[i];

    /* For Each juicy worm */
    for(int i = 0; i < m; i++)
    {
        /* Binary Search */
        int start = 0;
        int end = n - 1;
        int element;
        for(int j = 0; j < n; j++)
        {
            element = (start + end) / 2;

            /* If reaching the boundaries */
            if(element == 0){
                if(juicy[i] > piles[0])
                    cout << 2 << endl;
                else
                    cout << 1 << endl;
                break;
            }
            if(element == n - 2 && juicy[i] > piles[n - 2]){
                cout << n << endl;
                break;
            }

            /* Update the start or end */
            if(juicy[i] > piles[element])
                start = element;
            else if(juicy[i] <= piles[element - 1])
                end = element;
            else{
                cout << element + 1 << endl;
                break;
            }
                
        }
    }
}
