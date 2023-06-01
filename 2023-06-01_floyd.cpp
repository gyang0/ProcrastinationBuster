/**
 * Floyd's algorithm for cycle detection
 * May 31, 2023
 * 
 * https://usaco.guide/CPH.pdf#page=165
 */ 


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500; // Limit on N and K
int N; // Number of nodes
int K; // Number of input pairs
vector<int> successor(MAXN, 0); // successor[i] gives the next node in the graph from node i.

void floyd(){
	// Starting node
	int x = 0,
		y = 0;

	// 1. Advance both until they meet.
	do {
		x = successor[x];
		y = successor[successor[y]];
	} while(x != y);

	// 2. Find the first node in the cycle
	x = 0;
	while(x != y){
		x = successor[x];
		y = successor[y];
	}
	cout << "Cycle starts at node " << x << "\n";

	// 3. Calculate length of cycle
	y = successor[x];
	int len = 1;

	cout << "Node in cycle: " << x << "\n";
	while(x != y){
		cout << "Node in cycle: " << y << "\n";
		y = successor[y];
		len++;
	}
	cout << "The length of the cycle is " << len << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> K;
	for(int k = 0, from, to; k < K; k++){
		cin >> from >> to;
		successor[from] = to;
	}

	floyd();

	return 0;
}
