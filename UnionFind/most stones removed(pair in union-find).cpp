/*
Question:
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Soln:
Imagine each stone has an ID corresponding to its index in the input array.
Map each occupied row to a vector of all stone IDs in that row. Repeat for columns.
Union each stone ID with all other stone IDs in the same row or in the same column.
Each connected group can have all but one stone removed. Thus, "we count the number of unique groups and subtract this from the total number of stones to get our answer".
*/

// ismei maps use kia hai because pair se deal krna h
vector<int> parent;
int find(int n) {
	return parent[n] == n ? n : parent[n] = find(parent[n]); 
}

void unite(int a, int b) {
	parent[find(a)] = find(b);	
}



int removeStones(vector<vector<int>>& stones) {
	unordered_map<int, vector<int>> rowmap, colmap;
	for(int i = 0; i < stones.size(); i++) {
		rowmap[stones[i][0]].push_back(i);
		colmap[stones[i][1]].push_back(i);
	}

	for(int i = 0; i < stones.size(); i++) parent.push_back(i);
	for(int i = 0; i < stones.size(); i++) {
		for(int j : rowmap[stones[i][0]]) unite(i, j); //  basically stones[i][0] aur stones[i][1] mai jis jis stone ki stones[i][0] same h unko unite kia
		for(int j : colmap[stones[i][1]]) unite(i, j);
	}

	unordered_set<int> unique;
	for(int n : parent) unique.insert(find(n));
	return stones.size() - unique.size();
}