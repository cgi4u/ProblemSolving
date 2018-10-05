#include <stdio.h>

int main(void) {
	int month, date;

	int intv;

	scanf("%d %d", &month, &date);
	intv = (month - 1) * 31;

	if (month > 11) {
		intv -= 7;
	}
	else if (month > 9) {
		intv -= 6;
	}
	else if (month > 6) {
		intv -= 5;
	}
	else if (month > 4) {
		intv -= 4;
	}
	else if (month > 2) {
		intv -= 3;
	}
	intv += date - 1;

	switch (intv % 7) {
	case 0: printf("MON"); break;
	case 1: printf("TUE"); break;
	case 2: printf("WED"); break;
	case 3: printf("THU"); break;
	case 4: printf("FRI"); break;
	case 5: printf("SAT"); break;
	case 6: printf("SUN"); break;
	}
}