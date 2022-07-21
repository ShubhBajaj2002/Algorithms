
#include <bits/stdc++.h>
using namespace std;
int par[100007];


void make(int n){
	par[n] = n;
}

int find(int n){
	if(par[n] == n) return n;
	return par[n] = find(par[n]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		par[a] = b;
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int vertices, branches;
	cin >> vertices >> branches;
	vector <pair<int,pair<int,int> > > edges;
	for(int i = 0; i < branches; i++){
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;
		edges.push_back({weight,{vertex1,vertex2}});
	}		
	for(int i = 1; i <= vertices; i++){
		make(i);
	}
	cout << "vertex1 - vertex2 :\n";
	sort(edges.begin(),edges.end());
	for(auto &edge : edges){
		int n1 = edge.second.first;
		int n2 = edge.second.second;
		if(find(n1) == find(n2)) continue;
		Union(n1,n2);
		cout << n1 << " - " << n2 << endl;
	}

	return 0;
}
