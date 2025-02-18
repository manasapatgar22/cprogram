//With built in function: 
 
#include <stdio.h> 
#include <stdlib.h> 
 
int compare(const void *a, const void *b) { 
    return (*(int *)a - *(int *)b); 
} 
 
void sort_prices_builtin(int prices[], int size) { 
    qsort(prices, size, sizeof(int), compare); 
} 
 
int main() { 
    int n; 
 
    printf("Enter number of products: "); 
    scanf("%d", &n); 
 
    int prices[n]; 
    printf("Enter product prices: "); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &prices[i]); 
    } 
 
    sort_prices_builtin(prices, n); 
 
    printf("Sorted Prices (Built-in sort): "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", prices[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 
 
//Without built in function: 
#include <stdio.h> 
 
void sort_prices_bubble(int prices[], int size) { 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - i - 1; j++) { 
            if (prices[j] > prices[j + 1]) { 
                int temp = prices[j]; 
                prices[j] = prices[j + 1]; 
                prices[j + 1] = temp; 
            } 
        } 
    } 
} 
 
int main() { 
    int n; 
    printf("Enter number of products: "); 
    scanf("%d", &n); 
    int prices[n]; 
    printf("Enter product prices: "); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &prices[i]); 
    } 
 
    sort_prices_bubble(prices, n); 
 
    printf("Sorted Prices (Bubble Sort): "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", prices[i]); 
    } 
    printf("\n"); 
 
    return 0; 
}
