#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdint>
#include <cmath>


using namespace std;

typedef struct graphNode{
    uint64_t data;
    bool visited;
    set<struct graphNode*> neighbours;
}graphNode;

class Graph
{
public:
    vector<graphNode*> nodes;
    Graph(uint64_t data)
    {
        graphNode* head = new graphNode;
        head->data = data;
        nodes.push_back(head);
    }

    void addNode(uint64_t data)
    {
        graphNode* head = new graphNode;
        head->data = data;
        nodes.push_back(head);
    }

    void connect(graphNode* n1, graphNode* n2)
    {
        n1->neighbours.insert(n2);
        n2->neighbours.insert(n1);
    }
};

class Rumor: public Graph
{
public:
    Rumor(int data) : Graph(data){}
    uint64_t DFS(graphNode* head, uint64_t minGold)
    {
        minGold = (head->data < minGold) ? head->data : minGold;
        head->visited = true;
        for(auto i = head->neighbours.begin(); i != head->neighbours.end(); i++)
        {
            if(!(*i)->visited)
                minGold = DFS((*i), minGold);
        }
        return minGold;
    }

    uint64_t findMin(void)
    {
        uint64_t sum = 0;
        int size = (int)nodes.size();

        for(int i = 0; i < size; i++)
            nodes[i]->visited = false;
        
        for(int i = 0; i < size; i++)
        {
            if(nodes[i]->visited)
                continue;
            else
                nodes[i]->visited = true;
            
            if(nodes[i]->neighbours.empty())
                sum += nodes[i]->data;
            else
                sum += DFS(nodes[i], nodes[i]->data);
                
            
        }
        return sum;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    int elem;
    cin >> elem;
    Rumor rumor(elem);
    for(int i = 1; i < n; i++){
        cin >> elem;
        rumor.addNode(elem);
    }

    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        rumor.connect(rumor.nodes[x - 1], rumor.nodes[y - 1]);
    }

    cout << rumor.findMin() << endl;
}
