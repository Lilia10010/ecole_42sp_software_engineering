#include "push_swap.h"

// Cria um novo nó
t_stack *create_node(int value) {
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node) return NULL;
    node->data = value;
    node->next = NULL;
    return node;
}

// Adiciona um valor no topo da pilha
void push(t_stack **stack, int value) {
    t_stack *node = create_node(value);
    if (!node) return;
    node->next = *stack;
    *stack = node;
}

// Remove e retorna o valor do topo da pilha
int pop(t_stack **stack) {
    if (!*stack) return -1; // Pilha vazia
    t_stack *temp = *stack;
    int value = temp->data;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

// Imprime a pilha
void print_stack(t_stack *stack, char *name) {
    printf("%s: ", name);
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}