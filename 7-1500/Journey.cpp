#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

struct node{
    bool visited = false;
    vector<node*> children;
};

class Graph
{
public:
    node* elements;
    Graph(int n)
    {
        elements = new node[n];
    }

    void connect(node* n1, node* n2)
    {
        n1->children.push_back(n2);
        n2->children.push_back(n1);
    }

    double expectedLength(node* root, double length)
    {
        root->visited = true;
        
        double feasibleCities = 0;
        for(int i = 0; i < root->children.size(); i++)
        {
            if(!root->children[i]->visited)
                feasibleCities++;
        }
        if(!feasibleCities)
            return length;
        

        double result = 0;
        for(int i = 0; i < root->children.size(); i++)
        {
            if(!root->children[i]->visited)
                result += ((1.0 / feasibleCities) * expectedLength(root->children[i], length + 1));
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;

    Graph journey{n};
    int x, y;
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        journey.connect(&journey.elements[x - 1], &journey.elements[y - 1]);
    }

    //cout << journey.expectedLength(&journey.elements[0], 0) << endl;
    printf("%lf\n", journey.expectedLength(&journey.elements[0], 0));
}
