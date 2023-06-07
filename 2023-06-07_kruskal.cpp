/**
 * Kruskal's algorithm with Disjoint Set Union
 * June 7, 2023
 * 
 * https://usaco.guide/gold/dsu?lang=cpp
 * https://darrenyao.com/usacobook/cpp.pdf#page=54
 * https://usaco.guide/gold/mst?lang=cpp#kruskals
 */ 

#include <bits/stdc++.h>
using namespace std;

int N; // Number of nodes
int K; // Number of inputs

// Edge structure: two nodes and weight
struct Edge {
	int a, b, weight;
	Edge(int aa, int bb, int c){
		a = aa;
		b = bb;
		weight = c;
	}
	bool operator<(const Edge& other){
		return weight < other.weight;
	}
};

// Disjoint Set Union
struct DSU {
	vector<int> parent;

	DSU(int N){
		// Set the root of each node to be itself.
		parent = vector<int>(N);
		for(int i = 0; i < N; i++)
			parent[i] = i;
	}

	int find(int x){
		if(x == parent[x]) return x;
		else return parent[x] = find(parent[x]); // path compression
	}

	void merge(int a, int b){
		int c = find(a);
		int d = find(b);
		if(c != d){
			parent[d] = c;
		}
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> K;

	// Setup
	DSU dsu(N);
	vector<Edge> edges;
	int cost = 0;

	for(int i = 0, n1, n2, w; i < K; i++){
		cin >> n1 >> n2 >> w;
		edges.push_back(Edge(n1, n2, w));
	}

	// Sort edges and merge
	sort(edges.begin(), edges.end());
	for(Edge e : edges){
		if(dsu.find(e.a) != dsu.find(e.b)){
			dsu.merge(e.a, e.b);
			cost += e.weight;
		}
	}

	cout << "Cost: " << cost << "\n";

	return 0;
}
