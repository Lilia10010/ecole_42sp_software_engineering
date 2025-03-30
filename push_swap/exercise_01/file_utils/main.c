
#include "file_utils.h"

int main(void)
{
       //Teste: contagem de palavras em file
    const char* filename = "text.txt";
    int word_count = count_words_in_file(filename);
    if(word_count >= 0)
    {
        printf("Total de palavras: $%s: %d\n", filename, word_count);
    }
    return (0);
}