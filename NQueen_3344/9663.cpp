/* backtracking 알고리즘.
* 
*/
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int board[16][16];
int cnt;
int N;
int promising(int n) {

}
void nQueen(int num) {
	if (num == N) cnt++;
	else {
		for (int i = 1; i <= N; i++) {
			if()
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	nQueen(0);
	cout << cnt;
}