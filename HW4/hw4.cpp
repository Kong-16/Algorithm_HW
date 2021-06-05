/*back tracking 알고리즘. row[행][숫자] col[행][숫자] square[사각형][숫자] = 1이면 해당 줄/사각형 의 해당 숫자는 못 들어감.
* promising으로 가능한 지 검사. 
*/

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
	else return 0; //false 역할
}

void solve(int x,int y) {
	if (x == 10) { // 마지막 칸 도달 시
		done = true;
		return;
	}
	if (!sudoku[x][y]) { // 0일 때만
		for (int i = 1; i < 10; i++) {
			if (int tmp = promising(x, y, i)) { // tmp가 가능성 있는 수 일때
				sudoku[x][y] = i; // 집어넣고
				setNum(x, y, i, true); // row col square = true
				if (y < 9) solve(x, y + 1); 
				else solve(x + 1, 1); //다음 칸 풀러감
				if (done) return; // 마지막 칸 도달시 재귀 탈출
				sudoku[x][y] = 0; // tmp가 가능 없다 판단.
				setNum(x, y, i, false); // 다시 돌려놓음
			}
		}
		return;
	}
	if (y < 9) solve(x, y + 1); // 이미 차 있는 수일 때
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