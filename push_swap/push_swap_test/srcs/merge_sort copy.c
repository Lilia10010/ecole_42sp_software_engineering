#include "push_swap.h"

// Função para dividir a lista em duas metades
void split_list(t_stack *source, t_stack **front, t_stack **back) {
    t_stack *fast;
    t_stack *slow;
    slow = source;
    fast = source->next;

    // Avança 'fast' dois nós e 'slow' um nó
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' está antes do ponto médio da lista, então dividimos a lista em duas metades
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Função para mesclar duas listas ordenadas
t_stack *sorted_merge(t_stack *a, t_stack *b) {
    t_stack *result = NULL;

    // Caso base
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // Escolhe a menor das duas listas e recursivamente mescla o restante
    if (a->data <= b->data) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

// Função principal do Merge Sort
void merge_sort(t_stack **head_ref) {
    t_stack *head = *head_ref;
    t_stack *a;
    t_stack *b;

    // Caso base: se a lista é vazia ou tem apenas um elemento
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Divide a lista em duas metades
    split_list(head, &a, &b);

    // Ordena recursivamente as duas metades
    merge_sort(&a);
    merge_sort(&b);

    // Mescla as duas metades ordenadas
    *head_ref = sorted_merge(a, b);
}