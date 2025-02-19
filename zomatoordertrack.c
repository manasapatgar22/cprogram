/* Payment Gateway Simulation
Problem Statement:
A payment gateway processes online
transactions with the following steps:
1.
User
selects a payment method:
1 for
2 for
3 for
If
the user selects an invalid option, show an error message.
If a
valid method is chosen, the system asks for further details:
For ,
enter a 16-digit card number.
For , enter a
valid UPI ID (e.g., user@upi).
For ,
select a bank from predefined options (e.g., 1 for SBI, 2 for HDFC).
If
the details are correct, display "Payment
Successful!"
Otherwise,
prompt "Transaction Failed. Please
try again."
Select Payment Method
(1-3): 2
Enter your UPI ID: user@upi
Payment Successful!
Select Payment Method
(1-3): 5
Invalid payment method. Please try again.*/

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



//using function
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

