#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void deleteElement(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp == NULL) {
        printf("List is empty. Cannot delete %d.\n", key);
        return;
    }
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Move head to the next node
        printf("Deleted %d (was at head).\n", temp->data);
        free(temp);             // Free the old head
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    printf("Deleted %d from the list.\n", temp->data);
    free(temp);
}
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n\n");
}
int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printf("Original Linked List:\n");
    printList(head);
    deleteElement(&head, 20);
    printList(head);
    deleteElement(&head, 40);
    printList(head);
    deleteElement(&head, 100);
    printList(head);
    deleteElement(&head, 10);
    printList(head);
    return 0;
}
