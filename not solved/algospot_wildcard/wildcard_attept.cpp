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
			int w_len = strlen(W);
			int file_len = strlen(file);
			int w_idx = 0, f_idx = 0;

			//������ 2���� for���� ������ ���� �ʴ´�, �׳� while�� ��ü
			//������ ������ ��쿡�� ���� �ݺ��� ������ ���߿� ����
			while (1) {
				if (W[w_idx] == '*') {
					while (W[w_idx] != '*') w_idx++;
					if (w_idx == w_len) {
						//��Ī��
					}
					else {
						while ()	// ����: *?�� ���� ������ *�� � ��Ƹ����� �� ���� ����.
									//�׷��� ����ó�� ������ ��� ����� ���� ��ͷ� �����ؾ� �Ѵ�.
					}
				}
				else {
					if ((W[w_idx] != '?') && (W[w_idx] != file[f_idx]))
						break;
				}
			}
		}

	return 0;
}
