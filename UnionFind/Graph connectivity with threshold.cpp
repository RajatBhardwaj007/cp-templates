
/*
We have n cities labeled from 1 to n. Two different cities with labels x and y are directly connected by a
bidirectional road if and only if x and y share a common divisor strictly greater than some threshold. More 
formally, cities with labels x and y have a road between them if there exists an integer z such that all of the following are true:

x % z == 0,
y % z == 0, and
z > threshold.
Given the two integers, n and threshold, and an array of queries, you must determine for each queries[i] = [ai, bi] if cities ai and bi are connected 
(i.e. there is some path between them).

Return an array answer, where answer.length == queries.length and answer[i] is true if for the ith query, 
there is a path between ai and bi, or answer[i] is false if there is no path.





*/

class UnionFind {
    vector<int> component;
    vector<int> rank;
    int distinctComponents;
public:
    /*
     *   Initially all 'n' nodes are in different components.
     *   e.g. component[2] = 2 i.e. node 2 belong to component 2.
     */
    UnionFind(int n) {
        distinctComponents = n;
        for (int i=0; i<=n; i++) {
            component.push_back(i);
            rank.push_back(0);
        }
    }
    
    /*
     *   Returns true when two nodes 'a' and 'b' are initially in different
     *   components. Otherwise returns false.
     */
    bool unite(int a, int b) {    
        int rootA = findComponent(a);
        int rootB = findComponent(b);
        if (rootA == rootB) {
            return false;
        }
        if (rank[rootA] < rank[rootB]) {
            component[rootA] = rootB;    
        } else {
            if (rank[rootA] == rank[rootB]) {
                rank[rootA]++;
            }
            component[rootB] = rootA;
        }
        
        distinctComponents--;
        return true;
    }
    
    /*
     *   Returns what component does the node 'a' belong to.
     */
    int findComponent(int a) {
        if (component[a] != a) {
            component[a] = findComponent(component[a]);
        }
        return component[a];
    }
    
    /*
     * Are Node a and Node b connected? i.e. in same component? 
     */
    
    bool connected(int a, int b) {
        return findComponent(a) == findComponent(b);
    }
    
    /*
     *   Are all nodes united into a single component?
     */
    bool united() {
        return distinctComponents == 1;
    }
};

class Solution {
    void setup(int n, int t, UnionFind &uf) {
        t++;
        for (int i=t; i<=n; i++) {
            int m = 1;
            while (i*m <= n) {
                uf.unite(i, i*m);
                m += 1;
            }
        }
    }
    
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n+1);
        setup(n, threshold, uf);
        vector<bool> ans;
        for (auto query: queries) {
            ans.push_back(uf.connected(query[0], query[1]));
        }
        return ans;
    }
};
