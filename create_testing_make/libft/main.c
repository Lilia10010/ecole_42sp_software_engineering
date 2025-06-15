#include <stdio.h>
#include "libft.h"

int main(void)
{
    const char *test_str = "Hello, 42!";
    size_t length;

    length = ft_strlen(test_str);
    printf("The length of the string \"%s\" is: %zu\n", test_str, length);

    return 0;
}