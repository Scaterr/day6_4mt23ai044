#include <stdio.h>

void sortSelection(int distances[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (distances[j] < distances[index]) {
                index = j;
            }
        }
        if (index != i) {
            int temp = distances[i];
            distances[i] = distances[index];
            distances[index] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of ambulances: ");
    scanf("%d", &n);
    
    int distances[n];
    printf("Enter the distances of ambulances (in km): \n");
    for (int i = 0; i < n; i++) {
        printf("Ambulance %d: ", i + 1);
        scanf("%d", &distances[i]);
    }

    sortSelection(distances, n);
    printf("\nSorted by Distance:\n");
    printf("Distance: ");
    for (int i = 0; i < n; i++) {
        printf("%d km ", distances[i]);
        
    }
    printf("\nNearest Ambulance Assigned: Distance %d km\n", distances[0]);
    return 0;
}
