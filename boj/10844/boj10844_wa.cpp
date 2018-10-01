#include <iostream>
#include <queue>

using namespace std;

//����Լ�
//����: �����, �������, N
//1. ���� �� = N�̸�, 1�� ����
//2. ���� �� +- 1 �Լ��� �����Ͽ� ���ϰ��� ����
//3. ���� ���� ����
int main(void) {
	int N;

	//1. N�� �޴´�
	cin >> N;

	int num_of_stair = 0;
	//�ϴ� 1 �ϳ��� ���ؼ� ���ϴ� �κи� �ۼ��Ѵ�.
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
				//�� ������ ������ �Ǽ�, �������� ���� �� �ִ� ������ �ƴѵ� �������� ������ ��
				//������ ������踦 �� �ľ��ؾ� ��
				//Ư�� �̹����� �ϳ��� ��ü�� �ΰ��� �ɰ��ų� ���������� ������ �ΰ��� ������ ���̰����Ѵٴ°� �˾ƾ���
				//�ƴϸ� �������ִ� ���ǹ��� ������ ���� �Ѵٴ� ��Ģ�� ����°͵� ������
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

