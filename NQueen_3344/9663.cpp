/* backtracking �˰���. DFS.
* �־ �� �� : ���� nqueen ����.
* �ȵǸ� �Ǵ� �κб��� nqueen�����. ���� for ���� �ִ� j++�� ����.
*/
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int board[17][17];
int col[17];
int N;
bool promising(int i) {
	int k = 1;
	while (k < i) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k) return false;
		k++;
	}
	return true;
}
void nQueen(int num) {
	if (promising(num)) {
		if (num == N) {
			for (int i = 1; i <= N; i++) cout << col[i] << " " ;
			exit(0);
		}
		else 
			for (int j = 1; j <= N; j++) {
				col[num+ 1] = j;
				nQueen(num + 1);
			}
	}
}

int main() {
	FASTIO;
	cin >> N;
	nQueen(0);
}