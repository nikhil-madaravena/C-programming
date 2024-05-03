#include <stdio.h>

// Calculate bonus based on extra hours worked
float calculateBonus(float totalHours, float standardHours, float hourlyRate) {
    if (totalHours > standardHours) {
        float extraHours = totalHours - standardHours;
        return extraHours * hourlyRate;
    } else {
        return 0.0; // No bonus if no extra hours worked
    }
}

int main() {
    char ename[30], des[30];
    float monthlySalary, dailySalary, hourlySalary, loginTime, logoutTime;
    int workingDays, daysPresent;

    printf("Enter Employee Name: ");
    scanf("%s", ename);
    printf("Enter Designation: ");
    scanf("%s", des);
    printf("Enter Monthly Salary: ");
    scanf("%f", &monthlySalary);
    printf("Enter No. of working days in the month: ");
    scanf("%d", &workingDays);
    printf("No. of days present: ");
    scanf("%d", &daysPresent);

    if (workingDays == 0) {
        printf("Error: Working days cannot be zero.\n");
        return 1;
    }

    dailySalary = monthlySalary / workingDays;
    hourlySalary = dailySalary / 8.0;

    float totalBonus = 0.0, totalSalary = 0.0;

    for (int i = 0; i < daysPresent; i++) {
        printf("\nEnter login time for day %d: ", i + 1);
        scanf("%f", &loginTime);
        printf("Enter logout time for day %d: ", i + 1);
        scanf("%f", &logoutTime);

        float totalHours = logoutTime - loginTime;
        printf("Total working hours for day %d: %.2f\n", i + 1, totalHours);

        float bonus = calculateBonus(totalHours, 8.0, hourlySalary);
        totalBonus += bonus;

        float daySalary = (totalHours >= 8.0) ? dailySalary + bonus : dailySalary;
        printf("Day Salary for day %d: %.2f\n", i + 1, daySalary);

        totalSalary += daySalary;
    }

    printf("\nEmployee Name: %s\nDesignation: %s\n", ename, des);
    printf("Total Bonus: %.2f\nTotal Salary: %.2f\n", totalBonus, totalSalary);

    return 0;
}
