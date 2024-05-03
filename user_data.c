#include <stdio.h>
#include <string.h>

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

int main() {
    struct User users[MAX_USERS];
    int numUsers;

    // Input number of users
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    // Input user information
    for (int i = 0; i < numUsers; i++) {
        printf("\nEnter details for User %d:\n", i + 1);
        printf("Username: ");
        scanf("%s", users[i].username);
        printf("Password: ");
        scanf("%s", users[i].password);
        printf("Name: ");
        scanf("%s", users[i].name);
        printf("Enter Age : ");
        scanf("%d", &users[i].age);
        printf("Enter email : ");
        scanf("%s", &users[i].email);
        printf("Designation: ");
        scanf("%s", users[i].designation);
        printf("Employee id: ");
        scanf("%d", &users[i].id);
        printf("Enter the No. of Working days : ");
        scanf("%d", &users[i].workingDays);
        printf("Enter the No. of leaves : ");
        scanf("%d",&users[i].leaveCount);
        printf("Enter base salary : ");
        scanf("%f",&users[i].salary);

        printf("Enter projects (up to %d, type 'end' to stop):\n", MAX_PROJECTS);
        int projCount = 0;
        while (projCount < MAX_PROJECTS) {
            printf("Project %d: ", projCount + 1);
            scanf("%s", users[i].projects[projCount]);
            if (strcmp(users[i].projects[projCount], "end") == 0) {
                break;
            }
            projCount++;
        }
    }

    // Save user information to a file
    FILE *fp = fopen(DATA_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    fprintf(fp, "%d\n", numUsers);
    for (int i = 0; i < numUsers; i++) {
        fprintf(fp, "%s %s %s %d %s %s %d %d %d %f", users[i].username, users[i].password, users[i].name, users[i].age, users[i].email, users[i].designation, users[i].id, users[i].workingDays, users[i].leaveCount, users[i].salary);
        int j = 0;
        while (strcmp(users[i].projects[j], "end") != 0) {
            fprintf(fp, "%s ", users[i].projects[j]);
            j++;
        }
        fprintf(fp, "end\n");
    }


    fclose(fp);
    printf("\nUser information stored successfully in '%s' file!\n", DATA_FILE);

    return 0;
}
