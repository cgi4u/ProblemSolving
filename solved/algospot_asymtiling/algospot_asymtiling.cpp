#include <iostream>

using namespace std;

int main(void) {
	int T;
	int dp_all[101];
	int dp_sym[101];

	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		// Initialization
		dp_all[1] = 1; dp_all[2] = 2;
		dp_sym[0] = 1; dp_sym[1] = 1; dp_sym[2] = 2;

		for (int i = 3; i <= n; i++) {
			// Calculate the number of all cases
			dp_all[i] = (dp_all[i - 1] + dp_all[i - 2]) % 1000000007;

			// Calculate the number of symmetric cases
			dp_sym[i] = dp_sym[i - 2];
			if (i >= 4)
				dp_sym[i] = (dp_sym[i] + dp_sym[i - 4]) % 1000000007;
		}
	
		// All cases - Symmetric cases = Asymmetric cases
		int ans = dp_all[n] - dp_sym[n] < 0 ? dp_all[n] - dp_sym[n] + 1000000007 : dp_all[n] - dp_sym[n];
		cout << ans << endl;
	}
	
	return 0;
}