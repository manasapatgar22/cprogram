#include <stdio.h>

#define TOTAL_LINES 1000000  
#define INITIAL_DEBT_PER_LINE 0.1  
#define REDUCTION_RATE 0.05  

int main() {
    double totalDebt = TOTAL_LINES * INITIAL_DEBT_PER_LINE;  
    int month = 0;

    printf("Month\tTotal Technical Debt\n");
    printf("----------------------------------\n");

    while (totalDebt > 0.01) {  
        printf("%d\t%.2f\n", month, totalDebt);
        totalDebt -= totalDebt * REDUCTION_RATE;  
        month++;
    }

    printf("\nTechnical debt fully reduced in %d months.\n", month);
    return 0;
}
/*Technical Debt Reduction:
Write a C program to simulate a technical debt reduction program in Amazon's platform. Assume that
the platform has 1 million lines of code and each line of code has a technical debt of 0.1 (10%). Write
a program to simulate the reduction of technical debt over time and display the result.*/
