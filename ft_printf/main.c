
#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *msg = NULL;
    char c = 'A';
    char *str = "Hello, world!";
    void *ptr = &str;
    int num = -12345;
    unsigned int u_num = 4294967295U;
    int hex_num = 305441741;
    int ret;


    printf("\n------------------ \n");
    ret = printf("Caractere: %c\n", c);
    printf("Retorno de printf para %%c: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Caractere: %c\n", c);
    ft_printf("Retorno de printf para %%c: %d\n", ret);
    

    printf("\n------------------ \n");
    ret = printf("String: %s\n", str);
    printf("Retorno de printf para %%s: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    printf("a baixo minha funczinha \n");
    ret = ft_printf("String: %s\n", str);
    ft_printf("Retorno de printf para %%s: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("String: %s\n", msg);
    printf("Retorno de printf para %%s: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    printf("a baixo minha funczinha \n");
    ret = ft_printf("String: %s\n", msg);
    ft_printf("Retorno de printf para %%s: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Ponteiro: %p\n", ptr);
    printf("Retorno de printf para %%p: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Ponteiro: %p\n", ptr);
    ft_printf("Retorno de printf para %%p: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Número decimal (signed): %d\n", num);
    printf("Retorno de printf para %%d: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Número decimal (signed): %d\n", num);
    ft_printf("Retorno de printf para %%d: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Inteiro (base 10): %i\n", num);
    printf("Retorno de printf para %%i: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Inteiro (base 10): %i\n", num);
    ft_printf("Retorno de printf para %%i: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Número decimal (unsigned): %u\n", u_num);
    printf("Retorno de printf para %%u: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Número decimal (unsigned): %u\n", u_num);
    ft_printf("Retorno de printf para %%u: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Hexadecimal (minúsculo): %x\n", hex_num);
    printf("Retorno de printf para %%x: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Hexadecimal (minúsculo): %x\n", hex_num);
    ft_printf("Retorno de printf para %%x: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Hexadecimal (maiúsculo): %X\n", hex_num);
    printf("Retorno de printf para %%X: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Hexadecimal (maiúsculo): %X\n", hex_num);
    ft_printf("Retorno de printf para %%X: %d\n", ret);

    printf("\n------------------ \n");
    ret = printf("Porcentagem: %%\n");
    printf("Retorno de printf para %%%%: %d\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Porcentagem: %%\n");
    ft_printf("Retorno de printf para %%%%: %d\n", ret);


     // Teste pata test para matar a curiosidade testingling
   /*  printf("\n------------------ \n");
    ret = printf("Porcentagem: %a\n");
    printf("Retorno de printf para %a\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Porcentagem: %a\n");
    ft_printf("Retorno de printf para %a", ret);
     printf("\n------------------ \n");

    ret = printf("Porcentagem: %e\n");
    printf("Retorno de printf para %e\n", ret);
    printf("----------a baixo minha funczinha-------- \n");
    ret = ft_printf("Porcentagem: %e\n");
    ft_printf("Retorno de printf para %e", ret); */

    return 0;
}
