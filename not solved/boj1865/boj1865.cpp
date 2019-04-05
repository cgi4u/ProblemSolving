#include <iostream>
#include <vector>

/*
	오독 실수:
		문제는 '어떤 한 점'에 대한 것. 특정 점 0에 대한 것이 아님
		이게 잘못되어 문제 접근 자체가 꼬여버림
	개념 실수: 
		루프를 구성하는 원소의 개수는 최대 N개고 그 내에 점 0이 존재해야하므로 최대 N번 경로 이동 내에서 돌아온다고 생각.
		하지만 반례로 N-1개의 원소들이 루프를 이루고 있고, 그 루프의 한 점과 0이 연결되어 있을 경우 총 이동수가 N+1이 됨.
		pigeonhole이 0이 된다는 보장이 없으므로 처음 생각이 틀렸음.
	틀린것 자체는 오독으로 인한 실수지만 사고 자체도 잘못했음. 좀 더 엄밀하게 사고를 검증하는 것이 필요(반례찾기등)
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
