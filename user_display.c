#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_USERS 10
#define MAX_PROJECTS 5
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define DATA_FILE "user_data.txt"

// Structure to store user information
struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char projects[MAX_PROJECTS][MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
    char designation[MAX_NAME_LENGTH];
    int workingDays;
    int leaveCount;
    int id;
    float salary;
};

float calculateBonus(float totalHours, float standardHours, float hourlySalary) {
    if (totalHours > standardHours) {
        float extraHours = totalHours - standardHours;
        return extraHours * hourlySalary;
    } else {
        return 0.0; // No bonus if no extra hours worked
    }
}

void calculateSalary(int i, struct User *user) {
    float dailySalary, hourlySalary, loginTime, logoutTime;
    int workingDays, daysPresent;
    workingDays = user->workingDays;
    if (workingDays == 0) {
        printf("Error: Working days cannot be zero.\n");
        return;
    }
    daysPresent = workingDays - user->leaveCount;
    dailySalary = (user->salary) / workingDays;
    hourlySalary = dailySalary / 8.0;

    float totalBonus = 0.0, totalSalary = 0.0;
    float dayFraction;  // Fraction of a day worked

    for (int j = 0; j < daysPresent; j++) {
        printf("\nEnter login time for day %d: ", j + 1);
        scanf("%f", &loginTime);
        printf("Enter logout time for day %d: ", j + 1);
        scanf("%f", &logoutTime);

        float totalHours = abs(logoutTime - loginTime);
        printf("Total working hours for day %d: %.2f\n", j + 1, totalHours);

        float bonus = calculateBonus(totalHours, 8.0, hourlySalary);
        totalBonus += bonus;

        // Calculate dayFraction based on the actual hours worked
        dayFraction = totalHours / 8.0;

        float daySalary = dayFraction * dailySalary + bonus;  // Include bonus in day's salary
        printf("Day Salary for day %d: %.2f\n", j + 1, daySalary);

        totalSalary += daySalary;  // Accumulate day's salary to total salary
    }
    printf("Total Bonus: %.2f\nTotal Salary: %.2f\n", totalBonus, totalSalary);
}


int main() {
    struct User users[MAX_USERS];
    int numUsers;

    // Load user information from file
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    fscanf(fp, "%d", &numUsers);
    for (int i = 0; i < numUsers; i++) {
        fscanf(fp, "%s %s %s %d %s %s %d %d %d %f", users[i].username, users[i].password, users[i].name, &users[i].age,users[i].email, users[i].designation, &users[i].id, &users[i].workingDays, &users[i].leaveCount, &users[i].salary);
        int j = 0;
        while (1) {
            fscanf(fp, "%s", users[i].projects[j]);
            if (strcmp(users[i].projects[j], "end") == 0) {
                break;
            }
            j++;
        }
    }

    fclose(fp);

    // Login
    char loginUsername[MAX_NAME_LENGTH];
    char loginPassword[MAX_PASSWORD_LENGTH];
    int loggedIn = 0;
    int i;
    
    while (!loggedIn) {
        printf("\nEnter username to login (or type 'exit' to quit): ");
        scanf("%s", loginUsername);
        if (strcmp(loginUsername, "exit") == 0) {
            printf("Exiting program...\n");
            return 0;
        }
        printf("Enter password: ");
        scanf("%s", loginPassword);

        for (i = 0; i < numUsers; i++) {
            if (strcmp(loginUsername, users[i].username) == 0 && strcmp(loginPassword, users[i].password) == 0) {
                loggedIn = 1;
                printf("\nLogin successful!\n");
                printf("Welcome!!!\n");
                break;
            }
        }
        if (!loggedIn) {
            printf("\nLogin failed. Invalid username or password.\n");
        }
    }

    // main menu
    int choice, j = 0;
    while (1) {
        printf("\n1. Personal Details\n2. Calculate Salary\n3. Display Projects\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Name: %s\n", users[i].name);
                printf("Age: %d\n", users[i].age);
                printf("Email: %s\n", users[i].email);
                printf("Designation: %s\n", users[i].designation);
                printf("No of Working days: %d\n", users[i].workingDays);
                printf("No of days on leave: %d\n", users[i].leaveCount);
                break;
            case 2:
                printf("Base Salary: %.2f\n", users[i].salary);
                printf("No of Working days: %d\n", users[i].workingDays);
                printf("No of days on leave: %d\n", users[i].leaveCount);
                calculateSalary(i, &users[i]);
                break;
            case 3: 
                printf("Projects:\n");
                while (strcmp(users[i].projects[j], "end") != 0) {
                    printf("%d. %s\n", j + 1, users[i].projects[j]);
                    j++;
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
