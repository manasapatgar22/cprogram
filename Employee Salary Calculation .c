

//With built in function 
#include <stdio.h> 
#include <math.h> 
 
 
double calculateSalaryWithBuiltIns(double baseSalary, int yearsOfExperience) { 
    double bonus = fmax(0, yearsOfExperience * 1000);  
    return baseSalary + bonus; 
} 
 
int main() { 
    double baseSalary; 
    int yearsOfExperience; 
 
    printf("Enter the base salary: "); 
    scanf("%lf", &baseSalary); 
    printf("Enter years of experience: "); 
    scanf("%d", &yearsOfExperience); 
 
    double totalSalary = calculateSalaryWithBuiltIns(baseSalary, yearsOfExperience); 
 
    printf("Total Salary (with built-ins): %.2lf\n", totalSalary); 
 
    return 0; 
} 
 
 
 
 
//With out built in function: 
#include <stdio.h> 
 
int total_salary_builtin(int base_salary, int experience) { 
    int bonus = experience * 1000;  
    return base_salary + bonus; 
} 
 
int main() { 
    int base_salary, experience; 
 
    printf("Enter base salary: "); 
    scanf("%d", &base_salary); 
     
    printf("Enter years of experience: "); 
    scanf("%d", &experience); 
 
    int salary = total_salary_builtin(base_salary, experience); 
 
    printf("Total Salary using built-in functions: %d\n", salary); 
 
    return 0; 
} 
