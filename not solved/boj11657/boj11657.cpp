#include <iostream>
#include <vector>

/*
	�˰��� ������ ����� �ؼ� Ǯ�������� �ڲ� ������ ���µ�, �ܼ��� �Ǽ�����.
	bus_stop_weight[bus_routes[i].start] == inf �� bus_routes[i].start == inf�� ����Ҵ���.
	ó�� ©������ �����ϰ� ¥�°��� �߿��ϰ�, �Ǽ��ߴ��� ���������� �ʰ� �м��ؾ� ��.
	�� �ٺ������δ� �򰥸��� �ʰ� �������� ������ ������ ����ȭ������ ������ ��.
*/

using namespace std;

const int inf = 5000000;

struct bus_route {
	int start;
	int end;
	int weight;
};

int main(void) {
	int N, M;
	cin >> N >> M;

	int *bus_stop_weight = new int[N];
	bus_stop_weight[0] = 0;
	for (int i = 1; i < N; i++)
		bus_stop_weight[i] = inf;

	vector<bus_route> bus_routes;

	for (int i = 0; i < M; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		bus_route new_bus_route;
		new_bus_route.start = start - 1;
		new_bus_route.end = end - 1;
		new_bus_route.weight = weight;

		bus_routes.push_back(new_bus_route);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (bus_stop_weight[bus_routes[j].start] == inf)
				continue;

			if (bus_stop_weight[bus_routes[j].start] + bus_routes[j].weight <
				bus_stop_weight[bus_routes[j].end])
				bus_stop_weight[bus_routes[j].end] = bus_stop_weight[bus_routes[j].start] + bus_routes[j].weight;
		}
	}

	for (int i = 0; i < M; i++) {
		if (bus_stop_weight[bus_routes[i].start] == inf)
			continue;

		if (bus_stop_weight[bus_routes[i].start] + bus_routes[i].weight <
			bus_stop_weight[bus_routes[i].end]) {
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 1; i < N; i++) {
		if (bus_stop_weight[i] == inf)
			cout << -1 << endl;
		else
			cout << bus_stop_weight[i] << endl;
	}

	return 0;
}
