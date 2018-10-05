#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char W[101];
char file_name[101];
int w_len;
int f_len;

//�ڱ� ���ڵ� match�ǰ� ���� ���ڵ� ��� match �Ǹ� 1�� ��ȯ�ϴ� �Լ�
int match(int i, int j) {
	int ret;

	//����
	//����: *�� �� �������� ������ 0���ڿ� �����ϴ� ��Ȳ�� ������, ��Ī�Ǵ� ���ڿ��ε��� �ι�° ���ǿ� �ɸ���.
	if (i == w_len && j == f_len)
		return 1;
	else if (i == w_len || j == f_len)
		return 0;

	if (W[i] == '*') {
		//*�� ������ �� �ִ� ��� ���̸� �����ؼ� ��ġ�Ǵ°� �ϳ��� ������ ��ġ��.
		ret = 0;
		if (i + 1 == w_len) ret = 1;
		else {
			for (int k = j + 1; k <= f_len; k++) {	//������ ����: ���ʿ� ���Ǹ� �߸� �����ߴ�. *�� 0���ڿ� �ش��� �� �ִµ�, 1�� ������Ų�ͺ��� �����ߴ�.
				if (match(i + 1, k) == 1) {
					ret = 1;
					break;
				}
			}
		}
	}
	else {
		//���� ��ġ���� ���� ��ġ����� ��� ��ġ�Ǿ�� 1 ����
		ret = match(i + 1, j + 1);
		if (W[i] != '?' && W[i] != file_name[j])
			ret = 0;
	}
	
	return ret;
}

int main(void) {
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		cin >> W;
		w_len = strlen(W);

		int N; 
		cin >> N;

		vector<string> file_list;
		for (int i = 0; i < N; i++) {
			cin >> file_name;
			f_len = strlen(file_name);

			int is_match = match(0, 0);
			if (is_match == 1) {
				string file_name_str(file_name);
				file_list.push_back(file_name_str);
			}
		}

		sort(file_list.begin(), file_list.end());
		for (int i = 0; i < file_list.size(); i++)
			cout << file_list[i].c_str() << endl;

		file_list.clear();
	}

	return 0;
}