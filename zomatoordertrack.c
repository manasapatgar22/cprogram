#include <stdio.h>

int main() {
    int status;
    
    // asking user for input of status
    printf("Enter order status (1-4): ");
    scanf("%d", &status);
    
    // using switch statement checking status
    switch (status) {
        case 1:
            printf("Your order has been received.\n");
            break;
        case 2:
            printf("Your food is being prepared.\n");
            break;
        case 3:
            printf("Your food is out for delivery.\n");
            break;
        case 4:
            printf("Your order has been delivered. Enjoy your meal!\n");
            break;
        default:
            printf("Invalid status. Please enter a number between 1 and 4.\n");
    }
    
    return 0;
}
