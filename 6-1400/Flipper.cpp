#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int largestIndex = 0;

        vector<int> p(n);
        cin >> p[0];

        // If the largest number is at the start of the permutation
        if(p[0] == n)
        {
            for(int i = 1; i < n; i++){
                cin >> p[i];
                if(p[i] == n - 1)
                    largestIndex = i;
            }

            if(largestIndex == n - 1)
            {
                cout << p[n - 1] << " ";
                for(int i = 0; i < largestIndex; i++)
                    cout << p[i] << " ";
            }
            else
            {
                for(int i = largestIndex; i < n; i++)
                    cout << p[i] << " ";
                cout << p[largestIndex - 1] << " ";
                for(int i = 0; i < largestIndex - 1; i++)
                    cout << p[i] << " ";
            }
        }

        // If the largest number isn't at the start of the permutation
        else
        {
            for(int i = 1; i < n; i++){
                cin >> p[i];
                if(p[i] == n)
                    largestIndex = i;
            }

            // If the largest number is at the end of the permutation
            if(largestIndex == n - 1)
            {
                cout << p[n - 1] << " ";
                for(int i = largestIndex - 1; i >= 0; i--){
                    if(p[i] > p[0]){
                        cout << p[i] << " ";
                    }
                    else{
                        for(int j = 0; j <= i; j++)
                            cout << p[j] << " ";
                        break;
                    }
                }
            }

            // If the largest number isn't at the end of the permutation
            else
            {
                for(int i = largestIndex; i < n; i++)
                    cout << p[i] << " ";
                cout << p[largestIndex - 1] << " ";
                
                for(int i = largestIndex - 2; i >= 0; i--){
                    if(p[i] > p[0]){
                        cout << p[i] << " ";
                    }
                    else{
                        for(int j = 0; j <= i; j++)
                            cout << p[j] << " ";
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    
}
