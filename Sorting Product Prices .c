/*Create  Sorting Product Prices .c
1. Question: An e-commerce website needs to sort product prices in ascending order. 2. Write a function using built-in functions (sort()). 
3. Write the function without built-in functions (implement your own sorting algorithm 
like Bubble Sort).*/

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


//sorting based on price and rating
#include <stdio.h>

const char *statustrack(int status) {
    if (status == 1)
        return "Your order has been received.\n";
    if (status == 2)
        return "Your food is being prepared.\n";
    if (status == 3)
        return "Your food is out for delivery.\n";
    if (status == 4)
        return "Your order has been delivered. Enjoy your meal!\n";

     return "Invalid status. Please enter a number between 1 and 4.\n";  
}

int main() { 
    int status;
    const char *track;
    while (1) {
        printf("Enter order status (1-4) or 0 to exit: ");
        scanf("%d", &status);
        
        if (status == 0) { 
            break; 
        }
        
        track = statustrack(status);
        printf("%s", track);
    }
    return 0; 
}

