#include <iostream>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 987654321
using namespace std;

int dp[101][101];

void floyd(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

int main() {
	FASTIO;
	int n, m, srt, dest, cost;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> srt >> dest >> cost;
		dp[srt][dest] = min(dp[srt][dest],cost);
	}
	floyd(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == MAX) cout << 0 << " ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}