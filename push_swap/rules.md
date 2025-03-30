# Ordenando uma Pilha com Operações Restritas

## Descrição do Problema

Você tem 2 pilhas nomeadas `a` e `b`.

### Estado Inicial:

- A pilha `a` contém uma quantidade aleatória de números negativos e/ou positivos que **não podem ser duplicados**.
- A pilha `b` está vazia.

### Objetivo:

Ordenar os números na pilha `a` em **ordem crescente** usando um conjunto limitado de operações.

## Operações Disponíveis

### Trocas

- `sa` (swap a): Troca os dois primeiros elementos no topo da pilha `a`. **Não faz nada** se houver apenas um ou nenhum elemento.
- `sb` (swap b): Troca os dois primeiros elementos no topo da pilha `b`. **Não faz nada** se houver apenas um ou nenhum elemento.
- `ss`: Executa `sa` e `sb` ao mesmo tempo.

### Push (Mover Elementos entre Pilhas)

- `pa` (push a): Move o primeiro elemento do topo da pilha `b` para o topo da pilha `a`. **Não faz nada** se `b` estiver vazia.
- `pb` (push b): Move o primeiro elemento do topo da pilha `a` para o topo da pilha `b`. **Não faz nada** se `a` estiver vazia.

### Rotacionar (Mover Elementos para Cima)

- `ra` (rotate a): Move todos os elementos da pilha `a` uma posição para cima. O primeiro elemento se torna o último.
- `rb` (rotate b): Move todos os elementos da pilha `b` uma posição para cima. O primeiro elemento se torna o último.
- `rr`: Executa `ra` e `rb` ao mesmo tempo.

### Rotacionar Reverso (Mover Elementos para Baixo)

- `rra` (reverse rotate a): Move todos os elementos da pilha `a` uma posição para baixo. O último elemento se torna o primeiro.
- `rrb` (reverse rotate b): Move todos os elementos da pilha `b` uma posição para baixo. O último elemento se torna o primeiro.
- `rrr`: Executa `rra` e `rrb` ao mesmo tempo.

## Desafio

Utilizando apenas essas operações, desenvolva uma estratégia para ordenar a pilha `a` de forma eficiente.
