/* dp �˰���. W[i][j]�� i���� j�� ���� ����ġ ����.
*  1���� ������ �ٽ� 1�� ���ƿ��� �ּڰ�.
*  V�� ��� ����, A�� �Ϻ� ����
*  dp[��������][�湮����]
*  ���ϴ� �� : dp[1][V - 1] = min (W[1][j]+ dp[j][V - 1,j])
*  dp[i][A] = min (W[i][j] + dp[j][A - j])
*  �ȵ��ư�. ��ư �̷���
*/
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 987654321
using namespace std;

int N;
int W[20][20]; //W[i][j] = i���� j�� ���� ����ġ.
int dp[20][1 << 16];
//��Ʈ����ŷ ��� �̿�. 1�� �湮. 100~0 �湮 ���� 1�� �ٲ�.


int DFS(int now, int visit) {
	if (visit == (1 << N) - 1) { //��� ���� �湮,
		if (!dp[now][1]) return MAX; // �������� �� �� ���� ��
		return dp[now][1]; //
	}
	int& ret = dp[now][visit]; //�湮�� �� ������ return
	if (ret != MAX)return ret;

	for (int i = 1; i <= N; i++) {
		if (!(visit & (1 << (i - 1)))) { // and �������� ������ Ȯ��.
			// �ش� ��� �湮 ��������
			if (dp[now][i]) {
				ret = min(ret, DFS(i, visit | (1 << (i - 1))) + dp[now][i]); //or �������� �ٸ� �� �湮�ϰ� ������ ǥ��
				// ���簪�� ���� ª�� �� ä��
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