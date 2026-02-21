/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:04:02 by yuak              #+#    #+#             */
/*   Updated: 2025/08/22 14:54:39 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			n += process(format, args);
		}
		else
		{
			write(1, format, 1);
			n++;
		}
		format++;
	}
	va_end(args);
	return (n);
}

static int	process(const char *format, va_list args)
{
	int		n;
	char	spec;

	n = 0;
	spec = *format;
	if (spec == 's')
		n = format_string(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		n = format_integer(va_arg(args, int));
	else if (spec == 'c')
		n = format_char(va_arg(args, int));
	else if (spec == 'p')
		n = format_pointer(va_arg(args, void *));
	else if (spec == 'u')
		n = format_unsigned(va_arg(args, unsigned));
	else if (spec == 'x' || spec == 'X')
		n = format_hex(va_arg(args, unsigned), spec);
	else if (spec == '%')
		n = format_percent();
	else
	{
		write(1, &spec, 1);
		n = 1;
	}
	return (n);
}
