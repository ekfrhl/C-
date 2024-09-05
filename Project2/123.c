#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int num = 0;
	

	for (int i = 0; i < 10; i++) {
		num = rand();
		printf("num=%d\n", num);
	}
	return 0;
}