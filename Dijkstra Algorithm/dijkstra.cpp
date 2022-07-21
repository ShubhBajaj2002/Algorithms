
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
const int INF = 1e9;
vector< pair<int,int> > branches[N];
int vis[N];
vector<int> dist(N,INF);

void dijkstra(int source){
	set<pair<int,int> > order;
	order.insert({0,source});
	dist[source] = 0;
	while(order.size() != 0){
		int vertex = order.begin()->second;
		int distance = order.begin()->first;
		order.erase(order.begin());
		if(vis[vertex]) continue;
		vis[vertex] = 1;
		for(auto child : branches[vertex]){
			int child_node = child.first;
			int wt = child.second;
			if(wt + distance < dist[child_node]){
				dist[child_node] = wt + distance;
				order.insert({dist[child_node], child_node});
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
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;
		branches[vertex1].push_back({vertex2,weight});
	}
	int root;
	cin >> root;
	dijkstra(root);
	for(int i = 1; i <= vertices; i++){
		cout << i << " " << dist[i] << endl;
	}
	return 0;
}
