/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/12/18 18:26:10 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(va_list arguments, char arg)
{
	unsigned int number;

	number = 0;
	if (arg == 'i' || arg == 'd')
		number += ft_putnbr(va_arg(arguments, int));
	if (arg == 'c')
		number += ft_putchar(va_arg(arguments, int));
	if (arg == 's')
		number += ft_putstr(va_arg(arguments, char *));
	if (arg == '%')
		number += print_percent();
	if (arg == 'x')
		number += print_lowcase_hex(va_arg(arguments, unsigned int));
	if (arg == 'X')
		number += print_upcase_hex(va_arg(arguments, unsigned int));
	if (arg == 'p')
		number += print_ptr(va_arg(arguments, unsigned int));
	if (arg == 'u')
		number += print_unsigned(va_arg(arguments, unsigned int));
	return (number);
}

int	ft_printf(const char *s, ...)
{
	va_list	arguments;
	int				i;
	unsigned int	number_of_print;

	i = 0;
	number_of_print = 0;
	va_start(arguments, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			number_of_print += check_arg(arguments, s[i + 1]);
			i++;
		}
		i++;
	}
	va_end(arguments);
	return (number_of_print);
}
