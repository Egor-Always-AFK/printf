#include "ft_printf.h"

int ft_putnbr(int n)
{
	int len;
	char *message;

	len = 0;
	message = ft_itoa(n);
	len = ft_putstr(message);
	free (message);
	return (len);
}

int ft_putstr(char *c)
{
	int i;

	i = 0;
	if (c == NULL)
	{
		write(1, "NULL", 4);
		return (4);
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	print_lowcase_hex(unsigned int n)
{
	int len;

	len = 0;
	if (n >= 16)
	{
		print_lowcase_hex(n / 16);
		print_lowcase_hex(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd(n + '0', 1);
			len++;
		}
		else
		{
			ft_putchar_fd(n - '0' + 'a', 1);
			len++;
		}
	}
	return (len);
}

int	print_upcase_hex(unsigned int n)
{
	int len;

	len = 0;
	if (n >= 16)
	{
		print_lowcase_hex(n / 16);
		print_lowcase_hex(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd(n + '0', 1);
			len++;
		}
		else
		{
			ft_putchar_fd(n - '0' + 'A', 1);
			len++;
		}
	}
	return (len);
}