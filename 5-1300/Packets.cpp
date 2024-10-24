#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = (int)floor(log2((double)n));
    cout << ++result << endl;
}
