
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int depth[N];

void dfs(int vertex,vector< vector<int> > &branches, int par){
	for(int child : branches[vertex]){
		if(child == par) continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, branches, vertex);
	}
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
	int mx_depth = 0;
	int mx_depth_node;
	for(int i = 1; i <= vertices; i++){
		if(mx_depth < depth[i]){
			mx_depth = depth[i];
			mx_depth_node = i;
		}
		depth[i] = 0;
	}
	dfs(mx_depth_node, branches, 0);
	for(int i = 1; i <= vertices; i++){
		if(mx_depth < depth[i]){
			mx_depth = depth[i];
		}
	}
	cout << "Diameter of the given tree is " << mx_depth;
	return 0;
}
