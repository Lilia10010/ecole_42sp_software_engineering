#include "push_swap.h"

// Merge duas partes já ordenadas em a e b
void merge(t_stack **a, t_stack **b, int len_a, int len_b) {
    int i = 0, j = 0;

    while (i < len_a && j < len_b) {
        if ((*a)->data <= (*b)->data) {
            ra(a);       // Mantém o elemento em a e rotaciona
            i++;
        } else {
            pa(a, b);    // Move o menor elemento de b para a
            ra(a);       // Rotaciona para "fixar" o elemento em a
            j++;
        }
    }

    // Adiciona elementos restantes de a
    while (i++ < len_a)
        ra(a);

    // Adiciona elementos restantes de b
    while (j++ < len_b) {
        pa(a, b);
        ra(a);
    }
}

// Ordena recursivamente usando Merge Sort adaptado
void merge_sort(t_stack **a, t_stack **b, int size) {
    if (size <= 1)
        return;

    int half = size / 2;

    // Divide a lista em duas partes
    for (int i = 0; i < half; i++)
        pb(a, b);

    // Ordena recursivamente as duas metades
    merge_sort(a, b, half);
    merge_sort(b, a, size - half);  // Inverte os papéis de a e b

    // Mescla as duas partes ordenadas
    merge(a, b, half, size - half);
}