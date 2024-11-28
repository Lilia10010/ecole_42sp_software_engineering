<div align="center" style="padding-bottom: 10px;">
<img align="center" src="../assets/badges/get_next_linee.png" alt="Born2beRoot" style="width: 100px; vertical-align: middle;padding-bottom: 8px;" />
<h1 align="center" style="border: none;">
  Get Next Line
</h1>

</div>

> &nbsp; &nbsp; &nbsp;
>
> -   **Objetivo**: O objetivo desse projeto é criar uma função que leia uma linha de um arquivo ou de um fluxo de entrada (stdin) sem carregar o arquivo inteiro na memória. A função deve ser capaz de lidar com múltiplas chamadas e ler até o final do arquivo ou até encontrar uma linha completa.
> -   **Habilidades**: `Manipulação de arquivo` `buffers e leitura eficiente de dados`
>
> &nbsp; &nbsp; &nbsp;

## Funções Utilizadas

A tabela a seguir descreve as funções utilizadas pela `get_next_line`:

| Função          | Descrição                                                     |
| --------------- | ------------------------------------------------------------- |
| `get_next_line` | Lê uma linha de um arquivo ou fluxo de entrada.               |
| `ft_strjoin`    | Concatena duas strings.                                       |
| `ft_strlen`     | Calcula o comprimento de uma string.                          |
| `ft_strdup`     | Duplica uma string.                                           |
| `ft_substr`     | Extrai uma substring de uma string.                           |
| `ft_strchr`     | Localiza a primeira ocorrência de um caractere em uma string. |

## &nbsp;

&nbsp;

### Testando a Função `get_next_line`

**Compilar o Arquivo main.c**

```sh
cc main.c get_next_line.c get_next_line_utils.c -o test
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
