#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    printf("Original Linked List: \n");
    printList(head);
    int n;
    printf("Enter the no. of elements to add in beginning: ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int num;
        scanf("%d",&num);
        insertAtBeginning(&head, num);
    }
    printf("Linked List after insertions at the beginning:\n");
    printList(head);
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}