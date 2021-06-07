/* dp 알고리즘. W[i][j]에 i에서 j로 가는 가중치 저장.
*  1에서 시작해 다시 1로 돌아오는 최솟값.
*  V는 모든 정점, A는 일부 정점
*  dp[현재정점][방문정점]
*  구하는 것 : dp[1][V - 1] = min (W[1][j]+ dp[j][V - 1,j])
*  dp[i][A] = min (W[i][j] + dp[j][A - j])
*  안돌아감. 암튼 이런식
*/
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 987654321
using namespace std;

int N;
int W[20][20]; //W[i][j] = i에서 j로 가는 가중치.
int dp[20][1 << 16];
//비트마스킹 기법 이용. 1번 방문. 100~0 방문 도시 1로 바꿈.


int DFS(int now, int visit) {
	if (visit == (1 << N) - 1) { //모든 지점 방문,
		if (!dp[now][1]) return MAX; // 시작지점 갈 수 없을 때
		return dp[now][1]; //
	}
	int& ret = dp[now][visit]; //방문한 적 있으면 return
	if (ret != MAX)return ret;

	for (int i = 1; i <= N; i++) {
		if (!(visit & (1 << (i - 1)))) { // and 연산으로 같은지 확인.
			// 해당 노드 방문 안했으면
			if (dp[now][i]) {
				ret = min(ret, DFS(i, visit | (1 << (i - 1))) + dp[now][i]); //or 연산으로 다른 곳 방문하고 갔음을 표시
				// 현재값과 비교해 짧은 값 채택
			}
		}
	}
	return ret;
}


int main() {
	FASTIO;

	cin >> N;
	memset(dp, MAX, sizeof(dp));
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> W[i][j];
	cout << DFS(1, 1);
}