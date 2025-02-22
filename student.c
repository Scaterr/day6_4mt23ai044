#include <stdio.h>

struct Student {
    int roll_no;
    char name[50];
    int marks;
};

void sort_students(struct Student students[], int size) {
    struct Student temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[i].marks < students[j].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int binary_search(struct Student students[], int size, int roll_no) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].roll_no == roll_no) {
            return mid;
        } else if (students[mid].roll_no < roll_no) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }
    
    sort_students(students, n);
    printf("\nTop 3 Students:\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s (Roll No: %d, Marks: %d)\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    int search;
    printf("\nEnter roll number to search: ");
    scanf("%d", &search);
    int index = binary_search(students, n, search);
    if (index != -1) {
        printf("\nSearch Roll No %d: Found (%s, Marks: %d)\n", search, students[index].name, students[index].marks);
    } else {
        printf("\nSearch Roll No %d: Not Found\n", search);
    }
    return 0;
}
