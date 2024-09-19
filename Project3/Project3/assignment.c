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
//////////////////////////////////////////////////////////////////////////////////////////09.19
#include <stdio.h>
#define max 100
int main()
{
    int call;
    int call_2;
    int numProducts=5;
    int ids[MAX];        
    int stocks[MAX];     
    int sales[MAX];      
    int totalStock = 0, totalSales = 0;
    int i;
    double totalRate = 0.0;
    int maxSales = -1, minSales = MAX + 1;
    int maxSalesID = 0, minSalesID = 0;
    
    
    
    
    while(1){
    printf("원하는 메뉴를 선택하시오.(1. 입고, 2. 판매, 3.상품현황, 4. 종료)\n");
    scanf("%d", &call);
    }
    if(call==1){
        printf("입고수량 종류 선택: 1.전체 상품 입고 수량 입력/t 2. 개별 상품 입력 ");
        scanf("%d",&call_2);
        if(call_2==1){
            for(int i=0; i<numProducts; i++)
            scanf("%d",&stocks[i]);
        }
        if else(call_2==2){
            printf("상품 ID:");
            scanf("%d",&ids);
            printf("입고수량:");
            scanf("%d",&stocks);
        }
      if(call==2){
        printf("판매수량 종류 선택: 1. 전체 상품 판매수량 입력 /t 2. 개별 상품 입력");
        scanf("%d",&call_2);
        if(call_2==1){
            for(int i=0; i<numProducts; i++)
            scanf("%d",&sales[i]);
        }
          if else(call_2==2){
            printf("상품 ID:");
            scanf("%d",&ids);
            printf("입고수량:");
            scanf("%d",&stocks);
      }
      
    }
    return 0;
}

