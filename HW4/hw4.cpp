/*back tracking �˰���. row[��][����] col[��][����] square[�簢��][����] = 1�̸� �ش� ��/�簢�� �� �ش� ���ڴ� �� ��.
* promising���� ������ �� �˻�. 
*/

#include <iostream>
#include <fstream>

using namespace std;

int sudoku[11][11];

bool row[11][11];
bool col[11][11];
bool square[11][11];

bool done = false; // ��� Ż���� ���� �÷���

void setNum(int x, int y, int num, bool flag) {
		row[num][x] = flag;
		col[num][y] = flag;
		square[num][((x - 1) / 3) + ((y - 1) / 3) * 3 + 1] = flag;
}

int promising(int x, int y, int num) {
	if (!row[num][x] && !col[num][y] && !square[num][((x - 1) / 3) + ((y - 1) / 3) * 3 + 1]) return num;
	else return 0; //false ����
}

void solve(int x,int y) {
	if (x == 10) { // ������ ĭ ���� ��
		done = true;
		return;
	}
	if (!sudoku[x][y]) { // 0�� ����
		for (int i = 1; i < 10; i++) {
			if (int tmp = promising(x, y, i)) { // tmp�� ���ɼ� �ִ� �� �϶�
				sudoku[x][y] = i; // ����ְ�
				setNum(x, y, i, true); // row col square = true
				if (y < 9) solve(x, y + 1); 
				else solve(x + 1, 1); //���� ĭ Ǯ����
				if (done) return; // ������ ĭ ���޽� ��� Ż��
				sudoku[x][y] = 0; // tmp�� ���� ���� �Ǵ�.
				setNum(x, y, i, false); // �ٽ� ��������
			}
		}
		return;
	}
	if (y < 9) solve(x, y + 1); // �̹� �� �ִ� ���� ��
	else solve(x + 1,1);
}


int main() {
	int dataNum;
	fstream fin("input.txt");
	fin >> dataNum;
	for (int i = 0; i < dataNum; i++) {
		done = false;
		for (int j = 1; j <= 9; j++)
			for (int k = 1; k <= 9; k++) {
				fin >> sudoku[j][k];
				if (sudoku[j][k]) setNum(j, k, sudoku[j][k], true);
			}
		solve(1, 1);
		cout << "sudoku " << i + 1 << '\n';
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				cout << sudoku[j][k] << ' ';
				setNum(j, k, sudoku[j][k], false); //���� ����� ���� �ʱ�ȭ
			}
			cout << '\n';
		}
	}
}