#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct vertex{
    vertex* parent;
    vector<vertex*> children;
    int childrenCount;

    int value;
    bool state;

    // vertex(){
    //     parent = NULL;
    //     childrenCount = 0;
    // }
};

void addChild(vertex* parent, vertex* child)
{
    parent->childrenCount++;
    parent->children.push_back(child);
    child->parent = parent;
}

vector<vertex*> d;

void searchForDelete(vertex* head)
{
    if(head->childrenCount == 0)
        return;
    
    for(int i = 0; i < head->childrenCount; i++)
    {
        if(head->children[i]->state == 1)
        {
            bool del = true;
            for(int j = 0; j < head->children[i]->childrenCount; j++)
                if(head->children[i]->children[j]->state == 0){
                    del = false;
                    break;
                }
            if(del)
                d.push_back(head->children[i]);
        }
        searchForDelete(head->children[i]);
    }
}

int main()
{
    int n;
    cin >> n;

    vertex* arr = new vertex[n];
    for(int i = 0; i < n; i++){
        arr[i].childrenCount = 0;
        arr[i].parent = NULL;
        arr[i].value = i + 1;
    }

    int head;
    int p, c;
    for(int i = 0; i < n; i++)
    {
        cin >> p >> c;
        arr[i].state = c;
        if(p == -1)
            head = i;
        else
            addChild(&arr[p - 1], &arr[i]);
    }

    searchForDelete(&arr[head]);

    vector<int> result;
    for(int i = 0; i < (int)d.size(); i++)
        result.push_back(d[i]->value);

    if(result.empty())
        cout << "-1";
    
    sort(result.begin(), result.end());
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}
