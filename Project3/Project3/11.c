#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int number = 0;

	for (int i = 0; i < 10; i++) {
		number = rand();
		printf("number=%d\n", number);
		return 0;
	}
