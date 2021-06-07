/* DP
* dp[물건 번호][최대 무게]
* 무게 남기고 물건 안넣기 vs 무게 사용 후 넣기 비교
* 위의 값 가져옴 (dp[i - 1][j]) vs 넣기 전 무게의 가치 + 넣은 후의 가치 (dp[i - 1][j - weight])
* 비교해 큰 값 넣음 -> 최댓값
*/

#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N, K, i;

class Stuff {
public:
	int weight = 1;
	int value = 1;
};

Stuff s[102];
int dp[102][100010];

int main() {
	FASTIO;
	cin >> N >> K;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		int W, V;
		cin >> W >> V;
		s[i].weight = W;
		s[i].value = V;
		dp[i][W] = V;
		//가방에 들어갈 수 있는 첫번째 지점.
	}
	for (int i = 1; i <= N; i++) {
		int w = s[i].weight; int v = s[i].value;
		for (int j = 1; j <= K; j++) {
			if (j < w) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
		}
	}

	cout << dp[N][K];
}