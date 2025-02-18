/*Zomato provides real-time tracking of
food delivery orders. The order status changes dynamically as the delivery
progresses through different stages:
Write a C program that simulates a
Zomato order tracking system. The user should input a number (1-4)
corresponding to the order status, and the program should display the current
status message.
Enter order
status (1-4): 2
Your food is being prepared.
Enter order status (1-4):
4
Your order has been delivered. Enjoy your meal!
If the user enters an invalid number,
display an error message:
"Invalid status. Please enter a number
between 1 and 4."
*/

#include <stdio.h>
#include <string.h>

int main() {
    int paymentMethod;
    char cardNumber[17];
    char upiID[50];
    int bankChoice;

    while (1) {
        printf("\nSelect Payment Method (1-3):\n");
        printf("1. Credit/Debit Card\n");
        printf("2. UPI\n");
        printf("3. Net Banking\n");
        printf("Your choice: ");
        scanf("%d", &paymentMethod);

        switch (paymentMethod) {
            case 1: 
                printf("Enter your 16-digit card number: ");
                scanf("%16s", cardNumber); 
                if (strlen(cardNumber) == 16) {
                    printf("Payment Successful!\n");
                } else {
                    printf("Transaction Failed. Please try again.\n");
                }
                break;

            case 2:
                printf("Enter your UPI ID (e.g., user@upi): ");
                scanf("%s", upiID);
                if (strstr(upiID, "@upi") != NULL) {
                    printf("Payment Successful!\n");
                } else {
                    printf("Transaction Failed. Please try again.\n");
                }
                break;

            case 3: 
                printf("Select a bank:\n");
                printf("1. SBI\n");
                printf("2. HDFC\n");
                printf("3. ICICI\n");
                printf("Your choice: ");
                scanf("%d", &bankChoice);
                if (bankChoice >= 1 && bankChoice <= 3) {
                    printf("Payment Successful!\n");
                } else {
                    printf("Transaction Failed. Please try again.\n");
                }
                break;

            default:
                printf("Invalid payment method. Please try again.\n");
                break;
        }

        char continueInput;
        printf("Do you want to make another transaction? (y/n): ");
        scanf(" %c", &continueInput); 
        if (continueInput != 'y' && continueInput != 'Y') {
            break;
        }
    }
    return 0;
}
