#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 500000

int main() {
    unsigned int current_users = 0;
    char choice;

    while (1) {
        printf("Current Users: %u\n", current_users);
        printf("Do you want to add more users? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            unsigned int new_users;
            printf("Enter number of users to add: ");
            scanf("%u", &new_users);
            
            if (current_users + new_users > MAX_USERS) {
                printf("Platform Crash! Maximum concurrent users exceeded.\n");
                exit(1);
            } else {
                current_users += new_users;
                printf("Users successfully added.\n");
            }
        } else if (choice == 'n' || choice == 'N') {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
    
    return 0;
}



/*Scalability Issue
Write a C program to simulate a scalability issue in Amazon's platform. Assume that the platform can
handle a maximum of 500,000 concurrent users. If the number of users exceeds 500,000, the
platform crashes. Write a program to simulate this scenario and display the result.*/
