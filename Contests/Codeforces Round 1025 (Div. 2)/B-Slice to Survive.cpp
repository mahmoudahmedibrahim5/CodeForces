#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

#define USE_GRAPH       false
#define USE_ORDERED_SET false

#if GRAPH
    struct node{
        int element;
        bool visited = false;
        vector<node*> children;
    };

    class Graph
    {
    public:
        vector<node> elements;
        Graph(int n) : elements(n) {}

        void connect(node* n1, node* n2)
        {
            n1->children.push_back(n2);
            n2->children.push_back(n1);
        }

        void DFS()
        {

        }
    };
#endif

#if ORDERED_SET
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag,
     __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#endif

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int result1 = 1;
    int result2 = 1;

    int nearest1 = min(a, n - a + 1);
    int nearest2 = min(b, (m - b + 1));
    
    result1 += ((int) (ceil( log2((double)nearest1)) ) );
    result1 += ((int) (ceil( log2((double)m)) ) );

    result2 += ((int) (ceil( log2((double)nearest2)) ) );
    result2 += ((int) (ceil( log2((double)n)) ) );

    cout << min(result1, result2) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
