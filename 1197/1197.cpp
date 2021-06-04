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
	//find 할 때 노트의 부모를 찾아가면서 포인터를 부모가 아닌 루트를 가리키게함 -> 트리의 높이 낮아질 가능성 있음.
	if (node[a].parent == a) return a;
	else return node[a].parent = find(node[a].parent);
}

void merge() {
	//merge 할 때 트리의 높이가 낮은 것이 높은 것을 가리키게함 -> 트리의 높이 최소로 유지

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