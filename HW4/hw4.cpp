#include <iostream>
#include <fstream>

using namespace std;

int sudoku[11][11];

bool row[11][11];
bool col[11][11];
bool square[11][11];

bool done = false; // 재귀 탈출을 위한 플래그

void setNum(int x, int y, int num, bool flag) {
		row[num][x] = flag;
		col[num][y] = flag;
		square[num][((x - 1) / 3) + ((y - 1) / 3) * 3 + 1] = flag;
}

int promising(int x, int y, int num) {
	if (!row[num][x] && !col[num][y] && !square[num][((x - 1) / 3) + ((y - 1) / 3) * 3 + 1]) return num;
	else return 0;
}

void solve(int x,int y) {
	if (x == 10) {
		done = true;
		return;
	}
	if (!sudoku[x][y]) {
		for (int i = 1; i < 10; i++) {
			if (int tmp = promising(x, y, i)) {
				sudoku[x][y] = i;
				setNum(x, y, i, true);
				if (y < 9) solve(x, y + 1);
				else solve(x + 1, 1);
				if (done) return;
				sudoku[x][y] = 0;
				setNum(x, y, i, false);
			}
		}
		return;
	}
	if (y < 9) solve(x, y + 1);
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
				setNum(j, k, sudoku[j][k], false); //다음 사용을 위해 초기화
			}
			cout << '\n';
		}
	}
}