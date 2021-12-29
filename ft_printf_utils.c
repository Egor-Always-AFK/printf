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

int	print_percent(void)
{
	write(1, "%" , 1);
	return (1);
}

int	print_unsigned(unsigned int n)
{
	char	*message;

	message = ft_itoa(n);
	ft_putstr_fd(message, 1);
	return (ft_strlen(message));
}

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_ptr(unsigned int n)
{
	if (n >= 16)
	{
		print_ptr(n / 16);
		print_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n - '0' + 'A', 1);
	}
	return (ptr_len(n));
}

int ptr_len(unsigned int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (n);
}
