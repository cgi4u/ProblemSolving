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

		int max = 0;
		for (int n = 1; n <= N; n++) {
			//케이스 분할
			for (int i = 0; i < n; i++) {
				cin >> cur[i];
				//첫 줄 아닐때만 하면됨
				if (n != 1) {
					if (i == 0) {
						cur[i] += before[i];
					}
					else if (i == n - 1) {
						cur[i] += before[i-1];
					}
					else {
						if (before[i - 1] > before[i]) {
							cur[i] += before[i - 1];
						}
						else
							cur[i] += before[i];
					}
				}
			}

			if (n != N) {
				//복사하기
				for (int i = 0; i < n; i++) {
					before[i] = cur[i];
				}
			}
			else {
				//최댓값 고르기
				for (int i = 0; i < n; i++) {
					if (cur[i] > max) max = cur[i];
				}
			}
		}

		cout << max << endl;
	}
}
