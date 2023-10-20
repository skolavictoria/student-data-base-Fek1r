#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[20];
    char surname[20];
    int age;
    int grade;
};

void inputStudent(struct Student *student) {
    printf("Enter the name of a student: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';
    printf("Enter the surname of a student: ");
    fgets(student->surname, sizeof(student->surname), stdin);
    student->surname[strcspn(student->surname, "\n")] = '\0';
    printf("Enter the age of a student: ");
    scanf("%d", &student->age);
    printf("Enter the grade of a student: ");
    scanf("%d", &student->grade);
    getchar(); 
}

void printStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Surname: %s\n", student->surname);
    printf("Age: %d\n", student->age);
    printf("Grade: %d\n", student->grade);
}

int main() {
    struct Student students[30] = {};
    int count = 0;
    char answer1;

    do {
        inputStudent(&students[count]);
        count++;

        printf("Do you want to add a student to the database? [Y/N]: ");
        scanf(" %c", &answer1);
        getchar();
    } while (answer1 != 'N' && answer1 != 'n');

    FILE *fp;
    fp = fopen("students.txt", "w");

    if (fp != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(fp, "Student %d:\n", i + 1);
            fprintf(fp, "------------------\n");
            fprintf(fp, "Name: %s\n", students[i].name);
            fprintf(fp, "Surname: %s\n", students[i].surname);
            fprintf(fp, "Age: %d\n", students[i].age);
            fprintf(fp, "Grade: %d\n", students[i].grade);
        }

        fclose(fp);
    } else {
        printf("Failed to open the file for writing.\n");
    }
    return 0;
}