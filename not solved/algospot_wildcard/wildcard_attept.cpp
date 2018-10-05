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
			int w_len = strlen(W);
			int file_len = strlen(file);
			int w_idx = 0, f_idx = 0;

			//변수가 2개인 for문은 가급적 쓰지 않는다, 그냥 while로 대체
			//조건이 복잡한 경우에는 차라리 반복문 조건을 나중에 쓴다
			while (1) {
				if (W[w_idx] == '*') {
					while (W[w_idx] != '*') w_idx++;
					if (w_idx == w_len) {
						//매칭됨
					}
					else {
						while ()	// 문제: *?인 경우는 정말로 *가 몇개 잡아먹을지 알 수가 없다.
									//그래서 문제처럼 정말로 모든 경우의 수를 재귀로 실행해야 한다.
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
