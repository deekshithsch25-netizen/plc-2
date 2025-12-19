#include <stdio.h>
#include <string.h>

#define MAX 100

// Student structure
typedef struct {
    int roll;
    char fname[30];
    char lname[30];
    char course[30];
} Student;

// Global data
Student s[MAX];
int student_count = 0;

// Add Student
void addStudent() {
    if (student_count >= MAX) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s[student_count].roll);

    printf("Enter First Name: ");
    scanf("%s", s[student_count].fname);

    printf("Enter Last Name: ");
    scanf("%s", s[student_count].lname);

    printf("Enter Course: ");
    scanf("%s", s[student_count].course);

    student_count++;
    printf("Student added successfully!\n");
}

// Find by Roll
void findByRoll() {
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < student_count; i++) {
        if (s[i].roll == roll) {
            printf("Found:\n");
            printf("Roll: %d\nName: %s %s\nCourse: %s\n",
                   s[i].roll, s[i].fname, s[i].lname, s[i].course);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found!\n");
}

// Find by First Name
void findByName() {
    char name[30];
    int found = 0;

    printf("Enter First Name: ");
    scanf("%s", name);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(s[i].fname, name) == 0) {
            printf("Roll: %d | Name: %s %s | Course: %s\n",
                   s[i].roll, s[i].fname, s[i].lname, s[i].course);
            found = 1;
        }
    }

    if (!found)
        printf("No student found with this name!\n");
}

// Find by Course
void findByCourse() {
    char course[30];
    int found = 0;

    printf("Enter Course: ");
    scanf("%s", course);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(s[i].course, course) == 0) {
            printf("Roll: %d | Name: %s %s | Course: %s\n",
                   s[i].roll, s[i].fname, s[i].lname, s[i].course);
            found = 1;
        }
    }

    if (!found)
        printf("No students found in this course!\n");
}

// Update Student
void updateStudent() {
    int roll, found = 0;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < student_count; i++) {
        if (s[i].roll == roll) {
            printf("Enter New First Name: ");
            scanf("%s", s[i].fname);

            printf("Enter New Last Name: ");
            scanf("%s", s[i].lname);

            printf("Enter New Course: ");
            scanf("%s", s[i].course);

            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Delete Student
void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < student_count; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < student_count - 1; j++) {
                s[j] = s[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Count Students
void countStudents() {
    printf("Total Students: %d\n", student_count);
}

// Main Menu
int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Find by Roll Number\n");
        printf("3. Find by First Name\n");
        printf("4. Find by Course\n");
        printf("5. Update Student\n");
        printf("6. Delete Student\n");
        printf("7. Count Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: findByRoll(); break;
            case 3: findByName(); break;
            case 4: findByCourse(); break;
            case 5: updateStudent(); break;
            case 6: deleteStudent(); break;
            case 7: countStudents(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
