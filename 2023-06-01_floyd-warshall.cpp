/**
 * Floyd-Warshall algorithm for shortest path between nodes
 * June 1st, 2023
 * 
 * https://cses.fi/book/book.pdf
 * https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 */ 

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500; // Limit on N and K
const int MAX_WEIGHT = 1000; // Maximum weight of an edge. Using INT_MAX leads to overflow.
int N; // Number of nodes
int K; // Number of inputs

vector<vector<int>> edges; // Vector of edges in [node 1, node 2, weight]
int dist[MAXN][MAXN]; // Distance between node i and node j is dist[i][j].

void floydWarshall(){
	// 0. Setup
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			dist[i][j] = MAX_WEIGHT;
	}

	// 1. All edges
	for(auto edge : edges){
		dist[edge[0]][edge[1]] = edge[2];
		dist[edge[1]][edge[0]] = edge[2];
	}

	// 2. Distance from a node to itself
	for(int i = 0; i < N; i++){
		dist[i][i] = 0;
	}

	// 3. Other
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> K;
	for(int i = 0, n1, n2, weight; i < K; i++){
		cin >> n1 >> n2 >> weight;
		edges.push_back({n1, n2, weight});
	}

	floydWarshall();

	cout << "Distance between node 0 and node 1 is " << dist[0][1] << "\n";
	cout << "Distance between node 1 and node 3 is " << dist[1][3] << "\n";
	cout << "Distance between node 1 and node 2 is " << dist[1][2] << "\n";

	return 0;
}
