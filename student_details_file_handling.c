#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    int marks[6];
};

int main() {
    FILE *file;
    int N, i, j;
    
    printf("Enter the number of students: ");
    scanf("%d", &N);

    struct Student students[N];

    for (i = 0; i < N; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks of six subjects: ");
        for (j = 0; j < 6; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }

    file = fopen("student_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        fprintf(file, "%s %d ", students[i].name, students[i].rollNumber);
        for (j = 0; j < 6; j++) {
            fprintf(file, "%d ", students[i].marks[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nStudent Details with Average Marks:\n");
    for (i = 0; i < N; i++) {
        int sum = 0;
        printf("Student Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: ");
        for (j = 0; j < 6; j++) {
            fscanf(file, "%d", &students[i].marks[j]);
            printf("%d ", students[i].marks[j]);
            sum += students[i].marks[j];
        }
        double average = (double)sum / 6.0;
        printf("\nAverage Marks: %.2f\n\n", average);
    }
    fclose(file);

    return 0;
}
