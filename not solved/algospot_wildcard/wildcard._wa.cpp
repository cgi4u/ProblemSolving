#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//?는 어떤 문자와도 매칭
//*는 0글자 이상의 어떤 문자열에도 일치
int main(void) {
	int C;

	cin >> C;
	
	for (int c = 0; c < C; c++) {
		char W[101];
		int N;

		cin >> W;
		cin >> N;

		//char files[50][101];	//구현시간을 줄이려면 어지간히 큰수가 아닌한 고정배열을 쓰는게 좋다
		//애초에 생각해보면 배열을 굳이 저장할 필요가 없다.
		vector<string> match_files;
		for (int i = 0; i < N; i++) {
			char file[101];

			cin >> file;

			//*가 있는 경우, 매치되는 문자가 있을때까지 문자를 스킵 가능하다
			int W_len = strlen(W);
			int file_len = strlen(file);
			int j, k;

			//디버깅해서 틀리는 테스트케이스가 존재한다고 생각할 수 없는데... 알고리즘 측면에서 solid하게 못짜면 못푼다
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

			//이렇게 덕지덕지 케이스를 붙여서 해결하는건 실제 테스트때 현실적으로 불가능하다.
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

//엉망진창, 쓰레기 답.