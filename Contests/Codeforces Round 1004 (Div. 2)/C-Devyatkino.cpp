#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long uint64_t;
typedef long long sint64_t;

const uint64_t power10[] = {1, 10, 100, 1000, 10000,
                     100000, 1000000, 10000000, 100000000, 1000000000, 10000000000}; 
// n < 10^9
bool check(uint64_t n)
{
    for(int i = 0; i < 10; i++)
    {
        if(((n % power10[i + 1]) / power10[i]) == 7){
            //cout << "n = " << n << ", i = " << i << endl;
            return true;
        }
    }
    return false;
}

void testAnother(uint64_t increment, uint64_t n, int *min)
{
    uint64_t copy = n;
    int test = 0;
    while (test < *min && !check(copy))
    {
        copy += increment;
        test++;
    }
    
    if(test < *min){
        *min = test;
        //cout << copy << " " << *min << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    uint64_t n;
    int min;
    while (t--)
    {
        cin >> n;
        min = 1000;
        for(int i = 1; i < 11; i++){
            testAnother(power10[i] - 1, n, &min);
            if(min <= 1)
                break;
        }
        
        cout << min << endl;
    }
    return 0;
}
