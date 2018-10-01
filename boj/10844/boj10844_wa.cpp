#include <iostream>
#include <queue>

using namespace std;

//재귀함수
//인자: 현재수, 현재길이, N
//1. 현재 수 = N이면, 1을 리턴
//2. 현재 수 +- 1 함수를 수행하여 리턴값을 합함
//3. 더한 수를 리턴
int main(void) {
	int N;

	//1. N을 받는다
	cin >> N;

	int num_of_stair = 0;
	//일단 1 하나에 대해서 구하는 부분만 작성한다.
	queue<int> cur_nums;
	queue<int> cur_lens;

	for (int i = 1; i <= 9; i++) {
		cur_nums.push(i);
		cur_lens.push(1);

		while (!cur_nums.empty()) {
			int cur_num = cur_nums.front();
			int cur_len = cur_lens.front();

			if (cur_len == N) {
				num_of_stair += 1;

				if (num_of_stair >= 1000000000) {
					num_of_stair %= 1000000000;
				}
			}
			else {
				//또 저번과 동일한 실수, 공동으로 묶을 수 있는 조건이 아닌데 공동으로 묶으려 함
				//조건의 상관관계를 잘 파악해야 함
				//특히 이번에는 하나의 객체를 두개로 쪼갠거나 마찬가지기 때문에 두개는 무조건 같이가야한다는걸 알아야함
				//아니면 나눠저있는 조건문은 무조건 띄어쓰기 한다는 규칙을 세우는것도 좋을듯
				if (cur_num > 0) {
					cur_nums.push(cur_num - 1);
					cur_lens.push(cur_len + 1);
				}

				if (cur_num < 9) {
					cur_nums.push(cur_num + 1);
					cur_lens.push(cur_len + 1);
				}
			}

			cur_lens.pop();
			cur_nums.pop();
		}
	}

	cout << num_of_stair;

	while (1);
	return 0;
}

