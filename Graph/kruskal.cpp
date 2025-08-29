#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

int find(std::vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void Union(std::vector<int>& parent, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[yroot] = xroot;
}

int KruskalMST(std::vector<Edge>& edges, int V) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    std::vector<int> parent(V);
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    int mstWeight = 0;
    for (const Edge& edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);
        if (x != y) {
            mstWeight += edge.weight;
            Union(parent, x, y);
        }
    }
    return mstWeight;
}
