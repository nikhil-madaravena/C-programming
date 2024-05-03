#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PROJECTS 5
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

// Structure to store user information
struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char projects[MAX_PROJECTS][MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    int rollno;
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
        printf("Roll No: ");
        scanf("%d", &users[i].rollno);

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

    // Login check
    char loginUsername[MAX_NAME_LENGTH];
    char loginPassword[MAX_PASSWORD_LENGTH];
    printf("\nEnter username to login: ");
    scanf("%s", loginUsername);
    printf("Enter password: ");
    scanf("%s", loginPassword);

    int loggedIn = 0;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(loginUsername, users[i].username) == 0 && strcmp(loginPassword, users[i].password) == 0) {
            loggedIn = 1;
            printf("\nLogin successful!\n");
            printf("Welcome, %s!\n", users[i].name);
            // Display user information
            printf("\nUser Information:\n");
            printf("Username: %s\n", users[i].username);
            printf("Name: %s\n", users[i].name);
            printf("Roll No: %d\n", users[i].rollno);

            // Prompt to display projects
            char choice;
            printf("\nDo you want to display projects? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("Projects:\n");
                for (int j = 0; j < MAX_PROJECTS; j++) {
                    if (strcmp(users[i].projects[j], "end") == 0) {
                        break;
                    }
                    printf("- %s\n", users[i].projects[j]);
                }
            }
            break;
        }
    }

    if (!loggedIn) {
        printf("\nLogin failed. Invalid username or password.\n");
    }

    return 0;
}
