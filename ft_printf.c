/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:11:25 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/06 10:42:04 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	validator_less_than_zero(int validator, va_list args)
{
	if (validator < 0)
	{
		va_end(args);
		return (-1);
	}
	return (validator);
}	

static	int	validate_s(const char *s)
{
	if (!s)
		return (-1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count_printed;
	int		validator;

	count_printed = 0;
	validate_s(s);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			validator = chr_check(*s, args);
			validator_less_than_zero(validator, args);
			count_printed += validator;
		}
		else
			count_printed += write(1, &*s, 1);
		s++;
	}
	va_end(args);
	return (count_printed);
}
/*#include <stdio.h>

 int	main()
 {
 	char	*str = "test";
 	unsigned int i = 10;

 	printf("Sistema : [%c] \n", 'c');
 	ft_printf("Meu : [%c] \n", 'c');
 	write(1,"\n", 1);
 	printf("Sistema : [%s] \n", "teste");
         ft_printf("Meu : [%s] \n", "teste");
         write(1,"\n", 1);
 	printf("Sistema : [%p] \n", &str);
         ft_printf("Meu : [%p] \n", &str);
         write(1,"\n", 1);
 	printf("Sistema : [%d] \n", 21);
         ft_printf("Meu : [%d] \n", 21);
         write(1,"\n", 1);
         printf("Sistema : [%i] \n", 1101);
         ft_printf("Meu : [%i] \n", 1101);
         write(1,"\n", 1);
 	printf("Sistema : [%u] \n", i);
         ft_printf("Meu : [%u] \n", i);
         write(1,"\n", 1);
 	printf("Sistema : [%x] \n", 30);
         ft_printf("Meu : [%x] \n", 30);
         write(1,"\n", 1);
 	printf("Sistema : [%X] \n", 30);
         ft_printf("Meu : [%X] \n", 30);
         write(1,"\n", 1);
 	printf("Sistema : [%%] \n");
         ft_printf("Meu : [%%] \n");
         write(1,"\n", 1);
}*/
