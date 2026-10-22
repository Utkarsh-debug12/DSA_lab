#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};void insertAfterPosition(struct Node* head, int position, int newData) {
    if (head == NULL) {
        printf("The list is empty. Cannot insert after position %d.\n", position);
        return;
    }
    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = newData;
    newNode->next = current->next; 
    current->next = newNode;      
}
void append(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    int n;
    printf("Enter the no. of element in list: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        append(&head,num);
    }
    printf("Original List:\n");
    printList(head);
    int pos,value;
    printf("Enter the position and value to insert: ");
    scanf("%d %d",&pos,&value);
    insertAfterPosition(head, pos, value);
    printf("Updated List:\n");
    printList(head);
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}