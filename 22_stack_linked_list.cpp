#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* top = NULL;
void push(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = val;      
    newNode->next = top;     
    top = newNode;          
    printf("Pushed %d onto the stack.\n", val);
}
int pop() {
    if (top == NULL) {
        printf("Error: Stack Underflow! The stack is empty.\n");
        return -9999; 
    }
    Node* temp = top;       
    int poppedValue = temp->data; 
    top = top->next;         
    free(temp);            
    return poppedValue;
}
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack (top to bottom): ");
    Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    printf("--- Linked List Stack Operations ---\n");
    push(10);
    push(20);
    push(30);
    display();
    printf("\nPopped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    display();
    return 0;
}