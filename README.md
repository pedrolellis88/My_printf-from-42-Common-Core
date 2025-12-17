*Este projeto foi criado como parte do currículo da 42 por **pdiniz-l**.*

## ft_printf

### Descrição

O projeto **ft_printf** consiste na implementação de uma versão simplificada da função padrão `printf` da linguagem C.  
O objetivo é reproduzir seu comportamento principal, respeitando as restrições, os padrões de codificação e os requisitos de baixo nível do **currículo da 42**.

Este projeto foca na compreensão de **funções variádicas**, **parsing de formato**, **formatação de inteiros e strings** e **saída utilizando a chamada de sistema `write`**, garantindo ao mesmo tempo o tratamento correto de erros e a segurança de memória.

---

### Instruções

#### Compilação

O projeto é compilado utilizando o `Makefile` fornecido.

Targets disponíveis:

```bash
make        # compila a biblioteca
make clean  # remove os arquivos objeto
make fclean # remove os arquivos objeto e a biblioteca
make re     # recompila o projeto
```
Isso irá gerar a biblioteca estática:
```bash
libftprintf.a
```
#### Uso

Em `ft_printf.c` há um comentário com um `main` pronto para testes, que pode ser compilado usando:
```bash
cc -Wall -Wextra -Werror ft_printf.c libftprintf.a
```
#### Conversões Suportadas

A função ft_printf suporta os seguintes especificadores de formato:

* `%c` — caractere

* `%s` — string

* `%d` / `%i` — inteiro decimal com sinal

* `%u` — inteiro decimal sem sinal

* `%x` — hexadecimal (minúsculo)

* `%X` — hexadecimal (maiúsculo)

* `%p` — endereço de ponteiro

* `%%` — caractere de porcentagem literal

#### Cada função auxiliar retorna:

* O número de bytes escritos em caso de sucesso

* 1 em caso de erro de escrita

A função principal ft_printf acumula esses valores e retorna o total de bytes impressos, correspondendo ao comportamento do printf padrão.

#### Escolhas de Algoritmo e Estrutura de Dados
##### Análise do Formato

A string de formato é processada caractere por caractere.

Quando um % é encontrado, o caractere seguinte é analisado para determinar a conversão apropriada.

Uma função despachadora (chr_check) direciona a execução para o handler correto com base no especificador.

##### Argumentos Variádicos

O projeto utiliza va_list, va_start, va_arg e va_end para recuperar os argumentos dinamicamente de acordo com o especificador de formato detectado.

Conversão de Inteiros e Hexadecimal

Inteiros com sinal são impressos utilizando extração de dígitos de forma recursiva ou iterativa.

Valores sem sinal são usados para `%u`, `%x`, `%X` e `%p`.

Para a saída hexadecimal, os valores são convertidos utilizando lógica de base 16.

Valores com sinal são convertidos para tipos sem sinal quando necessário (ex.: long → unsigned long) para garantir a representação correta.

##### Gerenciamento de Memória

* Alocação dinâmica de memória é usada apenas quando necessário (conversão hexadecimal).

* Cada chamada de malloc possui uma chamada correspondente de free.

* Nenhum vazamento de memória é introduzido.

##### Propagação de Erros

Cada função auxiliar verifica o valor de retorno de write.

Em caso de erro, -1 é imediatamente propagado até ft_printf.

Esse design garante correção, simplicidade e robustez, mantendo-se dentro das restrições do projeto.

##### Estrutura de Arquivos

`ft_printf.c` — Função principal que faz o parsing da string de formato, gerencia o va_list, despacha os especificadores e acumula o tamanho da saída.

`chr_check.c` — Identifica o especificador de conversão e chama o handler correspondente.

`digits.c` — Calcula o número de dígitos necessários para conversões numéricas (usado para saída hexadecimal).

`ft_putchar.c` — Escreve um único caractere usando write.

`ft_putstr.c` — Escreve uma string, tratando valores NULL imprimindo (null).

`ft_putnbr.c` — Imprime inteiros com sinal.

`ft_put_unsigned_nbr.c` — Imprime inteiros sem sinal.

`ft_put_hex.c` — Converte e imprime valores hexadecimais usando alocação dinâmica de memória.

`ft_put_void_pointer.c` — Imprime endereços de ponteiro no formato 0x....

`lower_or_upper.c` — Determina se a saída hexadecimal deve ser minúscula ou maiúscula.

`ft_printf.h` — Arquivo de cabeçalho contendo protótipos e #includes necessários.

`Makefile` — Regras de compilação e targets padrão.

### Recursos

42 School — enunciado do ft_printf

#### Documentação POSIX:

* write(2)

* stdarg(3)

#### Páginas de manual:

* man printf
  
*  man stdarg
  
* C standard library documentation

# English Version 

*This project has been created as part of the 42 curriculum by **pdiniz-l**.*

## ft_printf

### Description

The **ft_printf** project consists of implementing a simplified version of the standard C `printf` function.  
The goal is to reproduce its core behavior while respecting the constraints, coding standards, and low-level requirements of the **42 curriculum**.

This project focuses on understanding **variadic functions**, **format parsing**, **integer and string formatting**, and **output using the `write` system call**, while ensuring proper error handling and memory safety.

---

### Instructions

#### Compilation

The project is compiled using the provided `Makefile`.

Available targets:

```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and the library
make re     # recompile the project
```
This will generate the static library:
```bash
libftprintf.a
```
#### Usage

In `ft_printf.c` there is a comment with a main ready to test by using:
```bash
cc -Wall -Wextra -Werror ft_printf.c libftprintf.a
```
#### Supported Conversions

The ft_printf function supports the following format specifiers:

* `%c` — character

* `%s` — string

* `%d` / `%i` — signed decimal integer

* `%u` — unsigned decimal integer

* `%x` — hexadecimal (lowercase)

* `%X` — hexadecimal (uppercase)

* `%p` — pointer address

* `%%` — literal percent sign

##### Each helper function returns:

* The number of bytes written on success

* 1 in case of a write error

The main ft_printf function accumulates these values and returns the total number of bytes printed, matching the behavior of the standard printf.

#### Algorithm and Data Structure Choices
##### Format Parsing

The format string is processed character by character.

When a % is encountered, the following character is analyzed to determine the appropriate conversion.

A dispatcher function (chr_check) routes execution to the correct handler based on the specifier.

##### Variadic Arguments

The project uses va_list, va_start, va_arg, and va_end to retrieve arguments dynamically according to the detected format specifier.

##### Integer and Hexadecimal Conversion

Signed integers are printed using recursive or iterative digit extraction.

Unsigned values are used for `%u`, `%x`, `%X`, and `%p`.

For hexadecimal output, values are converted using base-16 logic.

Signed values are cast to unsigned types when required (e.g. long → unsigned long) to ensure correct representation.

##### Memory Management

* Dynamic memory allocation is used only when necessary (hexadecimal conversion).

* Every malloc call has a corresponding free.

* No memory leaks are introduced.

##### Error Propagation

Every helper function checks the return value of write.

In case of error, -1 is immediately propagated up to ft_printf.

This design ensures correctness, simplicity, and robustness while staying within project constraints.

##### File Structure

`ft_printf.c` - Main function that parses the format string, manages va_list, dispatches specifiers, and accumulates output size.

`chr_check.c` - Identifies the conversion specifier and calls the corresponding handler.

`digits.c` -  Computes the number of digits required for numerical conversions (used for hexadecimal output).

`ft_putchar.c` - Writes a single character using write.

`ft_putstr.c` - Writes a string, handling NULL values by printing (null).

`ft_putnbr.c` -  Prints signed integers.

`ft_put_unsigned_nbr.c` - Prints unsigned integers.

`ft_put_hex.c` - Converts and prints hexadecimal values using dynamic memory allocation.

`ft_put_void_pointer.c` - Prints pointer addresses in 0x... format.

`lower_or_upper.c` - Determines whether hexadecimal output should be lowercase or uppercase.

`ft_printf.h` - Header file containing prototypes and required includes.

`Makefile` - Compilation rules and standard targets.

### Resources

42 School — ft_printf subject

#### POSIX documentation:

* write(2)

* stdarg(3)

#### Manual pages:

* man printf

* man stdarg

* C standard library documentation
