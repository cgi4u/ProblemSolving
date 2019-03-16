#include <iostream>
#include <vector>

/*
	���� �Ǽ�:
		������ '� �� ��'�� ���� ��. Ư�� �� 0�� ���� ���� �ƴ�
		�̰� �߸��Ǿ� ���� ���� ��ü�� ��������
	���� �Ǽ�: 
		������ �����ϴ� ������ ������ �ִ� N���� �� ���� �� 0�� �����ؾ��ϹǷ� �ִ� N�� ��� �̵� ������ ���ƿ´ٰ� ����.
		������ �ݷʷ� N-1���� ���ҵ��� ������ �̷�� �ְ�, �� ������ �� ���� 0�� ����Ǿ� ���� ��� �� �̵����� N+1�� ��.
		pigeonhole�� 0�� �ȴٴ� ������ �����Ƿ� ó�� ������ Ʋ����.
	Ʋ���� ��ü�� �������� ���� �Ǽ����� ��� ��ü�� �߸�����. �� �� �����ϰ� ��� �����ϴ� ���� �ʿ�(�ݷ�ã���)
*/

using namespace std;

const int inf = 5000000;

bool check_vector_contains(vector<int> &vec, int data) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == data)
			return true;
	}

	return false;
}

int main(void) {
	int TC;
	cin >> TC;

	for (int t = 0; t < TC; t++) {
		int N, M, W;
		cin >> N >> M >> W;

		int *point_weight = new int[N];
		point_weight[0] = 0;
		for (int i = 1; i < N; i++)
			point_weight[i] = inf;

		int **routes_weight = new int*[N];
		for (int i = 0; i < N; i++) {
			routes_weight[i] = new int[N];
			for (int j = 0; j < N; j++)
				routes_weight[i][j] = inf;
		}

		vector<vector<int>> available_routes(N);

		for (int i = 0; i < M; i++) {
			int point1, point2, weight;
			cin >> point1 >> point2 >> weight;
			
			if (routes_weight[point1-1][point2-1] > weight) {
				routes_weight[point1-1][point2-1] = weight;
				routes_weight[point2-1][point1-1] = weight;
				if (!check_vector_contains(available_routes[point1-1], point2-1)) {
					available_routes[point1-1].push_back(point2-1);
					available_routes[point2-1].push_back(point1-1);
				}
			}
		}

		for (int i = 0; i < W; i++) {
			int point1, point2, weight;
			cin >> point1 >> point2 >> weight;

			if (routes_weight[point1-1][point2-1] > -weight) {
				routes_weight[point1-1][point2-1] = -weight;
				if (!check_vector_contains(available_routes[point1-1], point2-1)) {
					available_routes[point1-1].push_back(point2-1);
				}
			}
		}

		bool isCycle = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < available_routes[j].size(); k++) {
					int start = j, end = available_routes[j][k],
						weight = routes_weight[j][available_routes[j][k]];
					
					if (point_weight[start] != inf
						&& point_weight[end] > point_weight[start] + weight) {
						point_weight[end] = point_weight[start] + weight;
						if (i == N-1) isCycle = true;
					}
				}
			}
		}

		if (isCycle)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	while (1);
	return 0;
}
