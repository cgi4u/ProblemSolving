#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

//책이 틀렸다. 나도 틀리고
//이렇게 인덱스가 지저분할 상황은 왠만하면 만들어선 안된다. 
//차라리 1베이스 인덱스로 통일하는게 나을수도 있다.

int N, M;

int A[100];
int B[100];
int jlis_len[101][101];	// A[i]와 B[j]를 시작으로 '포함' 하는 JLIS의 최대길이
						//index 0은 처음에 아무것도 포함하지 않음.

//A[i]과 B[j]를 시작으로 '포함' 하는 JLIS의 최대길이를 구하는 함수
//이걸 0~N 0~M 돌려서 얻은 최대값이 최대길이
int jlis(int indexA, int indexB) {
	int& ret = jlis_len[indexA+1][indexB+1];	//메모이제이션
	if (ret != -1)	return ret;

	long long a, b;	//int64
	ret = 0;
	int a_off = 0, b_off = 0;
	//자기보다 큰 수가 뒤에 올 경우만 고려하기 위해 각 수를 뽑아낸다
	if (indexA == -1)
		a = INT64_MIN;
	else {
		a = A[indexA];
		ret += 1;
		a_off = 1;
	}

	if (indexB == -1)
		b = INT64_MIN;
	else {
		b = B[indexB];
		ret += 1;
		b_off = 1;
	}

	long long max_ab = max(a, b);
	//B 인덱스는 그대로 두고 A 인덱스 찾을 수 있는 것 중에 둘중 큰수보다 큰 케이스를 모두 호출
	for (int nextA = indexA+1; nextA < N; nextA++) {
		if (max_ab < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + a_off);	//무조건 1을 더해서는 안된다. -1케이스를 포함한 만큼 문자가 추가되지 않는 케이스도 있다.
	}

	//A 인덱스는 그대로 두고 B 인덱스 찾을 수 있는 것 중에 둘중 큰수보다 큰 케이스를 모두 호출
	for (int nextB = indexB + 1; nextB < M; nextB++) {
		if (max_ab < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + b_off);	//무조건 1을 더해서는 안된다. -1케이스를 포함한 만큼 문자가 추가되지 않는 케이스도 있다.
	}

	return ret;
}

int main(void) {
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		cin >> N;
		cin >> M;

		for (int i = 0; i < N+1; i++) {
			for (int j = 0; j < M+1; j++)
				jlis_len[i][j] = -1;
		}

		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];

		int max_len = jlis(-1, -1);
		cout << max_len << endl;
	}
}