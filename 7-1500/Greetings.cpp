#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int main()
{
    int t;
    cin >> t;
    
    int n;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        sort(arr.begin(), arr.end());

        ordered_set st;
        uint64_t result = 0;
        for(int i = 0; i < n; i++)
        {
            result += st.order_of_key(arr[i].second);
            st.insert(arr[i].second);
        }

        cout << result << endl;
    }
}

