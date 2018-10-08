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

		//메모이제이션
		double before;
		double cur;

		if (least <= 0) {
			ans = 1.0;
		}
		else if (least > m) {
			ans = 0.0;
		}
		else {
			//초기값 설정
			//ans = before = powl(0.75, m);	표준이 아니라 못쓰는듯...
			ans = before = custom_pow(0.75, m);

			for (int i = m - 1; i >= least; i--) {
				cur = before * (i + 1) / (m - i) / 3.0;
				ans += cur;
				
				before = cur;
			}
		}
		
		//n자리 소수점 고정방식 알아두기
		cout << fixed;
		cout.precision(10);
		cout << ans << endl;
	}

	return 0;
}