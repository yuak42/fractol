/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:01:36 by yuak              #+#    #+#             */
/*   Updated: 2025/08/12 13:20:13 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hex(unsigned int u, char spec, int *n);
static void	print_digit(unsigned int u, char spec);

int	format_hex(unsigned int u, char spec)
{
	int	n;

	n = 0;
	print_hex(u, spec, &n);
	return (n);
}

static void	print_hex(unsigned int u, char spec, int *n)
{
	if (u >= 16)
		print_hex(u / 16, spec, n);
	print_digit(u % 16, spec);
	(*n)++;
}

static void	print_digit(unsigned int u, char spec)
{
	char	c;

	if (u < 10)
		c = u % 16 + '0';
	else if (spec == 'x')
		c = u % 16 - 10 + 'a';
	else
		c = u % 16 - 10 + 'A';
	write(1, &c, 1);
}
