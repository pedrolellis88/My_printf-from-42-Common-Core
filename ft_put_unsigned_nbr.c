/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:18:16 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/04 13:19:39 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	v_ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_put_unsigned_nbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 0 && nb <= 9)
	{
		v_ft_putchar(nb + '0');
		count++;
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}
