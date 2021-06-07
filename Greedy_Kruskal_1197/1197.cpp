/*Kruskal �˰���. Greedy �̿�. ������ ����ġ�� �������� �������� ����. ���� �� ����
 ���� �̾���. cycle�� �����Ǹ� �ش� ���� ��������.
 cycle ������ merge-find�� �Ǵ�.
 root ���� parent���� �ڱ� �ڽ���. leaf���� parent�� �ڱ� �θ� ����Ŵ.
 find �� ����� �θ� ã��.
 //////////////////////////////
 Prim �˰��� Greedy �̿������� Ư�� �������� ���� ������.
 Dijkstra �˰��� Prim�� ��������� Ư�� �������� Ư�� ���������� �ִܰŸ��� ����. -> �ּҽ��д�Ʈ�� ������.
 �ȵ��ư�. �����ʿ�
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
	//find �� �� ��Ʈ�� �θ� ã�ư��鼭 �����͸� �θ� �ƴ� ��Ʈ�� ����Ű���� -> Ʈ���� ���� ������ ���ɼ� ����.
	//Collapsing rule
	//���⼱ �������� ����.
	if (node[a].parent == a) return a;
	else return node[a].parent = find(node[a].parent);
}

void merge(int p,int q) {
	//merge �� �� Ʈ���� ���̰� ���� ���� ���� ���� ����Ű���� -> Ʈ���� ���� �ּҷ� ����
	if (node[p].depth == node[q].depth) {//���� ���� ������ �ƹ��ų�
		node[p].depth++;
		node[q].parent = p;
	}
	else if (node[p].depth < node[q].depth)
		node[p].parent = q;
	else
		node[q].parent = p;
}

void kruskal(int e) {
	//find(a) == find(b) �̸� cycle��.
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