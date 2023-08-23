#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    double rate;
    int quantity;
    double price;
};

void print(struct Item items[100], int noOfItems){
    for (int i = 0; i < noOfItems; i++) {
        printf("%s\t\t%.2lf\t%d\t\t%.2lf\n", items[i].name, items[i].rate, items[i].quantity, items[i].price);
    }
}

int main() {
    struct Item items[100];
    int noOfItems = 0;
    char name[50];
    printf("\n\nWelcome to the Grocery Billing System \n");
    printf("\nEnter customer name: ");
    scanf("%s", name);
    printf("\nType 'checkout' for name to stop.\n");
    while (noOfItems < 100) {
        char nameOfItem[50];
        double pricePerItem;
        int itemQuantity;
        printf("\nEnter item name (or 'checkout' to finish): ");
        scanf("%s", nameOfItem);
        if (strcmp(nameOfItem, "checkout") == 0) {
            break;
        }
        printf("Enter item rate: ");
        scanf("%lf", &pricePerItem);
        printf("Enter item quantity: ");
        scanf("%d", &itemQuantity);
        strcpy(items[noOfItems].name, nameOfItem);
        items[noOfItems].rate = pricePerItem;
        items[noOfItems].quantity = itemQuantity;
        items[noOfItems].price = pricePerItem * itemQuantity;
        noOfItems++;
    }
    printf("\n");
    printf("Customer: %s\n", name);
    printf("------------------------------------------------------\n");
    printf("Item Name\tRate\tQuantity\tPrice\n");
    printf("------------------------------------------------------\n");
    print(items, noOfItems);
    double amount = 0;
    for (int i = 0; i < noOfItems; i++) {
        amount += items[i].price;
    }
    printf("------------------------------------------------------\n");
    printf("Total Amount:\t\t\t\t%.2lf\n", amount);
    printf("------------------------------------------------------\n");
    return 0;
}

