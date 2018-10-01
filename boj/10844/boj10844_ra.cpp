#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	vector<vector<int>> stair_each_nums;

	cin >> N;
	//이중 for문으로 length i일때의 수 j에서의 계단수 개수를 이전 계단수 개수를 통해 구한다 
	for (int i = 1; i <= N; i++) {
		vector<int> stair_nums_for_i;

		for (int j = 0; j <= 9; j++) {
			if (i == 1)
				stair_nums_for_i.push_back(1);
			else {
				//j에 해당하는 현 length에서의 계단수 개수를 구함
				int stair_num_for_j = 0;
				if (j > 0)
					stair_num_for_j += stair_each_nums[i - 2][j - 1];
				if (j < 9) 
					stair_num_for_j += stair_each_nums[i - 2][j + 1];
				stair_num_for_j %= 1000000000;

				stair_nums_for_i.push_back(stair_num_for_j);
			}
		}

		stair_each_nums.push_back(stair_nums_for_i);
		stair_nums_for_i.clear();
	}

	//lenth N일때 계단수 개수의 합을 구해서 리턴한다(0으로 시작 빼고)
	//실수 2: 마지막 출력부에서 덧셈을 실행한다는걸 까먹고 애꿎은 위를 보고 있었음
	//자신이 어떤 코드를 짯는지 머리에 확실히 넣고 어디서 문제있을지 알수있어야함
	int stair_nums_for_N = 0;
	for (int i = 1; i <= 9; i++)
		stair_nums_for_N = (stair_nums_for_N + stair_each_nums[N - 1][i]) % 1000000000;

	cout << stair_nums_for_N;

	//while (1);
	return 0;
}