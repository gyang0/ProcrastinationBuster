/**
 * Bellman-Ford algorithm (without considering negative cycles, for now at least)
 * May 31, 2023
 * 
 * https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
 * https://usaco.guide/CPH.pdf#page=133
 */


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500; // Limit on N and V
int N; // Number of nodes
int V; // Number of vertices
vector<vector<int>> edges; // [node 1, node 2, weight]

int dist[MAXN]; // Result array

void bellmanFord(int source){
	for(int i = 0; i < V; i++){
		dist[i] = INT_MAX;
	}
	dist[source] = 0;

	for(int i = 0; i < V - 1; i++){
		for(int n = 0; n < N; n++){
			int n1 = edges[n][0],
				n2 = edges[n][1],
				weight = edges[n][2];
			dist[n2] = min(dist[n2], dist[n1] + weight);
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// Number of nodes
	cin >> N;

	// Number of vertices
	cin >> V;
	int n1, n2, weight;
	for(int v = 0; v < V; v++){
		cin >> n1 >> n2 >> weight;

		edges.push_back({n1, n2, weight});
	}

	bellmanFord(0); // From node 0
	for(int i = 0; i < N; i++){
		cout << "From vertex 0 to vertex " << i << ": " << dist[i] << "\n";
	}


	return 0;
}
