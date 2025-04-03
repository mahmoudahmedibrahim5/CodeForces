#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/* The number will be only T-prime if and only if its square root equal prime number 
 * So, We will create a set of T-Prime numbers less than or equal 10^12, 
 * which is square the set of prime numbers less than or equal 10^6 
 * We will use Sieve of Eratosthenes algorithm
*/
#define MAX     1e6 + 1

int main()
{
    static vector<bool> t_prime(MAX);
    t_prime[0] = true;
    t_prime[1] = true;

    int c = 2;
    while (c * c < MAX)
    {
        for(int i = 2 * c; i < MAX; i += c)
            t_prime[i] = true;
            
        for(int i = c + 1; i < MAX; i++)
        {
            if(!t_prime[i]){
                c = i;
                break;
            }
        }
    }

    int n;
    cin >> n;
    
    vector<uint64_t> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++)
    {
        if(sqrt(arr[i]) - (int)sqrt(arr[i]) == 0 && !t_prime[(int)sqrt(arr[i])])
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;
    }
    
}
