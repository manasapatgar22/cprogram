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
