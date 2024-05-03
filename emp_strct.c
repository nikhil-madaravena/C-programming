#include <stdio.h>
#include <string.h>

struct Employee {
    char name[1000];
    int empNumber;
    int deptNumber;
    char dateOfJoining[100];
    float salary;
};

int main() {
    int N,k;
    printf("Enter the number of employees: ");
    scanf("%d", &N);

    struct Employee emp[1000];

    printf("Enter details for %d employees:\n", N);
    for (int i = 0; i < N; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Employee Number: ");
        scanf("%d", &emp[i].empNumber);
        printf("Department Number: ");
        scanf("%d", &emp[i].deptNumber);
        printf("Date of Joining: ");
        scanf("%s", emp[i].dateOfJoining);
        printf("Monthly Salary: ");
        scanf("%f", &emp[i].salary);
    }

        float maxSalary = emp[0].salary;
    for (int i = 0; i < N; i++) {
        if (emp[i].salary > maxSalary) {
            maxSalary = emp[i].salary;
        }
    }
    printf("\n--------------------------------------\n");

    printf("\nEmployee with salary higher than all others:\n");
    for(int i=0 ; i<N ; i++){
        if(emp[i].salary==maxSalary){
    printf("Name: %s\n", emp[i].name);
    printf("Employee Number: %d\n", emp[i].empNumber);
    printf("Department Number: %d\n", emp[i].deptNumber);
    printf("Date of Joining: %s\n", emp[i].dateOfJoining);
    printf("Monthly Salary: %.2f\n\n", emp[i].salary);
        }
    }
}
