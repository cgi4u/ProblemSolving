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

//자기 문자도 match되고 뒤의 문자도 모두 match 되면 1을 반환하는 함수
int match(int i, int j) {
	int ret;

	//기저
	//문제: *가 맨 마지막에 나오고 0문자에 대응하는 상황이 나오면, 매칭되는 문자열인데도 두번째 조건에 걸린다.
	if (i == w_len && j == f_len)
		return 1;
	else if (i == w_len || j == f_len)
		return 0;

	if (W[i] == '*') {
		//*가 차지할 수 있는 모든 길이를 시험해서 매치되는게 하나라도 있으면 매치다.
		ret = 0;
		if (i + 1 == w_len) ret = 1;
		else {
			for (int k = j + 1; k <= f_len; k++) {	//문제의 이유: 애초에 정의를 잘못 생각했다. *는 0문자에 해당할 수 있는데, 1을 증가시킨것부터 시작했다.
				if (match(i + 1, k) == 1) {
					ret = 1;
					break;
				}
			}
		}
	}
	else {
		//다음 매치대상과 현재 매치대상이 모두 매치되어야 1 리턴
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