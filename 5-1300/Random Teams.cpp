#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

uint64_t calculateMin(int n, int m)
{
    uint64_t x = n / m;
    uint64_t y = x + 1;
    uint64_t yteams = (n % m);
    uint64_t xteams = m - yteams;
    
    return ((yteams) * (y * (y - 1)) / 2) + ((xteams) * (x * (x - 1)) / 2);
}

uint64_t calculateMax(int n, int m)
{
    n -= m;
    return ((1 + (uint64_t)n) * (uint64_t) n) / 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << calculateMin(n, m) << " " << calculateMax(n, m) << endl;
}
