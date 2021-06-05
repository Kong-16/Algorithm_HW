/* dp �˰���. 
* DNA���Ľ� mismatch�� 2, gap�� 3�� penalty�� �޴´�.
* penalty�� ���� ���� ������ ����.
* M�� penalty�� ��, P�� gap ���� �� 1, y-gap 2, x-gap 3 �� ����.
* P�� �� ����. 1�� �� �밢�� ��, 2�� �� ���ο��� �� ĭ, 3�� �� ���� ���� �� ĭ
* ���� �ٴٸ��� 1,1 �������� �������� �̵�.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <stack>
#include <iomanip>

#define MAX 100
using namespace std;

int m, n;
int M[MAX][MAX];
int P[MAX - 1][MAX - 1];
char x[MAX], y[MAX];

int get_min(int a, int b, int c) {
	int min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	return min;
}
void opt() {
	int penalty;
	for (int i = 0; i <= m; i++) M[i][0] = 3 * i;
	for (int i = 0; i <= n; i++) M[0][i] = 3 * i;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j]) penalty = 0; else penalty = 2;
			//x[i]�� y[j]�� ������ �˻�
			M[i][j] = get_min(M[i - 1][j - 1] + penalty, M[i - 1][j] + 3, M[i][j - 1] + 3);
			// ���� ���Ƽ + �̹� ���Ƽ , y�� �� �ֱ�, x�� �� �ֱ�
			if (M[i][j] == M[i - 1][j - 1] + penalty) P[i][j] = 1;
			else if (M[i][j] == M[i - 1][j] + 3) P[i][j] = 2;
			else P[i][j] = 3;
		}
	}
}

void align() {
	int p = max(m, n);
	stack<char> X, Y;
	int i, j;
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) cout << setw(3) << M[i][j];
		cout << "\n";
	}
	i = m; j = n;
	for (int k = 0; k < p; k++) {
		if (i == 0) {
			X.push('-');
			Y.push(x[i + 1]);
		}
		if (j == 0) {
			X.push(y[i + 1]);
			Y.push('-');
		}
		switch (P[i][j]) {
		case 1: // gap ���� ���
			X.push(x[i]);
			Y.push(y[j]);
			i--; j--; // �밢�� �� �̵�
			break;
		case 2: // y gap
			X.push(x[i]);
			Y.push('-');
			i--; // x�� �̵�
			break;
		case 3: // x gap
			X.push('-');
			Y.push(y[j]);
			j--; // y �� �̵�
			break;
		}
	}
	while (!X.empty()) {
		cout << X.top();
		X.pop();
	}
	cout << "\n";
	while (!Y.empty()) {
		cout << Y.top();
		Y.pop();
	}
	cout << "\n";
}

int main() {
	int dataNum;
	string s;
	fstream fin("input.txt");
	fin >> dataNum;
	for (int i = 0; i < dataNum; i++) {
		fin >> m >> s;
		for (int j = 0; j < m; j++) x[j + 1] = s[j];
		fin >> n >> s;
		for (int j = 0; j < n; j++) y[j + 1] = s[j];
		opt();
		align();
	}
}