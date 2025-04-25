#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int availableCopies;
};

struct Book inventory[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter title: ");
        scanf("%s", newBook.title);
        printf("Enter author: ");
        scanf("%s", newBook.author);
        printf("Enter available copies: ");
        scanf("%d", &newBook.availableCopies);
        
        inventory[numBooks++] = newBook;
        printf("Book added successfully.\n");
    } else {
        printf("Inventory is full. Cannot add more books.\n");
    }
}

int searchBook(const char* title) {
    for (int i = 0; i < numBooks; ++i) {
        if (strcmp(inventory[i].title, title) == 0) {
            return i; // Book found, return index
        }
    }
    return -1; // Book not found
}

void displayInventory() {
    printf("Inventory:\n");
    printf("---------------------------------------------------\n");
    printf("Title\t\tAuthor\t\tAvailable Copies\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numBooks; ++i) {
        printf("%s\t\t%s\t\t%d\n", inventory[i].title, inventory[i].author, inventory[i].availableCopies);
    }
    printf("---------------------------------------------------\n");
}

void sortInventory() {
    // Bubble sort algorithm to sort the inventory by book title
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - i - 1; j++) {
            if (strcmp(inventory[j].title, inventory[j + 1].title) > 0) {
                // Swap books
                struct Book temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
}

int main() {
    int choice;
    char searchTitle[MAX_TITLE_LENGTH];

    do {
        printf("\nInventory Tracking System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display Inventory\n");
        printf("4. Sort Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                printf("Enter the title of the book to search: ");
                scanf("%s", searchTitle);
                int index = searchBook(searchTitle);
                if (index != -1) {
                    printf("Book found:\n");
                    printf("Title: %s\nAuthor: %s\nAvailable Copies: %d\n", inventory[index].title, inventory[index].author, inventory[index].availableCopies);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                sortInventory();
                printf("Inventory sorted by title.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}