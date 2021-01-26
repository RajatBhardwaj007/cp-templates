/*
Ques:
Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms:
"a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.
Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.


Solution:

First, going through equality equations and use the union operation to join the variables in one set.

Second, going through inequality equations and verify that the variables are not in the same set using the find operation.

As a refresher, the picture below demonstrates how the disjoined set structure changes based on the equality equations.
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
	
	//UnionFind uf(n+1); ab ye graph type object hai. Ismei unite(a,b) krva skte ho.
};

bool equationsPossible(vector<string>& equations) {
  UnionFind uf('z' + 1);
  for (auto s : equations)
    if (s[1] == '=') 
	  uf.unite(s[0],s[3]);
	  
  for (auto s : equations)
    if (s[1] == '!' && uf.connected(s[0],s[3])) return false;
  return true;
}