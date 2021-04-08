// d * 3 ���߹迭,�����ε����� ����ȣ, �����ε����� 0���� left, 1���� right, 2���� ����Ʈ�� ��尳�� + 1 ����.

// ������ ����Ʈ�� ��� ���� - ���� ����Ʈ�� ��� ���� > 0 �� ��� ���� ���.



#include <iostream>

#include<fstream>



using namespace std;



int nodeCount(int** dlr, int num) { //���� ����Ʈ�� ��� ���� + ������ ����Ʈ�� ��� ���� + 1�� dlr[num][2]�� ����

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

		for (int j = 0; j < nodeNum; j++) { // -1 �ϰ�� -1 ��� 0 ����

			fin >> d >> l >> r;



			if (l == -1) dlr[d][0] = 0;

			else dlr[d][0] = l;



			if (r == -1) dlr[d][1] = 0;

			else dlr[d][1] = r;

		}

		nodeCount(dlr, 1);

		count = 0;

		for (int j = 1; j <= nodeNum; j++) { // ������ ����Ʈ�� : dlr[j][1], ������ ����Ʈ���� ��� ���� : dlr[dlr[j][1]][2]

			if (dlr[dlr[j][1]][2] - dlr[dlr[j][0]][2] > 0) count++;

		}

		cout << count << endl;

	}

}