
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9;
vector< pair<int,int> > branches[N];
vector<int> level(N,INF);

void bfs(int source){
	deque<int> order;
	order.push_back(source);
	level[source] = 0;
	int lvl = 0;
	while(!order.empty()){
		int vertex = order.front();
		order.pop_front();
		for(auto child : branches[vertex]){
			int child_node = child.first;
			int wt = child.second;
			if(level[vertex] + wt < level[child_node]){
				level[child_node] = level[vertex] + wt;
				if(wt == 1)
					order.push_back(child_node);
				else
					order.push_front(child_node);
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
	bfs(root);
	cout << "node - level\n" ;
	for(int i = 1; i <= vertices; i++){
		cout << i << " - " << level[i] << endl;
	}
	return 0;
}
