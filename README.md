
Projeto ft_printf em C 

Este projeto consiste na implementação de uma versão simplificada da função printf, denominada ft_printf, desenvolvida em linguagem C. A proposta segue a estrutura modular e estática comum nos repositórios da 42, com organização clara por responsabilidades (um ficheiro por função) e um Makefile que automatiza a compilação.

A função ft_printf implementa os especificadores mais utilizados: %c, %s, %d/%i, %u, %x, %X, %p e %%. Cada função auxiliar retorna a quantidade de bytes escritos com write ou -1 em caso de erro, permitindo que ft_printf acumule esse total e o retorne ao final da execução.

Decisões de Projeto

A estrutura original foi mantida, respeitando o uso de funções static, alocação dinâmica com malloc na conversão hexadecimal (ft_put_hex), e nomenclatura em snake_case.

Números assinados são convertidos para tipos sem sinal quando necessário (ex.: long → unsigned long) para correta exibição em hexadecimal.

Todos os auxiliares realizam checagem do retorno de write; em caso de erro, propagam o -1.

O uso de memória dinâmica está corretamente balanceado com chamadas a free, garantindo ausência de vazamentos.

Estrutura de Arquivos:

-ft_printf.c:	Função principal ft_printf: percorre a string de formato, utiliza va_list, despacha para chr_check e acumula bytes escritos.
-chr_check.c:	Analisa o caractere após % e direciona para o handler correspondente.
-digits.c:	Função auxiliar que calcula o número de dígitos (usada para base 16 em ft_put_hex).
-ft_putchar.c:	Escreve um único caractere via write; retorna 1 ou -1.
-ft_putstr.c:	Escreve uma string; trata valores NULL imprimindo (null); retorna bytes escritos ou -1.
-ft_putnbr.c:	Imprime inteiros com sinal (int); retorna bytes escritos ou -1.
-ft_put_unsigned_nbr.c:	Imprime inteiros sem sinal (unsigned int); retorna bytes escritos ou -1.
-ft_put_hex.c:	Converte valores unsigned int para hexadecimal e imprime; utiliza malloc e libera corretamente.
-ft_put_void_pointer.c:	Imprime ponteiros no formato 0x...; trata ponteiros nulos como (nil) se desejado (unsigned int -> unsigned long).
-lower_or_upper.c:	Verifica se o especificador é minúsculo ('x') ou maiúsculo ('X'); retorna 1, 2 ou 0.
-ft_printf.h:	Arquivo de cabeçalho com protótipos e #includes.
-Makefile: Define regras de compilação com os targets padrão: all, clean, fclean, re.

Esse projeto serve tanto como exercício de domínio de funções variádicas e manipulação de strings em C, quanto como base sólida para submissões acadêmicas no currículo da 42.

English Version:

ft_printf Project in C

This project consists of implementing a simplified version of the printf function, named ft_printf, developed in the C programming language. The structure follows the modular and static organization commonly used in 42 school repositories, with clearly defined responsibilities (one file per function) and a Makefile to automate compilation.

The ft_printf function supports the most commonly used format specifiers: %c, %s, %d/%i, %u, %x, %X, %p, and %%. Each helper function returns the number of bytes written using write, or -1 in case of an error, allowing ft_printf to accumulate the total and return it upon completion.

Design Decisions

The original structure was preserved, including the use of static functions, dynamic memory allocation with malloc in the hexadecimal conversion (ft_put_hex), and naming conventions in snake_case.

Signed numbers are converted to unsigned types when necessary (e.g., long → unsigned long) to ensure correct hexadecimal output.

All helper functions check the return value of write and propagate -1 in case of error.

Dynamic memory usage is properly managed with corresponding free calls, ensuring no memory leaks.

File Structure

-ft_printf.c: Main function ft_printf: iterates through the format string, uses va_list, dispatches to chr_check, and accumulates bytes written.

-chr_check.c: Analyzes the character after % and dispatches to the appropriate handler.

-digits.c: Helper function that calculates the number of digits (used for base 16 in ft_put_hex).

-ft_putchar.c: Writes a single character using write; returns 1 or -1.

-ft_putstr.c: Writes a string; handles NULL values by printing (null); returns bytes written or -1.

-ft_putnbr.c: Prints signed integers (int); returns bytes written or -1.

-ft_put_unsigned_nbr.c: Prints unsigned integers (unsigned int); returns bytes written or -1.

-ft_put_hex.c: Converts unsigned int values to hexadecimal and prints them; uses malloc and frees memory properly.

-ft_put_void_pointer.c: Prints pointers in 0x... format; handles null pointers as (nil) if desired (unsigned int → unsigned long).

-lower_or_upper.c: Checks whether the specifier is lowercase ('x') or uppercase ('X'); returns 1, 2, or 0.

-ft_printf.h: Header file containing prototypes and #includes.

-Makefile: Defines compilation rules with standard targets: all, clean, fclean, re.

This project serves both as an exercise in mastering variadic functions and string manipulation in C, and as a solid foundation for academic submissions within the 42 school curriculum.
