#include <iostream>

using namespace std;

double custom_pow(double x, int y) {
	double ret = 1.0;

	for (int i = 0; i < y; i++)
		ret *= x;

	return ret;
}

int main(void) {
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		int n, m;
		cin >> n >> m;

		int least = n - m;
		double ans;

		//�޸������̼�
		double before;
		double cur;

		if (least <= 0) {
			ans = 1.0;
		}
		else if (least > m) {
			ans = 0.0;
		}
		else {
			//�ʱⰪ ����
			//ans = before = powl(0.75, m);	ǥ���� �ƴ϶� �����µ�...
			ans = before = custom_pow(0.75, m);

			for (int i = m - 1; i >= least; i--) {
				cur = before * (i + 1) / (m - i) / 3.0;
				ans += cur;
				
				before = cur;
			}
		}
		
		//n�ڸ� �Ҽ��� ������� �˾Ƶα�
		cout << fixed;
		cout.precision(10);
		cout << ans << endl;
	}

	return 0;
}