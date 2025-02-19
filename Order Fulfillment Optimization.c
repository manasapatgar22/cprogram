#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STAGES 5  

const char *stageNames[STAGES] = {
    "Order Receipt", "Inventory Allocation", "Packaging", "Shipping", "Delivery"
};

void optimizeOrderFulfillment(int delays[]) {
    int totalTime = 0;

    printf("\nOptimized Order Fulfillment Process:\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < STAGES; i++) {
        printf("%s: %d seconds\n", stageNames[i], delays[i]);
        totalTime += delays[i];
    }

    printf("\nTotal Order Fulfillment Time: %d seconds(%d hours)\n", totalTime,totalTime/60);
}

int main() {
    int delays[STAGES];

    srand(time(0));  

    printf("Enter the time delay for each stage (in seconds):\n");
    for (int i = 0; i < STAGES; i++) {
        printf("%s: ", stageNames[i]);
        scanf("%d", &delays[i]);
    }

    optimizeOrderFulfillment(delays);

    return 0;
}

/*Order Fulfillment Optimization:
Write a C program to simulate an optimization of the order fulfillment process in Amazon's platform. Assume that the process has 5 stages (e.g., order receipt, inventory allocation, packaging, shipping, etc.) and each stage has a time delay. Write a program to optimize the order fulfillment process using
a simulation algorithm.*/
