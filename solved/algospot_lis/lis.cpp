#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		int N;
		cin >> N;

		int max_len = 0;
		int nums[500];
		int contain_max_lens[500];
		for (int i = 0; i < N; i++) {
			cin >> nums[i];

			if (i == 0) {
				max_len += 1;
				contain_max_lens[i] = 1;
			}
			else {
				contain_max_lens[i] = 1;	//자신만 포함하는 경우
				for (int j = i - 1; j >= 0; j--) {
					if (nums[j] < nums[i])	//작을 경우에만
						contain_max_lens[i] = max(contain_max_lens[i], contain_max_lens[j] + 1);	//최대길이랑 현재최대길이를 비교한다
				}

				max_len = max(max_len, contain_max_lens[i]);
			}
		}

		cout << max_len << endl;
	}
}