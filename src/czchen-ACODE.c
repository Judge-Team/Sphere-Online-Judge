#include <stdio.h>

int get_total(long long * total)
{
	char previous_digit = 0;

	// get first digit
	scanf("%c", &previous_digit);
	if ('0' == previous_digit)
		return 0;

	long long current_total = 1; // T(n)
	long long previous_total = 1; // T(n-1)
	long long previous_2_total = 1; // T(n-2)
	char current_digit = 0;

	for (;;) { // Use formula to get T(n)
		scanf("%c", &current_digit);

		if ('\n' == current_digit) {
			break;
		}

		// At this time, current_total stored T(n-1).
		if ('0' == current_digit) {
			current_total = 0;
		}

		if ('1' == previous_digit || ('2' == previous_digit && current_digit <= '6')) {
			current_total += previous_2_total;
		}

		previous_2_total = previous_total;
		previous_total = current_total;
		previous_digit = current_digit;
	}

	*total = current_total;

	return 1;
}

int main()
{
	for (;;) {
		long long total = 0;
		if (!get_total(&total)) {
			break;
		}
		printf("%Ld\n", total);
	}

	return 0;
}
