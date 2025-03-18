#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack *a = NULL;
    t_stack *b = NULL;

    // Preenche a pilha a com os argumentos
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        push(&a, num);
    }

    // Ordena usando o Merge Sort adaptado
    merge_sort(&a, &b, argc - 1);

    // Imprime a pilha ordenada
    print_stack(a, "A (ordenado)");

    // Libera a memória
    free_stack(a);
    free_stack(b);

    return 0;
}