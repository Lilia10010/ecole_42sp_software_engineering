#include "linked_list.h"
void push(Node** head, int data)
{
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

Node* reverse_list(Node* head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return(prev);
}

void print_list(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf(" NULL\n");
}

void free_list(Node* head)
{
    Node* tmp;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

