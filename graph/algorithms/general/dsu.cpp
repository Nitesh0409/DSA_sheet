#include <iostream>
#include <vector>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false; // Already in the same set

        // Union by rank
        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main()
{
    // Create DSU with 5 elements (0 to 4)
    DSU dsu(5);

    // Unions
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    // Find operations
    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(2): " << dsu.find(2) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;

    // Check if two elements are connected
    cout << "Are 0 and 2 connected? " << (dsu.find(0) == dsu.find(2) ? "Yes" : "No") << endl;
    cout << "Are 0 and 4 connected? " << (dsu.find(0) == dsu.find(4) ? "Yes" : "No") << endl;

    return 0;
}
