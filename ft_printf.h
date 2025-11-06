/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:12:18 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/06 10:40:05 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	chr_check(char c, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_put_hex(unsigned int n, int c);
int	ft_put_void_pointer(void *p);
int	ft_putnbr(int nbr);
int	ft_put_unsigned_nbr(unsigned int nbr);
int	lower_or_upper(int c);
int	lower_or_upper(int c);
int	digits(unsigned int n);

#endif
