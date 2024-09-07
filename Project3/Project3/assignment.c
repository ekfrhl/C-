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


int main() {

	int number = 0;
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		number = rand();
		printf("number=%d\n", number);
		return 0;
	}
	return 0;
}


int main() {

	int number[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		number[i] = rand();
		printf("number=%d\n", number[i]);
	}
	return 0;
}
int main() {

	int number[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		number[i] = (rand()%100)+1;
	}
		
	for (int i = 0; i < 10; i++) {
		printf("number=%d\n", number[i]);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100 //define을 통한 노가다 방지
int main() {

	int number[SIZE];
	int total=0;
	float average=0.0;
	int max;
	int min;
	

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand()%100)+1;
	}
	
	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 5 == 0)printf("\n");
	}
	
	for (int i = 0; i < SIZE; i++) {
		total += number[i];
	}
	average = (float)total / SIZE;
	
	max = number[0];
	min = number[0];
	
	
	for (int i = 1; i < SIZE; i++) {
		if (max < number[i])
			max = number[i];
		else if (min > number[i])
			min = number[i];
	}
	
	printf("\naverage=%f\n", average);
	printf("max=%d\n",max);
	printf("min=%d\n", min);
	return 0;
} 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main() {

	int number[SIZE];
	int most;
	int temp;
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand()%10000)+1;
	}
	
	for (int i = 0; i < SIZE-1; i++) {
		most = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (number[most] < number[j]) {
				most = j;
			}
			temp = number[i];
			number[i] = number[most];
			number[most]=temp;
		}
	}
	
	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 5 == 0)printf("\n");
	}
	return 0;
}


