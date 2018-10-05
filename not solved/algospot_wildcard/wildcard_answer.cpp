#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//-1: �� �̰��
//0: ���ڳ��� ��ġ���� ����
//1: ��¥���� ��ġ��
int cache[101][101];

string W, file_name;

bool match(int w, int f) {
	int& ret = cache[w][f];	//referece Ÿ�� Ȱ����
	if (ret != -1) return ret;

	while (f < file_name.size() && w < W.size()
			&& (W[w] == '?' || file_name[f] == W[w])) {	// * �Ǵ� ����ġ�� ���� ������ ����ϴ°�
		f++; w++;
	}

	//����� ��
	//1. ������ �������� �� ���ڿ��� ����(��ġ)
	//2. W���� *�� ����. ���̸� �ٲ㰡�鼭 ���ȣ��� 1�� ������ ������ �ֳ� Ȯ��
	//3. �� ��: ���� �ٸ� ���ڰ� ����, ���ڿ��̳� ���� �� �� �ϳ��� �������� : ��������
	if (w == W.size() && f == file_name.size())
		ret = 1;	//����ϰ� �� �ϳ��� ������ �ΰ�, �� ������ ���缭 �Լ��� §��
	else if (W[w] == '*') {
		ret = 0;	//�̰� ������, �ƿ� �� �� ������ �ʱ�ȭ�� �ȵǴ� ��Ȳ�� ��������.
		for (int skip = 0; skip + f <= file_name.size(); skip++) {
			if (match(w + 1, f + skip) == 1)
				ret = 1;
		}
	}
	else
		ret = 0;

	//�翬������ ���ϰ��� � �� �������� �ʱ�ȭ�Ǿ�� �Ѵ�.

	return ret;
}

int main(void) {
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		char temp[101];

		cin >> W;

		int N;
		cin >> N;

		vector<string> file_list;
		for (int i = 0; i < N; i++) {
			for (int x = 0; x < 101; x++) {
				for (int y = 0; y < 101; y++)
					cache[x][y] = -1;
			}

			cin >> file_name;

			if (match(0, 0)) {
				file_list.push_back(file_name);
			}
		}

		sort(file_list.begin(), file_list.end());
		for (int i = 0; i < file_list.size(); i++)
			cout << file_list[i].c_str() << endl;

		file_list.clear();
	}

	return 0;
}