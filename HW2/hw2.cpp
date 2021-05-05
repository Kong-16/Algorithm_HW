#include <iostream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <sys/time.h>


using namespace std;

void partition(int low, int high, int& pivotpoint, int S[]) {
	int i, j;
	int pivotitem;
	pivotitem = S[low];
	j = low;
	for (i = low + 1; i <= high; i++)
		if (S[i] < pivotitem) {
			j++;
			swap(S[i], S[j]);// exchange S[i] and S[j];
		}
	pivotpoint = j;
	swap(S[low], S[pivotpoint]);
}

void quickSort(int low, int high, int S[]) {
	int pivotpoint;

	if (high > low) {
		partition(low, high, pivotpoint, S);
		quickSort(low, pivotpoint - 1, S);
		quickSort(pivotpoint + 1, high, S);
	}
}

void merge(int h, int m, const int U[], const int V[], int S[]) {
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i < h && j < m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
	}
	if (i >= h)
		copy(V + j, V + m, S + k);
	else
		copy(U + i, U + h, S + k);

}

void mergeSort(int n, int S[]) {
	if (n > 1) {
		const int h = n / 2, m = n - h;
		int* U = new int[h];
		int* V = new int[m];
		copy(S, S + h, U);
		copy(S + h, S + n, V);
		mergeSort(h, U);
		mergeSort(m, V);
		merge(h, m, U, V, S);
		delete[] U;
		delete[] V;
	}
}

int main() {
	int dataNum;
	srand(time(NULL));
	fstream fin("input.txt");
	double sorted[6];
	double random_merge[9];
	double avg_merge[3] = { 0 };
	double random_quick[9];
	double avg_quick[3] = { 0 }; // 데이터 별로 정렬시간 저장
	struct timeval start_t, end_t;
	double diff_t;
	int num_arr[6];

	for (int i = 0; i < 3; i++) { //sorted data
		fin >> dataNum;
		num_arr[i] = dataNum;
		int* quick_rand = new int[dataNum];
		int* merge_rand = new int[dataNum];
		for (int j = 0; j < dataNum; j++) quick_rand[j] = j + 1; // 정렬된 데이터 생성
		copy(quick_rand, quick_rand + dataNum, merge_rand);

		gettimeofday(&start_t, NULL);
		mergeSort(dataNum, merge_rand);
		gettimeofday(&end_t, NULL);
		diff_t = (double)(end_t.tv_sec - start_t.tv_sec) + ((double)(end_t.tv_usec - start_t.tv_usec) / 1000000);
		sorted[2 * i] = diff_t;

		gettimeofday(&start_t, NULL);
		quickSort(0, dataNum - 1, quick_rand);
		gettimeofday(&end_t, NULL);
		diff_t = (double)(end_t.tv_sec - start_t.tv_sec) + ((double)(end_t.tv_usec - start_t.tv_usec) / 1000000);
		sorted[2 * i + 1] = diff_t;
	}
	cout << left << setw(15) << "sorted" << "N = " << setw(11) << num_arr[0] << "N = " << setw(11) << num_arr[1] << "N = " << setw(15) << num_arr[2] << endl;
	cout << left << setw(15) << "Merge Sort" << setw(15) << sorted[0] << setw(15) << sorted[2] << setw(15) << sorted[4] << endl;
	cout << left << setw(15) << "Quick Sort" << setw(15) << sorted[1] << setw(15) << sorted[3] << setw(15) << sorted[5] << endl << endl;

	for (int i = 0; i < 3; i++) { // random data
		fin >> dataNum;
		num_arr[i + 3] = dataNum;
		int* quick_rand = new int[dataNum];
		int* merge_rand = new int[dataNum];
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < dataNum; j++) quick_rand[j] = rand();
			copy(quick_rand, quick_rand + dataNum, merge_rand);

			gettimeofday(&start_t, NULL);
			mergeSort(dataNum, merge_rand);
			gettimeofday(&end_t, NULL);
			diff_t = (double)(end_t.tv_sec - start_t.tv_sec) + ((double)(end_t.tv_usec - start_t.tv_usec) / 1000000);
			random_merge[3 * i + k] = diff_t;

			gettimeofday(&start_t, NULL);
			quickSort(0, dataNum - 1, quick_rand);
			gettimeofday(&end_t, NULL);
			diff_t = (double)(end_t.tv_sec - start_t.tv_sec) + ((double)(end_t.tv_usec - start_t.tv_usec) / 1000000);
			random_quick[3 * i + k] = diff_t;
		}
	}

	cout << left << setw(30) << "random" << "N = " << setw(11) << num_arr[3] << "N = " << setw(11) << num_arr[4] << "N = " << setw(11) << num_arr[5] << endl;
	cout << "Merge Sort" << endl;
	for (int i = 0; i < 3; i++) {
		cout << left << "\t\tdata" << setw(10) << i + 1 << setw(15) << random_merge[i] << setw(15) << random_merge[i + 3] << setw(15) << random_merge[i + 6] << endl;
		for (int j = 0; j < 3; j++) avg_merge[j] += random_merge[i + 3 * j];
	}
	cout << left << setw(16) << "\t\taverage" << setw(15) << avg_merge[0] / 3 << setw(15) << avg_merge[1] / 3 << setw(15) << avg_merge[2] / 3 << endl << endl;

	cout << "Quick Sort" << endl;
	for (int i = 0; i < 3; i++) {
		cout << left << "\t\tdata" << setw(10) << i + 1 << setw(15) << random_quick[i] << setw(15) << random_quick[i + 3] << setw(15) << random_quick[i + 6] << endl;
		for (int j = 0; j < 3; j++) avg_quick[j] += random_quick[i + 3 * j];
	}
	cout << left << setw(16) << "\t\taverage" << setw(15) << avg_quick[0] / 3 << setw(15) << avg_quick[1] / 3 << setw(15) << avg_quick[2] / 3 << endl;
}