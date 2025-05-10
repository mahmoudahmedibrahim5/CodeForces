#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    bool cat;
    vector<node*> connections;
    bool visited;
};

class Graph
{
public:
    node* elements;

    Graph(int n)
    {
        elements = new node[n];
    }

    void assignCatValue(int index, bool catValue)
    {
        elements[index].cat = catValue;
        elements[index].visited = false;
    }

    void connect(node* n1, node* n2)
    {
        n1->connections.push_back(n2);
        n2->connections.push_back(n1);
    }

    int DFS(node* root, int currentCats, int maxCats)
    {
        root->visited = true;
        if(root->cat)
            currentCats++;
        else
            currentCats = 0;

        if(currentCats == maxCats + 1)
            return 0;
        if(root->connections.size() == 1 && root != &elements[0])
            return 1;

        int count = 0;
        for(int i = 0; i < root->connections.size(); i++)
        {
            if(!root->connections[i]->visited)
                count += DFS(root->connections[i], currentCats, maxCats);
        }
        return count;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Graph tree{n};

    bool catValue;
    for(int i = 0; i < n; i++){
        cin >> catValue;
        tree.assignCatValue(i, catValue);
    }

    int x, y;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        tree.connect(&tree.elements[x - 1], &tree.elements[y - 1]);
    }

    int result = tree.DFS(&tree.elements[0], 0, m);
    cout << result << endl;
}
