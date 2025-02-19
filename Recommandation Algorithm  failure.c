#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_RECOMMENDATIONS 100
#define FAILURE_PROBABILITY 0.02

int main() {
    int failed_recommendations = 0;
    srand(time(0));

    for (int i = 0; i < TOTAL_RECOMMENDATIONS; i++) {
        double rand_prob = (double)rand() / RAND_MAX;  
        if (rand_prob < FAILURE_PROBABILITY) {
            failed_recommendations++;
        }
    }

    printf("Total recommendations: %d\n", TOTAL_RECOMMENDATIONS);
    printf("Failed recommendations: %d\n", failed_recommendations);

    return 0;
}
/* Recommendation Algorithm Failure:
Write a C program to simulate a recommendation algorithm failure in Amazon's platform. Assume
that the algorithm fails with a probability of 0.02 (2%). Write a program to simulate 100 product
recommendations and display the number of failed recommendations*/
