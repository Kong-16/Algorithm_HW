/*Kruskal 알고리즘. Greedy 이용. 간선의 가중치를 기준으로 오름차순 정렬. 작은 것 부터
 간선 이어줌. cycle이 형성되면 해당 간선 잇지않음.
 cycle 형성은 merge-find로 판단.
 root 노드는 parent값이 자기 자신임. leaf노드는 parent가 자기 부모를 가리킴.
 find 로 노드의 부모를 찾음.
 //////////////////////////////
 Prim 알고리즘도 Greedy 이용하지만 특정 정점에서 부터 시작함.
 Dijkstra 알고리즘도 Prim과 비슷하지만 특정 정점에서 특정 정점까지의 최단거리만 구함. -> 최소스패닝트리 못만듬.
 안돌아감. 수정필요
*/

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
		return cost < a.cost;
	}
};

struct Node {
	int parent;
	int depth = 0;
};

Path p[MAX];
Node node[MAX];
int cost = 0;

int find(int a) {
	//find 할 때 노트의 부모를 찾아가면서 포인터를 부모가 아닌 루트를 가리키게함 -> 트리의 높이 낮아질 가능성 있음.
	//Collapsing rule
	//여기선 구현하지 않음.
	if (node[a].parent == a) return a;
	else return node[a].parent = find(node[a].parent);
}

void merge(int p,int q) {
	//merge 할 때 트리의 높이가 낮은 것이 높은 것을 가리키게함 -> 트리의 높이 최소로 유지
	if (node[p].depth == node[q].depth) {//높이 비교후 같으면 아무거나
		node[p].depth++;
		node[q].parent = p;
	}
	else if (node[p].depth < node[q].depth)
		node[p].parent = q;
	else
		node[q].parent = p;
}

void kruskal(int e) {
	//find(a) == find(b) 이면 cycle임.
	int a, b;
	for (int i = 0; i < e; i++) {
		a = find(p[i].srt);
		b = find(p[i].dest);
		if (a != b) {
			merge(a, b);
			cost += p[i].cost;
		}
	}
}

int main() {
	FASTIO;
	int V, E;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) node[i].parent = i;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		p[i].srt = A;
		p[i].dest = B;
		p[i].cost = C;
	}
	sort(p, p + E);
	kruskal(E);

	cout << cost;
}