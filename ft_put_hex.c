/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:29:34 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/06 10:36:54 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*memorize_base16(unsigned int n, char *ref)
{	
	char	*temp;
	int		len;
	int		i;

	len = digits(n);
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		temp[i] = ref[n % 16];
		n /= 16;
		i--;
	}
	return (temp);
}

int	ft_put_hex(unsigned int n, int c)
{
	char	*ref;
	int		count;
	char	*temp;
	int		len;

	if (lower_or_upper(c) == 1)
		ref = "0123456789abcdef";
	else if (lower_or_upper(c) == 2)
		ref = "0123456789ABCDEF";
	else
		return (-1);
	if (n == 0)
		return (ft_putchar('0'));
	len = digits(n);
	temp = memorize_base16(n, ref);
	if (temp == NULL)
		return (-1);
	count = write(1, temp, len);
	free (temp);
	if (count < 0)
		return (-1);
	return (count);
}
/*#include <stdio.h>
int	main(void)
{
	ft_printf("%d\n", ft_put_hex(30, 'X'));

	printf("%d\n", ft_put_hex(30, 'X'));
}*/
