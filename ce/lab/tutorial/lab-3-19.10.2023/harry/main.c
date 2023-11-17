#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char *title;
    double price;
    int pages;
    char *language;
    double weight;
    int year;
    struct Book *next;
};

struct Book *createNode(char *title, double price, int pages, char *language, double weight, int year) {
    struct Book *newNode = (struct Book *) malloc(sizeof(struct Book));
    if (newNode == NULL) {
        printf("Lmao bro, you got no memory\n");
        exit(1);
    }

    newNode->title = strdup(title);
    newNode->language = strdup(language);

    if (newNode->title == NULL || newNode->language == NULL) {
        printf("Bro, fix your ram\n");
        exit(1);
    }

    newNode->price = price;
    newNode->pages = pages;
    newNode->weight = weight;
    newNode->year = year;
    newNode->next = NULL;

    return newNode;
}

void printBooks(struct Book *head) {
    struct Book *current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Price: %.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.2f\n", current->weight);
        printf("Year: %d\n", current->year);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Book *head = NULL;

    head = createNode("Harry Potter and the Philosopher's Stone", 15.99, 336, "English", 0.85, 1997);
    head->next = createNode("Harry Potter and the Chamber of Secrets", 16.99, 360, "English", 0.88, 1998);
    head->next->next = createNode("Harry Potter and the Prisoner of Azkaban", 17.99, 448, "English", 0.92, 1999);

    printf("Information about Harry Potter books:\n");
    printBooks(head);

    struct Book *current = head;
    while (current != NULL) {
        struct Book *next = current->next;
        free(current->title);
        free(current->language);
        free(current);
        current = next;
    }

    return 0;
}
