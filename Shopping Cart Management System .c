#include <stdio.h> 
#include <string.h> 
#define MAX_CART_ITEMS 50 
typedef struct { 
int productId; 
char productName[50]; 
float price; 
int quantity; 
} CartItem; 
CartItem cart[MAX_CART_ITEMS]; 
int cartCount = 0; 
 
void addProduct() { 
    if (cartCount >= MAX_CART_ITEMS) { 
        printf("Error: Shopping cart is full!\n"); 
        return; 
    } 
 
    printf("\nEnter Product ID: "); 
    scanf("%d", &cart[cartCount].productId); 
    getchar(); 
 
    printf("Enter Product Name: "); 
    fgets(cart[cartCount].productName, 
sizeof(cart[cartCount].productName), stdin); 
    strtok(cart[cartCount].productName, "\n");  
    printf("Enter Product Price: "); 
    scanf("%f", &cart[cartCount].price); 
 
    printf("Enter Quantity: "); 
    scanf("%d", &cart[cartCount].quantity); 
 
    cartCount++; 
    printf("Product added to cart successfully!\n"); 
} 
 
void displayCart() { 
    if (cartCount == 0) { 
        printf("\nShopping cart is empty.\n"); 
        return; 
    } 
 
    printf("\nShopping Cart:\n"); 
    printf("------------------------------------------------------\n"); 
    printf("ID\tName\t\tPrice\tQuantity\tTotal\n"); 
    printf("------------------------------------------------------\n"); 
 
    float totalCost = 0; 
    for (int i = 0; i < cartCount; i++) { 
        float total = cart[i].price * cart[i].quantity; 
        totalCost += total; 
        printf("%d\t%-10s\t%.2f\t%d\t\t%.2f\n",  
               cart[i].productId, cart[i].productName, cart[i].price, 
cart[i].quantity, total); 
    } 
 
    printf("------------------------------------------------------\n"); 
    printf("Total Cart Value: %.2f\n", totalCost); 
} 
 
void updateQuantity() { 
    int id, newQuantity; 
    printf("\nEnter Product ID to update quantity: "); 
    scanf("%d", &id); 
 
    for (int i = 0; i < cartCount; i++) { 
        if (cart[i].productId == id) { 
            printf("Enter New Quantity for %s: ", cart[i].productName); 
            scanf("%d", &newQuantity); 
            cart[i].quantity = newQuantity; 
            printf("Product quantity updated successfully!\n"); 
            return; 
        } 
    } 
 
    printf("Product not found in the cart.\n"); 
} 
 
void removeProduct() { 
    int id, index = -1; 
    printf("\nEnter Product ID to remove: "); 
    scanf("%d", &id); 
 
    for (int i = 0; i < cartCount; i++) { 
        if (cart[i].productId == id) { 
            index = i; 
            break; 
        } 
    } 
 
    if (index == -1) { 
        printf("Product not found in the cart.\n"); 
        return; 
    } 
 
    for (int i = index; i < cartCount - 1; i++) { 
        cart[i] = cart[i + 1]; 
    } 
    cartCount--; 
 
    printf("Product removed from the cart successfully!\n"); 
} 
 
 
void applyDiscount() { 
    float totalCost = 0, discount = 0; 
 
    for (int i = 0; i < cartCount; i++) { 
        totalCost += cart[i].price * cart[i].quantity; 
    } 
 
    printf("\nTotal Cart Value: %.2f\n", totalCost); 
 
    if (totalCost >= 500) { 
        discount = totalCost * 0.10;  
    } else if (totalCost >= 200) { 
        discount = totalCost * 0.05;  
    } 
 
    if (discount > 0) { 
        printf("Discount Applied: %.2f\n", discount); 
        totalCost -= discount; 
    } else { 
        printf("No discount available.\n"); 
    } 
 
    printf("Final Price after discount: %.2f\n", totalCost); 
} 
 
 
void menu() { 
    int choice; 
    while (1) { 
        printf("\n=== Shopping Cart Management ===\n"); 
        printf("1. Add Product to Cart\n"); 
        printf("2. Display Cart\n"); 
        printf("3. Update Product Quantity\n"); 
        printf("4. Remove Product from Cart\n"); 
        printf("5. Apply Discount\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        getchar(); 
 
        switch (choice) { 
            case 1: addProduct(); break; 
            case 2: displayCart(); break; 
            case 3: updateQuantity(); break; 
            case 4: removeProduct(); break; 
            case 5: applyDiscount(); break; 
            case 6: printf("Exiting program...\n"); return; 
            default: printf("Invalid choice! Try again.\n"); 
        } 
    } 
} 
int main() { 
menu(); 
return 0;
}
