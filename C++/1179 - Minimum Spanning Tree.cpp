#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e4 + 4; // max number of vertices
const int MAX_E = 1e5 + 5; // max number of edges
const int INF = 1e9;

int parent[MAX_V];

struct Edge {
    int from, to, weight;
};

typedef struct GraphType {
    int v; 
    int e;
    vector<Edge> edges;
} GraphType;

void init() {
    memset(parent, -1, sizeof(parent));
}

int setFind(int curNode) {
    if (parent[curNode] == -1) return curNode;
    return parent[curNode] = setFind(parent[curNode]); 
}

void setUnion(int node1, int node2) {
    int root1 = setFind(node1);
    int root2 = setFind(node2);
    if (root1 != root2) parent[root1] = root2;
}

void initGraph(GraphType* g, int v, int e) {
    g->v = v;  
    g->e = e;  
}

void insertEdge(GraphType* g, int from, int to, int w) {
    g->edges.push_back({from, to, w});
}

int kruskal(GraphType* g) {
    int acceptedEdges = 0;
    int setU, setV;
    int sum = 0;
    init();

    sort(g->edges.begin(), g->edges.end(), [](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });

    for (Edge &e : g->edges) {
        setU = setFind(e.from);
        setV = setFind(e.to);

        if (setU != setV) {
            acceptedEdges++;
            sum += e.weight;
            setUnion(setU, setV);
        }

        if (acceptedEdges == g->v - 1) break;
    }

    if (acceptedEdges != g->v - 1) {
        return -1;  
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    GraphType* g = new GraphType();
    initGraph(g, v, e);

    for (int i = 0; i < e; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        insertEdge(g, from, to, weight);
    }

    int result = kruskal(g);

    cout << result << "\n";

    delete g; 

    return 0;
}
