#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	vector<vector<int>> stair_each_nums;

	cin >> N;
	//���� for������ length i�϶��� �� j������ ��ܼ� ������ ���� ��ܼ� ������ ���� ���Ѵ� 
	for (int i = 1; i <= N; i++) {
		vector<int> stair_nums_for_i;

		for (int j = 0; j <= 9; j++) {
			if (i == 1)
				stair_nums_for_i.push_back(1);
			else {
				//j�� �ش��ϴ� �� length������ ��ܼ� ������ ����
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

	//lenth N�϶� ��ܼ� ������ ���� ���ؼ� �����Ѵ�(0���� ���� ����)
	//�Ǽ� 2: ������ ��ºο��� ������ �����Ѵٴ°� ��԰� �ֲ��� ���� ���� �־���
	//�ڽ��� � �ڵ带 ­���� �Ӹ��� Ȯ���� �ְ� ��� ���������� �˼��־����
	int stair_nums_for_N = 0;
	for (int i = 1; i <= 9; i++)
		stair_nums_for_N = (stair_nums_for_N + stair_each_nums[N - 1][i]) % 1000000000;

	cout << stair_nums_for_N;

	//while (1);
	return 0;
}