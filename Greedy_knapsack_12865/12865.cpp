/* DP
* dp[���� ��ȣ][�ִ� ����]
* ���� ����� ���� �ȳֱ� vs ���� ��� �� �ֱ� ��
* ���� �� ������ (dp[i - 1][j]) vs �ֱ� �� ������ ��ġ + ���� ���� ��ġ (dp[i - 1][j - weight])
* ���� ū �� ���� -> �ִ�
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
		//���濡 �� �� �ִ� ù��° ����.
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