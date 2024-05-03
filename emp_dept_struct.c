#include <stdio.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    int empNumber;
    int deptNumber;
    char dateOfJoining[20];
    float monthlySalary;
};

int main() {
    int N;

    printf("Enter the number of employees: ");
    scanf("%d", &N);

    struct Employee employees[MAX_EMPLOYEES];

    printf("Enter details for %d employees:\n", N);
    for (int i = 0; i < N; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Employee Number: ");
        scanf("%d", &employees[i].empNumber);
        printf("Department Number: ");
        scanf("%d", &employees[i].deptNumber);
        printf("Date of Joining (YYYY-MM-DD): ");
        scanf("%s", employees[i].dateOfJoining);
        printf("Monthly Salary: ");
        scanf("%f", &employees[i].monthlySalary);
    }

    // Calculating average salary for each department
    float totalSalary[100] = {0};
    int count[100] = {0};

    for (int i = 0; i < N; i++) {
        totalSalary[employees[i].deptNumber] += employees[i].monthlySalary;
        count[employees[i].deptNumber]++;
    }
    printf("\n--------------------------------------------\n");

    printf("\nDepartment Numbers and their Average Salaries:\n\n");
    for (int i = 1; i <= 99; i++) {
        if (count[i] > 0) {
            float averageSalary = totalSalary[i] / count[i];
            printf("Department Number: %d,\tAverage Salary: %.2f\n", i, averageSalary);
        }
    }

    return 0;
}
