#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 100010
using namespace std;

class Path {
public:
	int srt;
	int dest;
	int cost;
	bool operator <(Path& a) {
		if (cost < a.cost) return true;
		return false;
	}
};

struct Node {
	int parent;
	int depth = 0;
};

Path p[MAX];
Node node[MAX];

int find(int a) {
	//find �� �� ��Ʈ�� �θ� ã�ư��鼭 �����͸� �θ� �ƴ� ��Ʈ�� ����Ű���� -> Ʈ���� ���� ������ ���ɼ� ����.
	if (node[a].parent == a) return a;
	else return node[a].parent = find(node[a].parent);
}

void merge() {
	//merge �� �� Ʈ���� ���̰� ���� ���� ���� ���� ����Ű���� -> Ʈ���� ���� �ּҷ� ����

}

void kruskal() {

}
int main() {
	FASTIO;
	int V, E;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		p[i].srt = A;
		p[i].dest = B;
		p[i].cost = C;
	}
	sort(p, p + E);

}