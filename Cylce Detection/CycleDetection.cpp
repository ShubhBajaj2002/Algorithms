
#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex,vector< vector<int> > &branches, vector<bool> &vis, int par){
	vis[vertex] = true;
	for(int child : branches[vertex]){
		if(vis[child] && child == par) continue;
		if(vis[child]) return true;
		dfs(child, branches, vis, vertex);
	}
	return false;
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
	for(int i = 1; i <= vertices; i++){
		if(vis[i]) continue;
		if(dfs(i, branches, vis, 0)){
			cout << "True";
			return 0;
		}
	}
	cout << "False";
	return 0;
}
