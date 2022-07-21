
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> branches[N];
int vis[N];
int level[N];

void bfs(int source){
	queue<int> order;
	order.push(source);
	vis[source] = 1;
	int lvl = 0;
	while(!order.empty()){
		int vertex = order.front();
		order.pop();
		for(int child : branches[vertex]){
			if(!vis[child]){
				order.push(child);
				vis[child] = 1;
				level[child] = level[vertex] + 1;
				if(level[child] > lvl){
					lvl = level[child];
					cout << "level " << lvl << ":"<< endl;
				} 
				cout << child << endl;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int vertices, edges;
	cin >> vertices >> edges;
	for(int i = 0; i < edges; i++){
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;
		branches[vertex1].push_back(vertex2);
		branches[vertex2].push_back(vertex1);
	}
	int root;
	cin >> root;
	cout << "level 0 :\n" << root << endl;
	bfs(root);
	return 0;
}
