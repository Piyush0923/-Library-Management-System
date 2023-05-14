#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int id;
    int is_borrowed;
};

struct Book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Error: Library inventory is full.\n");
        return;
    }

    struct Book book;
    printf("Enter book title: ");
    scanf(" %[^\n]s", book.title);
    printf("Enter author name: ");
    scanf(" %[^\n]s", book.author);
    printf("Enter book ID: ");
    scanf("%d", &book.id);
    book.is_borrowed = 0;

    books[num_books++] = book;
    printf("Book added successfully.\n");
}

void display_books() {
    printf("\nLibrary Inventory\n");
    printf("-----------------\n");
    printf("Title\t\tAuthor\t\tID\tStatus\n");

    for (int i = 0; i < num_books; i++) {
        printf("%-16s %-16s %-8d", books[i].title, books[i].author, books[i].id);
        if (books[i].is_borrowed) {
            printf("Borrowed\n");
        } else {
            printf("Available\n");
        }
    }
}

void borrow_book() {
    int book_id;
    printf("Enter book ID: ");
    scanf("%d", &book_id);

    for (int i = 0; i < num_books; i++) {
        if (books[i].id == book_id) {
            if (books[i].is_borrowed) {
                printf("Error: Book is already borrowed.\n");
            } else {
                books[i].is_borrowed = 1;
                printf("Book borrowed successfully.\n");
            }
            return;
        }
    }

    printf("Error: Book not found.\n");
}

void return_book() {
    int book_id;
    printf("Enter book ID: ");
    scanf("%d", &book_id);

    for (int i = 0; i < num_books; i++) {
        if (books[i].id == book_id) {
            if (!books[i].is_borrowed) {
                printf("Error: Book is not borrowed.\n");
            } else {
                books[i].is_borrowed = 0;
                printf("Book returned successfully.\n");
            }
            return;
        }
    }

    printf("Error: Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Borrow book\n");
        printf("4. Return book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                borrow_book();
                break;
            case 4:
                return_book();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
