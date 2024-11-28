<div align="center" style="padding-bottom: 10px;">
<img align="center" src="../assets/badges/ft_printfe.png" alt="Born2beRoot" style="width: 100px; vertical-align: middle;padding-bottom: 8px;" />
<h1 align="center" style="border: none;">
  Ft Printf
</h1>

</div>

> &nbsp; &nbsp; &nbsp;
>
> -   **Objetivo**: O projeto Libft consiste em criar uma biblioteca de funções essenciais em C, que inclui funções de manipulação de strings, memória, listas encadeadas, e outros utilitários que são comumente usados em projetos subsequentes na 42.
> -   **Habilidades**: `Programação em C` `manipulação de memória` `listas e estruturas de dados básicas`
>
> &nbsp; &nbsp; &nbsp;

## Especificadores de Formato

A tabela a seguir descreve os especificadores de formato suportados pela função `ft_printf`:

| Especificador | Descrição                                                                 |
| ------------- | ------------------------------------------------------------------------- |
| `%c`          | Imprime um único caractere.                                               |
| `%s`          | Imprime uma string (conforme definido pela convenção comum do C).         |
| `%p`          | O endereço do ponteiro `void *` deve ser impresso em formato hexadecimal. |
| `%d`          | Imprime um número decimal (base 10).                                      |
| `%i`          | Imprime um inteiro em base 10.                                            |
| `%u`          | Imprime um número decimal (base 10) sem sinal.                            |
| `%x`          | Imprime um número em formato hexadecimal (base 16) em minúsculas.         |
| `%X`          | Imprime um número em formato hexadecimal (base 16) em maiúsculas.         |
| `%%`          | Imprime um sinal de porcentagem.                                          |

## &nbsp;

&nbsp;

### Testando a Função `ft_printf` e comparando com a `printf` original

**Compilar a Biblioteca `libftprintf.a`**

```sh
make
```

&nbsp;

**Compilar o Arquivo main.c**

```sh
cc main.c -o test libftprintf.a
```

&nbsp;

**Executar os Testes**

```
./test
```

&nbsp;

**Verificar Possíveis Erros com Valgrind**

(verificar possíveis erros de memória, como vazamentos)

```
valgrind --leak-check=full ./test
```
