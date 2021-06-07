/* Floyd 알고리즘. dp[i][j]에 i에서 j로 가는 가중치 저장.
* 길이 없는 경우 무한대 (MAX)
* 이후 모든 숫자(k)에 대해 i에서 j로 바로가는 것과  
* i에서 k , k에서 j로 가는 비용 비교 후 작으면 교체
*/
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
				// i -> j 와 i -> k(다른 모든 지점) + k -> i 비교 
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
		//같은 곳으로 가는 경로 2개 이상일 때 짧은거.
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