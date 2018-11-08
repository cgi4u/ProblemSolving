#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
	int v1;
	int v2;
	int w;

	Edge(int _v1, int _v2, int _w) {
		v1 = _v1; v2 = _v2; w = _w;
	}
};

//������ �����Ǹ� ���� sort�� ��� ����
bool operator <(const Edge &e1, const Edge &e2) {
	return e1.w < e2.w;
}

int main() {
	int V, E;
	cin >> V >> E;

	int *set_of_v = new int[V];
	int *num_of_set = new int[V];
	for (int i = 0; i < V; i++) {
		set_of_v[i] = i;
		num_of_set[i] = 0;
	}

	vector<Edge> edges;
	for (int i = 0; i < E; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		edges.push_back(Edge(v1, v2, w));
	}

	sort(edges.begin(), edges.end());	//operator ���Ǹ� �س����� ��������!

	int e_accepted = 0;	
	int w_sum = 0;
	int cur = 0;
	while (e_accepted != V-1) {	//
		if (set_of_v[edges[cur].v1 - 1] != set_of_v[edges[cur].v2 - 1]) {
			w_sum += edges[cur].w;

			int set1 = set_of_v[edges[cur].v1 - 1];
			int set2 = set_of_v[edges[cur].v2 - 1];
			if (num_of_set[set1] >= num_of_set[set2]) {			//����Ʋ��, ���� �� ���� ������ ���Ͻ��Ѿ� �˰����� ���ư�
				for (int i = 0; i < V; i++) {
					if (set_of_v[i] == set2)
						set_of_v[i] = set1;
				}
				num_of_set[set1] += num_of_set[set2];
				num_of_set[set2] = 0;
			}
			else {
				for (int i = 0; i < V; i++) {
					if (set_of_v[i] == set1)
						set_of_v[i] = set2;
				}
				num_of_set[set2] += num_of_set[set1];
				num_of_set[set1] = 0;
			}													//edge �ϳ��� �ٲ㼭�� �ȵǰ� ��ü ������ �ٹٲ����
			
			e_accepted += 1;
		}
		cur += 1;
	}

	cout << w_sum;

	delete(set_of_v);
	delete(num_of_set);

	return 0;
}