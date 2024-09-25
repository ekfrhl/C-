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
/////////////////////////////////////////////////////////PROJECT01///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#define MAX 100

int main() {
    int numProducts;
    int ids[MAX];
    int stocks[MAX];
    int sales[MAX];
    int i, id, totalStock = 0;

    scanf_s("%d", &numProducts);

    if (numProducts < 1 || numProducts > 100) {
        printf("잘못된 상품 종류 수입니다.\n");
        return 1;
    }

 //입고할 수량
    for (i = 0; i < numProducts; i++) {
        scanf_s("%d", &stocks[i]); 
        ids[i] = i + 1;  
    }

    for (i = 0; i < numProducts; i++) {
        scanf_s("%d", &sales[i]);
        stocks[i] -= sales[i]; 
        if (stocks[i] < 0) 
            stocks[i] = 0;  
    }

    scanf_s("%d", &id);

    for (i = 0; i < numProducts; i++) {
        if (ids[i] == id) {
            printf("%d\n", stocks[i]);
        }
        totalStock += stocks[i];
    }

    for (i = 0; i < numProducts; i++) {
        printf("%d ", stocks[i]);
    }
    return 0;
}
/////////////////////////////////////////////////////////PROJECT02////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#define MAX 100

int main() {
    int numProducts;
    int ids[MAX];        
    int stocks[MAX];     
    int sales[MAX];      
    int totalStock = 0, totalSales = 0;
    int i;
    double totalRate = 0.0;
    int maxSales = -1, minSales = MAX + 1;
    int maxSalesID = 0, minSalesID = 0;

    
    scanf_s("%d", &numProducts);

    
    for (i = 0; i < numProducts; i++) {
        scanf_s("%d", &stocks[i]);
        ids[i] = i + 1;  
        totalStock += stocks[i];  
    }


    for (i = 0; i < numProducts; i++) {
        scanf_s("%d", &sales[i]);
        totalSales += sales[i];  


        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxSalesID = ids[i];
        }
        if (sales[i] < minSales) {
            minSales = sales[i];
            minSalesID = ids[i];
        }


        stocks[i] -= sales[i];
    }

    
    printf("재고수량:");
    for (i = 0; i < numProducts; i++) {
        printf("%d", stocks[i]);
    }
    printf("\n");

    
    totalRate = ((double)totalSales / totalStock) * 100;
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSales, totalRate);

    
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxSalesID, maxSales);

    
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minSalesID, minSales);

    
    for (i = 0; i < numProducts; i++) {
        if (stocks[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", ids[i], stocks[i]);
        }
    }

    return 0;
}
/////
#include <stdio.h>

void test(int* p, char* cp) {
	printf(" test : p =%p, cp = %p\n", p, cp);
	printf(" test : *p =%p, *cp = %p\n", *p, *cp);
	* p = 60;
	*cp = '$';
}
int main(void) {

	int a = 50;
	char ch = '*';
	printf("main  : a =%d, ch = %d\n", a, ch);
	test(&a, &ch);
	printf("main  : a =%d, ch = %d\n", a, ch);
	return 0;
}
////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void inputRandomarray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		*(array + i) = rand() % 100;
	}
}



int main() {
	int number[SIZE];

	srand(time(NULL));
	inputRandomarray(&number[0], SIZE);

	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	return 0;
}
//////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void inputRandomarray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		*(array + i) = rand() % 100;
	}
}
void printArray(int* array, int size) {

	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", *(array+i));
		if ((i + 1) % 10 == 0) printf("\n");
	}
}



int main() {
	int number[SIZE];

	srand(time(NULL));
	inputRandomarray(&number[0], SIZE);

	
	return 0;
}
/////////////////////////////////////////PROJECT03/////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM_PRODUCTS 5
int main() {
    int stock[NUM_PRODUCTS] = { 0 };  
    int sales[NUM_PRODUCTS] = { 0 }; 
    int incoming;  
    int sell;      
    int id, total_sales = 0;  
    int choice;   
    float sales_rate;

    while (1) {
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택: ");
            int sub_choice;
            scanf("%d", &sub_choice);

            if (sub_choice == 1) {
               
                printf("입고 수량 (5개 상품): ");
                for (int i = 0; i < NUM_PRODUCTS; i++) {
                    scanf("%d", &incoming);
                    stock[i] += incoming;  
                }
            }
            else if (sub_choice == 2) {
                
                printf("상품 ID (0~4): ");
                scanf("%d", &id);
                printf("입고 수량: ");
                scanf("%d", &incoming);
                stock[id] += incoming;  
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
        }
        else if (choice == 2) {
            printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택: ");
            int sub_choice;
            scanf("%d", &sub_choice);

            if (sub_choice == 1) {
                
                printf("판매 수량 (5개 상품): ");
                for (int i = 0; i < NUM_PRODUCTS; i++) {
                    scanf("%d", &sell);
                    if (stock[i] >= sell) {
                        stock[i] -= sell; 
                        sales[i] += sell;  
                        total_sales += sell;  
                    }
                    else {
                        printf("상품 ID %d: 재고가 부족합니다.\n", i);
                    }
                }
            }
            else if (sub_choice == 2) {
                
                printf("상품 ID (0~4): ");
                scanf("%d", &id);
                printf("판매 수량: ");
                scanf("%d", &sell);
                if (stock[id] >= sell) {
                    stock[id] -= sell;  
                    sales[id] += sell;  
                    total_sales += sell;  
                }
                else {
                    printf("재고가 부족합니다.\n");
                }
            }
            else {
                printf("잘못된 선택입니다.\n");
            }
        }
        else if (choice == 3) {
     
            printf("재고수량: ");
            for (int i = 0; i < NUM_PRODUCTS; i++) {
                printf("%d ", stock[i]);
            }
            printf("\n총 판매량: %d\n", total_sales);
            sales_rate = (float)total_sales / (NUM_PRODUCTS * 5) * 100;  
            printf("판매율: %.2f%%\n", sales_rate);

          
            int max_sales = 0, min_sales = 10000, max_id = 0, min_id = 0;
            for (int i = 0; i < NUM_PRODUCTS; i++) {
                if (sales[i] > max_sales) {
                    max_sales = sales[i];
                    max_id = i;
                }
                if (sales[i] < min_sales) {
                    min_sales = sales[i];
                    min_id = i;
                }
            }
            printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", max_id, max_sales);
            printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", min_id, min_sales);

            
            for (int i = 0; i < NUM_PRODUCTS; i++) {
                if (stock[i] <= 2) {
                    printf("상품 ID %d: 재고부족(%d)\n", i, stock[i]);
                }
            }
        }
        else if (choice == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}

///////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char str1[5] = { 'a','b','c','d','\0'};
	char str2[5] = "abcd";
	char str3[5];

	printf("%s\n %s\n", str1, str2);
	scanf("%s", str3);
	printf("%s", str3);
	return 0;
}
int main() {

	char str1[5] = { 'a','b','c','d','\0' };
	char str2[5] = "abcd";

	printf("%s\n %s\n", str1, str2);



	return 0;
}
#include <stdio.h>

int main(void) {

	char message[100] = "hello world\n";
	
	printf("%s", message); 
	&message= "hello";
	printf("%s", message);
	return 0;
}



