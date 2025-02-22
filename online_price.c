#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    int price;
};

void sort_products(struct Product products[], int size) {
    struct Product temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (products[i].price > products[j].price) {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

int binary_search(struct Product products[], int size, const char* name) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(products[mid].name, name);
        if (comparison == 0) {
            return mid;
        } else if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    
    struct Product products[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for product %d\n", i + 1);
        printf("Product Name: ");
        scanf("%s", products[i].name);
        printf("Product Price: ");
        scanf("%d", &products[i].price);
    }

    sort_products(products, n);
    printf("\nSorted by Price:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", products[i].name, products[i].price);
    }

    printf("\nCheapest Product: %s (Price: %d)\n", products[0].name, products[0].price);
    printf("Most Expensive Product: %s (Price: %d)\n", products[n - 1].name, products[n - 1].price);
    
    char search_name[50];
    printf("\nEnter product name to search: ");
    scanf("%s", search_name);
    int index = binary_search(products, n, search_name);
    if (index != -1) {
        printf("\nSearch '%s': Found (Price: %d)\n", search_name, products[index].price);
    } else {
        printf("\nSearch '%s': Not Found\n", search_name);
    }
    return 0;
}
