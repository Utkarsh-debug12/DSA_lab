#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int searchSortedList(struct Node* head, int key) {
    struct Node* current = head;
    int index = 0;
    while (current != NULL && current->data <= key) {
        if (current->data == key) {
            return index; 
        }
        current = current->next;
        index++;
    }
    return -1;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(25);
    head->next->next = createNode(40);
    head->next->next->next = createNode(55);
    head->next->next->next->next = createNode(70);
    int target;
    printf("Enter the number to search: ");
    scanf("%d",&target);
    int position = searchSortedList(head, target);
    if (position != -1) {
        printf("Element %d found at index %d (position %d).\n", target, position, position + 1);
    } else {
        printf("Element %d not found in the list.\n", target);
    }
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}