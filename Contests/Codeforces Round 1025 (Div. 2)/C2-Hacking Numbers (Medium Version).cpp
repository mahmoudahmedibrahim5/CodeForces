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
    int n;
    cin >> n;
    int tmp;

    cout << "mul 9" << endl;
    cin >> tmp;

    cout << "digit" << endl;
    cin >> tmp;

    cout << "digit" << endl;
    cin >> tmp;

    cout << "add " << n - 9 << endl;
    cin >> tmp;

    cout << "!" << endl;
    cin >> tmp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
