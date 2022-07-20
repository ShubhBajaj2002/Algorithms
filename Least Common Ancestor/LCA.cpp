
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int parent[N];

void dfs(int vertex,vector< vector<int> > &branches, int par){
	parent[vertex] = par;
	for(int child : branches[vertex]){
		if(child == par) continue;
		dfs(child, branches, vertex);
	}
}

vector<int> path(int vertex){
	vector<int> pth;
	while(vertex != 0){
		pth.push_back(vertex);
		vertex = parent[vertex];
	}
	reverse(pth.begin(), pth.end());
	return pth;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int vertices, edges;
	cin >> vertices >> edges;
	vector< vector<int> > branches(vertices);
	for(int i = 0; i < edges; i++){
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;
		branches[vertex1].push_back(vertex2);
		branches[vertex2].push_back(vertex1);
	}
	int root;
	cin >> root;
	dfs(root, branches, 0);
	int node1, node2;
	cin >> node1 >> node2;
	vector<int> path1 = path(node1);
	vector<int> path2 = path(node2);
	int min_len = (path1.size(), path2.size());

	int lca = 0;
	for(int i = 0; i < min_len; i++){
		if(path1[i] == path2[i])
			lca = path1[i];
		else
			break;
	}
	cout << "Least Common Ancestor of " << node1 << " and " << node2 << " is " << lca;
	return 0;
}
