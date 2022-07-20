
#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex,vector< vector<int> > &branches, vector<bool> &vis){
	vis[vertex] = true;
	for(int child : branches[vertex]){
		if(vis[child]) continue;
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
	int count = 0;
	for(int i = 1; i <= vertices; i++){
		if(vis[i]) continue;
		dfs(i, branches, vis);
		count++;
	}
	cout << "Number of connected components are : " << count ;
	return 0;
}
