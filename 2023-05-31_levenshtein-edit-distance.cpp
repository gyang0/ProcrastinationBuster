/**
 * Levenshtein Edit Distance
 * May 31, 2023
 * 
 * https://en.wikipedia.org/wiki/Levenshtein_distance
 * https://leetcode.com/problems/edit-distance/editorial/
 * https://codeforces.com/blog/entry/70018
 */

#include <bits/stdc++.h>
#include <string>
using namespace std;

int levenshtein(string s1, string s2){
	int N = s1.size();
	int M = s2.size();

	// Full of large values
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
	dp[0][0] = 0;

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= M; j++){
			if(i > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			if(j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			if(i > 0 && j > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
		}
	}

	return dp[N][M];
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// The two strings
	string s1, s2;
	cin >> s1 >> s2;

	cout << s1 << "\n" << s2 << "\n\n";

	cout << levenshtein(s1, s2) << "\n";


	return 0;
}
