/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:10:03 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/06 10:39:43 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chr_check(char a, va_list args)
{
	if (a == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (a == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (a == 'p')
		return (ft_put_void_pointer(va_arg(args, void *)));
	if (a == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (a == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (a == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	if (a == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), a));
	if (a == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), a));
	if (a == '%')
		return (ft_putchar('%'));
	return (0);
}
