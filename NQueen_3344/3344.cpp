#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int board[1000000][1000000];
int count = 0;
int N;
int promising(int n) {

}
void nQueen(int num) {
	if (num == N) count++;
	if (promising(num)) {
		for (int i = 1; i <= N; i++) {

		}
	}
}

int main() {
	FASTIO;

	cin >> N;
}