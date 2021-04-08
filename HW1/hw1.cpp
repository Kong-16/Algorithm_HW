// d * 3 이중배열,가로인덱스는 노드번호, 세로인덱스의 0에는 left, 1에는 right, 2에는 서브트리 노드개수 + 1 저장.

// 오른쪽 서브트리 노드 개수 - 왼쪽 서브트리 노드 개수 > 0 인 노드 개수 출력.



#include <iostream>

#include<fstream>



using namespace std;



int nodeCount(int** dlr, int num) { //왼쪽 서브트리 노드 개수 + 오른쪽 서브트리 노드 개수 + 1을 dlr[num][2]에 저장

	if (num == 0) return 0;

	dlr[num][2] = nodeCount(dlr, dlr[num][0]) + nodeCount(dlr, dlr[num][1]) + 1;

}



int main() {

	int testNum, nodeNum, d, l, r, count;



	fstream fin("input.txt");



	fin >> testNum;

	for (int i = 0; i < testNum; i++) {

		fin >> nodeNum;

		int** dlr = new int* [nodeNum + 1];

		for (int j = 0; j < nodeNum + 1; j++) {

			dlr[j] = new int[3];

		}

		dlr[0][0] = dlr[0][1] = dlr[0][1] = 0;

		for (int j = 0; j < nodeNum; j++) { // -1 일경우 -1 대신 0 저장

			fin >> d >> l >> r;



			if (l == -1) dlr[d][0] = 0;

			else dlr[d][0] = l;



			if (r == -1) dlr[d][1] = 0;

			else dlr[d][1] = r;

		}

		nodeCount(dlr, 1);

		count = 0;

		for (int j = 1; j <= nodeNum; j++) { // 오른쪽 서브트리 : dlr[j][1], 오른쪽 서브트리의 노드 개수 : dlr[dlr[j][1]][2]

			if (dlr[dlr[j][1]][2] - dlr[dlr[j][0]][2] > 0) count++;

		}

		cout << count << endl;

	}

}