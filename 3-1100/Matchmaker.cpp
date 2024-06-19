#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define TABLE_SIZE  1000

unsigned int hashFunc(int size, int color)
{
    return (size * 1000 + color);
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    unsigned int maxTable[1000] = {0};
    unsigned int* hashTable = (unsigned int*)calloc(1001000, sizeof(unsigned int));
    unsigned int x, y;
    
    unsigned int hashValue;
    int max = 0, beautiful = 0;
    /* Markers Input */
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        maxTable[y]++;
        hashValue = hashFunc(y, x);
        hashTable[hashValue]++;
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        if(maxTable[y] > 0){
            max++;
            maxTable[y]--;
        }
        hashValue = hashFunc(y, x);
        if(hashTable[hashValue] > 0){
            hashTable[hashValue]--;
            beautiful++;
        }
    }
    
    cout << max << " " << beautiful << endl;
}
