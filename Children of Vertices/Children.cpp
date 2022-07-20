
#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex,vector< vector<int> > &branches, vector<bool> &vis){
	vis[vertex] = true;
	for(int child : branches[vertex]){
		if(vis[child]) continue;
		cout << vertex << " -> " << child << endl;
		dfs(child, branches, vis);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int vertices, edges;
	cin >> vertices >> edges;
	vector<bool> vis(vertices,false);
	vector< vector<int> > branches(vertices);
	for(int i = 0; i < edges; i++){
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;
		branches[vertex1].push_back(vertex2);
		branches[vertex2].push_back(vertex1);
	}
	int root;
	cin >> root;
	dfs(root, branches, vis);
	return 0;
}
