#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

//å�� Ʋ�ȴ�. ���� Ʋ����
//�̷��� �ε����� �������� ��Ȳ�� �ظ��ϸ� ���� �ȵȴ�. 
//���� 1���̽� �ε����� �����ϴ°� �������� �ִ�.

int N, M;

int A[100];
int B[100];
int jlis_len[101][101];	// A[i]�� B[j]�� �������� '����' �ϴ� JLIS�� �ִ����
						//index 0�� ó���� �ƹ��͵� �������� ����.

//A[i]�� B[j]�� �������� '����' �ϴ� JLIS�� �ִ���̸� ���ϴ� �Լ�
//�̰� 0~N 0~M ������ ���� �ִ밪�� �ִ����
int jlis(int indexA, int indexB) {
	int& ret = jlis_len[indexA+1][indexB+1];	//�޸������̼�
	if (ret != -1)	return ret;

	long long a, b;	//int64
	ret = 0;
	int a_off = 0, b_off = 0;
	//�ڱ⺸�� ū ���� �ڿ� �� ��츸 ����ϱ� ���� �� ���� �̾Ƴ���
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
	//B �ε����� �״�� �ΰ� A �ε��� ã�� �� �ִ� �� �߿� ���� ū������ ū ���̽��� ��� ȣ��
	for (int nextA = indexA+1; nextA < N; nextA++) {
		if (max_ab < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + a_off);	//������ 1�� ���ؼ��� �ȵȴ�. -1���̽��� ������ ��ŭ ���ڰ� �߰����� �ʴ� ���̽��� �ִ�.
	}

	//A �ε����� �״�� �ΰ� B �ε��� ã�� �� �ִ� �� �߿� ���� ū������ ū ���̽��� ��� ȣ��
	for (int nextB = indexB + 1; nextB < M; nextB++) {
		if (max_ab < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + b_off);	//������ 1�� ���ؼ��� �ȵȴ�. -1���̽��� ������ ��ŭ ���ڰ� �߰����� �ʴ� ���̽��� �ִ�.
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