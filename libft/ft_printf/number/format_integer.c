/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:59:54 by yuak              #+#    #+#             */
/*   Updated: 2025/08/09 16:00:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	print_integer(int integer, int *n);

int	format_integer(int integer)
{
	int	n;

	n = 0;
	print_integer(integer, &n);
	return (n);
}

static void	print_integer(int integer, int *n)
{
	char	*s;

	s = ft_itoa(integer);
	write(1, s, ft_strlen(s));
	(*n) += ft_strlen(s);
	free(s);
}
