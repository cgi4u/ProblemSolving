#include <iostream>

using namespace std;

int main(void) {
	int x, y;
	int days_each_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	/*for (int i = 0; i < 7; i++)
		cout << week[i].c_str() << endl;*/

	cin >> x >> y;
	
	int days = 0;
	if (x == 1) {
		days += y - 1;
	}
	else {
		for (int i = 0; i < x - 1; i++)
			days += days_each_month[i];
		days = days + y - 1;
	}

	cout << week[days % 7].c_str();

	//while (1);
	return 0;
}