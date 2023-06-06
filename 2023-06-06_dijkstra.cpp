/**
 * Dijkstra's algorithm
 * 
 * June 5, 2023
 * https://usaco.guide/CPH.pdf#page=136
 */ 

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

const int MAXN = 500; // Limit on N and K
int N; // Number of nodes
int K; // Number of inputs

int distances[MAXN]; // Minimum distance from source node to all other nodes
bool done[MAXN]; // Whether we're done for a node or not, set to false by default.
vector<pii> adjList[MAXN]; // Adjacency list in the form [connected_node, weight]

void dijkstra(int src){
	for(int i = 0; i < N; i++)
		distances[i] = INT_MAX;

	distances[src] = 0;

	// Queue
	priority_queue<pii> q;
	q.push({0, src});

	while(!q.empty()){
		int a = q.top().s; // Node in question
		q.pop();

		// No repeats
		if(done[a]) continue;
		done[a] = true;

		for(auto u : adjList[a]){
			int b = u.f;
			int w = u.s;
			if(distances[a] + w < distances[b]){
				distances[b] = distances[a] + w;

				// A negative number since the priority queue in C++ only works with the maximum
				q.push({-distances[b], b});
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> K;
	for(int i = 0, n1, n2, w; i < K; i++){
		cin >> n1 >> n2 >> w;
		adjList[n1].push_back({n2, w});
		adjList[n2].push_back({n1, w});
	}

	// Minimum distance from node 0 to all other nodes
	dijkstra(0);

	cout << "The minimum distance from node 0 to node 1 is " << distances[1] << "\n";
	cout << "The minimum distance from node 0 to node 3 is " << distances[3] << "\n";

	return 0;
}
