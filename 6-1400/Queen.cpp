#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct vertex
{
    vertex* parent;
    vector<vertex*> children;
    bool state;
};

void addChild(vertex* parent, vertex* child)
{
    parent->children.push_back(child);
    child->parent = parent;
}

void searchForDelete(vertex* arr, int n, vector<int>& result)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i].state && arr[i].parent != NULL)
        {
            bool del = true;
            for(int j = 0; j < arr[i].children.size(); j++)
            {
                if(!arr[i].children[j]->state){
                    del = false;
                    break;
                }
            }
            if(del)
                result.push_back(i + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vertex* arr = new vertex[n];
    int p, c;
    for(int i = 0; i < n; i++)
    {
        cin >> p >> c;
        arr[i].state = c;
        if(p == -1)
            arr[i].parent = NULL;
        else
            addChild(&arr[p - 1], &arr[i]);
    }

    vector<int> result;
    searchForDelete(arr, n, result);

    if(result.empty())
        cout << "-1" << endl;
    else
    {
        for(int i = 0; i < (int)result.size(); i++)
            cout << result[i] << ((i != result.size() - 1)? " " : "\n");
    }
}
