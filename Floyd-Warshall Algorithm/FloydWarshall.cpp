
#include <bits/stdc++.h>
using namespace std;
int dp[507][507];
const int INF = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int vertices, edges;
	cin >> vertices >> edges;
	for(int i = 1; i <= vertices; i++){
		for(int j = 1; j <= vertices; j++){
			dp[i][j] = i == j ? 0 : INF;
		}
	}
	for(int i = 0; i < edges; i++){
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;
		dp[vertex1][vertex2] = weight;
	}
	for(int k = 1; k <= vertices; k++){
		for(int i = 1; i <= vertices; i++){
			for(int j = 1; j <= vertices; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 0; i <= vertices; i++){
		cout << i << " ";
	}
	cout << endl;
	for(int i = 1; i <= vertices; i++){
		cout << i << " ";
		for(int j = 1; j <= vertices; j++){
			if(dp[i][j] == INF) cout << "I";
			else cout << dp[i][j];
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
