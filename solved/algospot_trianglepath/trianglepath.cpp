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
			//���̽� ����
			for (int i = 0; i < n; i++) {
				cin >> cur[i];
				//ù �� �ƴҶ��� �ϸ��
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
				//�����ϱ�
				for (int i = 0; i < n; i++) {
					before[i] = cur[i];
				}
			}
			else {
				//�ִ� ����
				for (int i = 0; i < n; i++) {
					if (cur[i] > max) max = cur[i];
				}
			}
		}

		cout << max << endl;
	}
}
