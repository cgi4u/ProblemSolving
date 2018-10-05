#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//?�� � ���ڿ͵� ��Ī
//*�� 0���� �̻��� � ���ڿ����� ��ġ
int main(void) {
	int C;

	cin >> C;
	
	for (int c = 0; c < C; c++) {
		char W[101];
		int N;

		cin >> W;
		cin >> N;

		//char files[50][101];	//�����ð��� ���̷��� �������� ū���� �ƴ��� �����迭�� ���°� ����
		//���ʿ� �����غ��� �迭�� ���� ������ �ʿ䰡 ����.
		vector<string> match_files;
		for (int i = 0; i < N; i++) {
			char file[101];

			cin >> file;

			//*�� �ִ� ���, ��ġ�Ǵ� ���ڰ� ���������� ���ڸ� ��ŵ �����ϴ�
			int W_len = strlen(W);
			int file_len = strlen(file);
			int j, k;

			//������ؼ� Ʋ���� �׽�Ʈ���̽��� �����Ѵٰ� ������ �� ���µ�... �˰��� ���鿡�� solid�ϰ� ��¥�� ��Ǭ��
			for (j = 0, k = 0; j < W_len && k < file_len; ) {
				if (W[j] == '*') {
					if (j == W_len - 1) {
						k = file_len;
						break;
					}

					j += 1;
					while (W[j] != '?' && W[j] != file[k] && k < file_len) k++;
				}

				if (W[j] != '?' && W[j] != file[k]) break;

				if (j < W_len && k < file_len) 
					k++; j++;	
			}

			//�̷��� �������� ���̽��� �ٿ��� �ذ��ϴ°� ���� �׽�Ʈ�� ���������� �Ұ����ϴ�.
			if ((j == W_len || W[j] == '*') && k == file_len) {
				string file_str(file);
				match_files.push_back(file_str);
			}
		}

		sort(match_files.begin(), match_files.end());
		for (int i = 0; i < match_files.size(); i++)
			cout << match_files[i].c_str() << endl;
		match_files.clear();
	}

	return 0;
}

//������â, ������ ��.