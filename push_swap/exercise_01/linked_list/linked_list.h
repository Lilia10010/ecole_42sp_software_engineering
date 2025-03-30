#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void push(Node** head, int data);
Node* reverse_list(Node* head);
void print_list(Node* head);
void free_list(Node* head);

#endif