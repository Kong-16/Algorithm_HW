/*backtracking
* isin[물건 번호] 안에 물건이 있는지 여부 작성
* bound 는 남은 weight에서 얼마나 큰 이익을 낼 수 있는지
*/

#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N, K, i, profit = 0, maxprofit = 0;

class Stuff {
public:
	int weight = 1;
	int value = 1;
	float vpw = 1;
	bool operator<(Stuff& a) {
		return vpw > a.vpw;
	}
};

Stuff s[102];
bool isin[102];

bool promising(int i,int profit, int weight) { // i번째 물품을 넣는게 좋은지?
	if (s[i].weight + weight >= K) return false;
	int j = i + 1, bound = profit, totweight = weight;
	while (j <= N && totweight + s[j].weight <= K) {
		totweight += s[j].weight;
		bound += s[j].value;
		j++;
	}
	int k = j;
	if (k <= N)
		bound += (K - totweight) * s[k].vpw; // vpw는 bound 값 계산위함.
	return bound > maxprofit;
}
void knapsack(int i,int profit, int weight) {
	if (weight <= K && profit > maxprofit) {
		maxprofit = profit;
	}
	if (promising(i, profit, weight)) {
		isin[i + 1] = 1;
		knapsack(i + 1, profit + s[i + 1].value, weight + s[i + 1].weight);
		//담을 경우
		isin[i + 1] = 0;
		//실패할 경우 담지 않고 넘김.
		knapsack(i + 1, profit, weight);
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;
		s[i].weight = W;
		s[i].value = V;
		s[i].vpw = V / W;
	}
	sort(s, s + N);

}