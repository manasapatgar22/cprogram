#include <stdio.h>

#define WAREHOUSES 10  
#define MAX_CAPACITY 100  

void optimizeInventory(int items[], int warehouses[], int n) {
    int dp[WAREHOUSES + 1][MAX_CAPACITY + 1];

    for (int i = 0; i <= WAREHOUSES; i++) {
        for (int j = 0; j <= MAX_CAPACITY; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (items[i - 1] <= j)
                dp[i][j] = (warehouses[i - 1] + dp[i - 1][j - items[i - 1]]) > dp[i - 1][j]
                               ? (warehouses[i - 1] + dp[i - 1][j - items[i - 1]])
                               : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("Optimal inventory allocation: %d units\n", dp[WAREHOUSES][MAX_CAPACITY]);
}

int main() {
    int items[WAREHOUSES] = {10, 20, 30, 25, 15, 35, 40, 50, 30, 20};  
    int warehouses[WAREHOUSES] = {50, 60, 70, 40, 30, 80, 90, 100, 75, 65};  

    optimizeInventory(items, warehouses, WAREHOUSES);

    return 0;
}
/*Inventory Optimization:
Write a C program to optimize the inventory management in Amazon's platform. Assume that the
platform has 10 warehouses and each warehouse has a limited capacity. Write a program to find the
optimal inventory allocation using a dynamic programming algorithm. */
