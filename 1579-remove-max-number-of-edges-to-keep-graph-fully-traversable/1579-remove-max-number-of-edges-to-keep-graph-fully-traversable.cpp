class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n+1), dsuBob(n+1);
        int redundantEdges = 0, aliceEdges = 0, bobEdges = 0;

        for (auto e : edges) {
            if (e[0] == 3) {
                int n1 = e[1], n2 = e[2];
                if ((dsuAlice.findParent(n1) != dsuAlice.findParent(n2)) || (dsuBob.findParent(n1) != dsuBob.findParent(n2))) {
                    dsuAlice.makeUnion(n1, n2);
                    dsuBob.makeUnion(n1, n2);
                    aliceEdges++;
                    bobEdges++;
                }
                else {
                    redundantEdges++;
                }
            }
        }

        for (auto e : edges) {
            int n1 = e[1], n2 = e[2];
            if (e[0] == 1) {
                if (dsuAlice.findParent(n1) != dsuAlice.findParent(n2)) {
                    dsuAlice.makeUnion(n1, n2);
                    aliceEdges++;
                }
                else {
                    redundantEdges++;
                }
            }
            else if (e[0] == 2) {
                if (dsuBob.findParent(n1) != dsuBob.findParent(n2)) {
                    dsuBob.makeUnion(n1, n2);
                    bobEdges++;
                }
                else {
                    redundantEdges++;
                }
            }
        }
        return (aliceEdges == n-1 && bobEdges == n-1) ? redundantEdges : -1;
    }
};