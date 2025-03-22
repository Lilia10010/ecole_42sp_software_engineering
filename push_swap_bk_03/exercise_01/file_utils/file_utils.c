#include "file_utils.h"

int count_words_in_file(const char* filename)
{
    int word_count = 0;
    char ch;

    FILE* file = fopen(filename,  "r");
    if(file == NULL)
    {
        perror("Erro ao abrir arquivo");
        return (-1);
    }
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == ' ' || ch == '\n' || ch == '\t')
            ++word_count;
    }
    fclose(file);
    return (word_count + 1);
}