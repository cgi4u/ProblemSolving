#include <iostream>

using namespace std;

int main(void) {
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		int N;
		cin >> N;

		int before[100];
		int cur[100];

		int before_count[100];
		int cur_count[100];

		int max = 0;
		int max_count;

		before_count[0] = 1;
		cur_count[0] = 1;		//초기화는 방어적으로
		for (int n = 1; n <= N; n++) {
			//케이스 분할
			for (int i = 0; i < n; i++) {
				cin >> cur[i];

				//첫 줄 아닐때만 하면됨
				if (n != 1) {
					if (i == 0) {
						cur[i] += before[i];
						cur_count[i] = before_count[i];
					}
					else if (i == n - 1) {
						cur[i] += before[i-1];
						cur_count[i] = before_count[i-1];
					}
					else {
						if (before[i - 1] > before[i]) {
							cur[i] += before[i - 1];
							cur_count[i] = before_count[i - 1];
						}
						else if (before[i - 1] == before[i]) {
							cur[i] += before[i];
							cur_count[i] = before_count[i - 1] + before_count[i];
						}
						else {
							cur[i] += before[i];
							cur_count[i] = before_count[i];
						}
					}
				}
			}

			for (int i = 0; i < n; i++) {
				before[i] = cur[i];
				before_count[i] = cur_count[i];
			}
		}

		for (int i = 0; i < N; i++) {
			if (cur[i] > max) {
				max = cur[i];
				max_count = cur_count[i];
			}
			else if (cur[i] == max)
				max_count += cur_count[i];
		}

		cout << max_count << endl;
	}
}
