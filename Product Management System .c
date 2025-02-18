#include <stdio.h> 
#include <string.h> 
#define MAX_PRODUCTS 100  
typedef struct { 
int id; 
char name[50]; 
char description[100]; 
float price; 
int quantity; 
} Product; 
Product products[MAX_PRODUCTS]; 
int productCount = 0; 
void addProduct() { 
if (productCount >= MAX_PRODUCTS) { 
        printf("Error: Product list is full!\n"); 
        return; 
    } 
 
    printf("\nEnter Product ID: "); 
    scanf("%d", &products[productCount].id); 
    getchar();  
 
    printf("Enter Product Name: "); 
    fgets(products[productCount].name, 
sizeof(products[productCount].name), stdin); 
    strtok(products[productCount].name, "\n");  
 
    printf("Enter Product Description: "); 
    fgets(products[productCount].description, 
sizeof(products[productCount].description), stdin); 
    strtok(products[productCount].description, "\n"); 
 
    printf("Enter Product Price: "); 
    scanf("%f", &products[productCount].price); 
 
    printf("Enter Product Quantity: "); 
    scanf("%d", &products[productCount].quantity); 
 
    productCount++; 
    printf("Product added successfully!\n"); 
} 
 
void displayProducts() { 
    if (productCount == 0) { 
        printf("\nNo products available.\n"); 
        return; 
    } 
 
    printf("\nProduct List:\n"); 
    printf("------------------------------------------------------------\n"); 
    printf("ID\tName\t\tPrice\tQuantity\tDescription\n"); 
    printf("------------------------------------------------------------\n"); 
 
    for (int i = 0; i < productCount; i++) { 
        printf("%d\t%-10s\t%.2f\t%d\t\t%s\n",  
               products[i].id, products[i].name, products[i].price,  
               products[i].quantity, products[i].description); 
    } 
} 
 
 
void searchProduct() { 
    int choice, id; 
    char name[50]; 
    printf("\nSearch Product By:\n1. ID\n2. Name\nEnter choice: "); 
    scanf("%d", &choice); 
    getchar();  
 
    if (choice == 1) { 
        printf("Enter Product ID: "); 
        scanf("%d", &id); 
        for (int i = 0; i < productCount; i++) { 
            if (products[i].id == id) { 
                printf("\nProduct Found: %s - Price: %.2f - Quantity: %d\n",  
                       products[i].name, products[i].price, products[i].quantity); 
                return; 
            } 
        } 
    } else if (choice == 2) { 
        printf("Enter Product Name: "); 
        fgets(name, sizeof(name), stdin); 
        strtok(name, "\n");  
        for (int i = 0; i < productCount; i++) { 
            if (strcmp(products[i].name, name) == 0) { 
                printf("\nProduct Found: ID: %d - Price: %.2f - Quantity: 
%d\n",  
                       products[i].id, products[i].price, products[i].quantity); 
                return; 
            } 
        } 
    } 
    printf("Product not found.\n"); 
} 
 
 
void updateProduct() { 
    int id, choice; 
    printf("\nEnter Product ID to Update: "); 
    scanf("%d", &id); 
    getchar();  
 
    for (int i = 0; i < productCount; i++) { 
        if (products[i].id == id) { 
            printf("\nUpdating Product: %s\n", products[i].name); 
            printf("1. Update Price\n2. Update Quantity\n3. Update 
Description\nEnter choice: "); 
            scanf("%d", &choice); 
            getchar();  
 
            if (choice == 1) { 
                printf("Enter New Price: "); 
                scanf("%f", &products[i].price); 
            } else if (choice == 2) { 
                printf("Enter New Quantity: "); 
                scanf("%d", &products[i].quantity); 
            } else if (choice == 3) { 
                printf("Enter New Description: "); 
                fgets(products[i].description, sizeof(products[i].description), 
stdin); 
                strtok(products[i].description, "\n"); 
            } else { 
                printf("Invalid choice!\n"); 
                return; 
            } 
 
            printf("Product updated successfully!\n"); 
            return; 
        } 
    } 
    printf("Product not found.\n"); 
} 
 
 
void deleteProduct() { 
    int id, index = -1; 
    printf("\nEnter Product ID to Delete: "); 
    scanf("%d", &id); 
 
    for (int i = 0; i < productCount; i++) { 
        if (products[i].id == id) { 
            index = i; 
            break; 
        } 
    } 
 
    if (index == -1) { 
        printf("Product not found.\n"); 
        return; 
    } 
 
    for (int i = index; i < productCount - 1; i++) { 
        products[i] = products[i + 1]; 
    } 
    productCount--; 
 
    printf("Product deleted successfully!\n"); 
} 
 
void menu() { 
    int choice; 
    while (1) { 
        printf("\n=== Product Management System ===\n"); 
        printf("1. Add Product\n2. Display Products\n3. Search Product\n4. 
Update Product\n5. Delete Product\n6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        getchar(); 
 
        switch (choice) { 
            case 1: addProduct(); break; 
            case 2: displayProducts(); break; 
            case 3: searchProduct(); break; 
            case 4: updateProduct(); break; 
            case 5: deleteProduct(); break; 
            case 6: printf("Exiting program...\n"); return; 
            default: printf("Invalid choice! Try again.\n"); 
        } 
    } 
} 
 
int main() { 
menu(); 
return 0; 
}
