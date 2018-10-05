#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//-1: 답 미계산
//0: 문자끼리 매치되지 않음
//1: 문짜끼리 매치됨
int cache[101][101];

string W, file_name;

bool match(int w, int f) {
	int& ret = cache[w][f];	//referece 타입 활용방법
	if (ret != -1) return ret;

	while (f < file_name.size() && w < W.size()
			&& (W[w] == '?' || file_name[f] == W[w])) {	// * 또는 불일치가 나올 때까지 계속하는것
		f++; w++;
	}

	//경우의 수
	//1. 패턴이 종료했을 때 문자열도 종료(일치)
	//2. W에서 *이 나옴. 길이를 바꿔가면서 재귀호출로 1이 나오는 리턴이 있나 확인
	//3. 그 외: 서로 다른 문자가 나옴, 문자열이나 패턴 둘 중 하나가 먼저끝남 : 대응안함
	if (w == W.size() && f == file_name.size())
		ret = 1;	//깔끔하게 단 하나의 기저를 두고, 그 기저에 맞춰서 함수를 짠다
	else if (W[w] == '*') {
		ret = 0;	//이게 없으면, 아예 이 절 내에서 초기화가 안되는 상황이 벌어진다.
		for (int skip = 0; skip + f <= file_name.size(); skip++) {
			if (match(w + 1, f + skip) == 1)
				ret = 1;
		}
	}
	else
		ret = 0;

	//당연하지만 리턴값은 어떤 절 내에서라도 초기화되어야 한다.

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