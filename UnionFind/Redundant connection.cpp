// basically ek graph h tree mai convert krna h ek edge remove kr k. So basically cycle ki koi bhi edge remove kr do. Quesiton mai bola tha jo last mai aa rhi h vo krni h.

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
	
	//UnionFind uf(n+1); ab ye graph type object hai. Ismei unite(a,b) krva skte ho.
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(100005);
        vector<int>res;
        for(int i=0;i<edges.size(); i++)
        {
            if(uf.findComponent(edges[i][0])!=uf.findComponent(edges[i][1]))
                uf.unite(edges[i][0],edges[i][1]);
            else
                res=edges[i];
        }
        return res;
    }
};